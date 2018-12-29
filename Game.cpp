#include "Game.h"
#include "FBuffer.h"
#include "Point.h"
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#ifdef __linux__ 
    #include "linuxGetchPatch.h"
#elif _WIN32
    #include <conio.h>
#else
#endif

using namespace std;

char Game::userKey;
int Game::endFlag;

Game::Game() {
    userKey = '\0';
    endFlag = 0;
    score = 0;
    life = 5;
    width = 80;
    height = 20;
    fb = new FBuffer(width+2,height+3);
}

Game::~Game(){
    delete(fb);
}

void Game::readUserKey(){
    while(endFlag==0){
        userKey = getch();
    }
}

bool Game::validPosition(int x, int y){
    if(x<0 || x>=width) return false;
    if(y<0 || y>=height) return false;
    return true;
}

int Game::offsetX(int x){
    return x+1;
}
int Game::offsetY(int y){
    return y+2;
}

void Game::start(){
    //new thread to record user key input
    thread th(readUserKey);
    
    while(endFlag==0){
        this_thread::sleep_for(chrono::milliseconds(33));
        //======begin Tick======
        fb->clear();
        //draw the scene
        fb->drawLine(0,height+1,width+1,height+1, "█");
        fb->drawLine(0,0,width+1,0, "█");
        fb->drawLine(0,0,0,height+1, "█");
        fb->drawLine(width+1,0,width+1,height+1, "█");
        //refresh
        for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            (*i)->update();
        }
        //redraw
        for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            int _x=offsetX((*i)->getX());
            int _y=offsetY((*i)->getY());
            if((*i)->getContent()!="") fb->setPoint(_x,_y,(*i)->getContent());
        }

        //redraw life
        for(int i=1; i<=getLife(); i++){
            fb->setPoint(offsetX(i-1), 1, "*");
        }
        //redraw score
        int _score = score;
        for(int i=0; i<4; i++){
            fb->setPoint(offsetX(width-1-i), 1, '0'+_score%10);
            _score /= 10;
        }

        if(userKey!=(char)0) userKey=0;
        fb->flush();
        //======End Tick========
    }
    cout << "Press any key to end the game." << endl;
    th.join();
}

//====Begin API====
bool Game::moveTo(Point& req, int x, int y){
    if(!validPosition(x,y)) return false;
    //check collision
    for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if((*i)->getX()==x || (*i)->getY()==y) return false;
    }
    req.setX(x);
    req.setY(y);
    return true;
}
char Game::getUserKey(){
    return userKey;
}
void Game::setScore(int newScore){
    if(newScore<0 || newScore>9999) return;
    score = newScore;
}
int Game::getScore(){
    return score;
}
void Game::setLife(int newLife){
    if(newLife<0 || newLife>5) return;
    life = newLife;
}
int Game::getLife(){
    return life;
}
void Game::endGame(){
    endFlag = true;
}
//====End API====