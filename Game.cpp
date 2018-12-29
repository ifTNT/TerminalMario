#include "Game.h"
#include "FBuffer.h"
#include "Point.h"
#include <iostream>
#include <stdio.h>
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
    life = 1;
    width = 80;
    height = 20;
    fb = new FBuffer(width,height);
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

void Game::start(){
    thread th(readUserKey);
    /*int counter=0;
    int px=10, py=10;
    float vx=0, vy=0;
    const float g = 0.8;*/
    while(endFlag==0){
        this_thread::sleep_for(chrono::milliseconds(33));
        //======begin Tick======
        cout << "Tick\n";
        fb->clear();
        fb->drawLine(0,19,79,19, "█");
        //refresh
        for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            cout << *i;
            (*i)->update();
        }
        //redraw
        for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            int _x=(*i)->getX();
            int _y=(*i)->getY();
            fb->setPoint(_x,_y,(*i)->getContent());
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
