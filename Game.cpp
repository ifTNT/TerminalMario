#include "Game.h"
#include "FBuffer.h"
#include "Point.h"
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <typeinfo>

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
int Game::getRealX(GameChar t){
    return t.originX+t.x;
}
int Game::getRealY(GameChar t){
    return t.originY+t.y;
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
        for(vector<GameChar>::iterator i=objPool.begin(); i<objPool.end(); i++){
            i->ref->update();
        }
        //redraw
        for(vector<GameChar>::iterator i=objPool.begin(); i<objPool.end(); i++){
            int _x=offsetX(getRealX(*i));
            int _y=offsetY(getRealY(*i));
            if(i->ref->getContent()!="") fb->setPoint(_x,_y,i->ref->getContent());
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
bool Game::moveTo(void* req, int x, int y){
    if(!validPosition(x,y)) return false;
    //check collision
    struct GameChar* realReq;
    for(vector<GameChar>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if(i->ref == (Point*)req) realReq = &(*i);
        if(getRealX(*i)==x && getRealY(*i)==y) return false;
    }
    realReq->x = x;
    realReq->y = y;

    //req.setX(x);
    //req.setY(y);
    return true;
}
const type_info* Game::whosThere(int x, int y){
    for(vector<GameChar>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if(getRealX(*i)==x && getRealY(*i)==y) return i->type;
    }
    return &typeid(void);
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
bool Game::reachBottom(void* req){
    struct GameChar* realReq;
    for(vector<GameChar>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if(i->ref == (Point*)req) realReq = &(*i);
    }
    return (getRealY(*realReq)>=height-2);
}
//====End API====