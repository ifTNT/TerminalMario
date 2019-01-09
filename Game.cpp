#include "Game.h"
#include "FBuffer.h"
#include "Point.h"
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <typeinfo>
#include "EndChar.h"
#include <cstring>

#ifdef __linux__
    #include <curses.h>
#elif _WIN32
    #include <ncursesw/curses.h>
#endif

/*
#ifdef __linux__ 
    #include "linuxGetchPatch.h"
#elif _WIN32
    #include <conio.h>
#else
#endif
*/
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
    _frameCnt = 0;
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
    return height-1-y+2;
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
    
    while(true){
        _frameCnt++;
        this_thread::sleep_for(chrono::milliseconds(33));

        //Copy new objPool
        objPool.assign(_objPool.begin(),_objPool.end());
        //======begin Tick======
        clear();
        if(endFlag!=0){
            string scoreStr = "SCORE";
            for(int i=0; i<scoreStr.length(); i++){
                fb->setPoint((width-scoreStr.length())/2+i+1, 6, scoreStr[i]);
            }
            int _score = score;
            for(int i=0; i<4; i++){
                fb->drawNumber(width/2-(i-1)*8+2, 8, _score%10);
                _score /= 10;
            }
            /*for(int i=0; i<10; i++){
                fb->drawNumber(2+8*i,8,i);
            }*/
        }
        //draw the scene
        fb->drawLine(0,height+2,width+1,height+2, L'█');
        fb->drawLine(0,0,width+1,0, L'█');
        fb->drawLine(0,0,0,height+2, L'█');
        fb->drawLine(width+1,0,width+1,height+2, L'█');
        //refresh
        for(vector<GameChar*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            (*i)->ref->update();
        }
        //redraw
        for(vector<GameChar*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            if(!validPosition(getRealX(**i), getRealY(**i)));
            int _x=offsetX(getRealX(**i));
            int _y=offsetY(getRealY(**i));
            if((*i)->ref->getContent()!=L'\0') fb->setPoint(_x,_y,(*i)->ref->getContent());
        }
        if(endFlag==0){
            //redraw life
            for(int i=1; i<=getLife(); i++){
                fb->setPoint(offsetX(i-1), 1, L'웃');
            }
            //redraw score
            int _score = score;
            for(int i=0; i<4; i++){
                fb->setPoint(offsetX(width-1-i), 1, '0'+_score%10);
                _score /= 10;
            }

            //redraw rest time
            int _second = (3000-_frameCnt)/30;
            for(int i=0; i<3; i++){
                fb->setPoint(offsetX(width/2-i), 1, '0'+_second%10);
                _second /= 10;
            }
            if(_frameCnt>=3000){
                endGame();
            }
        }
        if(userKey!=(char)0) userKey=0;
        fb->flush();
#ifdef DEBUG
        cout << "Frame " << _frameCnt << endl;
#endif
        //======End Tick========
        const wchar_t* gameover = L"GAME OVER";
        if(endFlag>=1 && endFlag<=wcslen(gameover)){
            if(endFlag==1) _objPool.clear();
            create<EndChar>(10+endFlag*4,5);
            _objPool[endFlag-1]->ref->setContent(gameover[endFlag-1]);
            endFlag++;
        }
    }
    cout << "Press any key to end the game." << endl;
    th.join();
}

struct GameChar* Game::getRealReq(Point* req){
    struct GameChar* realReq;
    for(vector<GameChar*>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if((*i)->ref == req) realReq = (*i);
    }
    return realReq;
}

//====Begin API====
bool Game::moveTo(void* req, int x, int y){
    //check collision
    struct GameChar* realReq=getRealReq((Point*)req);
    for(vector<GameChar*>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if((*i)!=realReq &&
           getRealX(**i)==realReq->originX+x &&
           getRealY(**i)==realReq->originY+y) return false;
    }
    if(!validPosition(realReq->originX+x,realReq->originY+y)) return false;
    realReq->x = x;
    realReq->y = y;

    //req.setX(x);
    //req.setY(y);
    return true;
}
const type_info* Game::whosThere(void * cola,int x, int y){
    struct GameChar* realReq=getRealReq((Point*)cola);
    for(vector<GameChar*>::iterator i=objPool.begin(); i<objPool.end(); i++){
        if(getRealX(**i)==realReq->originX+x && getRealY(**i)==realReq->originY+y) return (*i)->type;
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
    struct GameChar* realReq=getRealReq((Point*)req);
    return (getRealY(*realReq)<=0);
}
int Game::getWidth(){
    return width;
}
int Game::getHeight(){
    return height;
}
int Game::getFrameCount(){
    return _frameCnt;
}
int Game::getAbsX(void* req){
    struct GameChar* realReq=getRealReq((Point*)req);
    return getRealX(*realReq);
}
int Game::getAbsY(void* req){
    struct GameChar* realReq=getRealReq((Point*)req);
    return getRealY(*realReq);
}
void Game::Delete(void* req){
    for(vector<GameChar*>::iterator i=_objPool.begin(); i<_objPool.end();){
        if((*i)->ref == ((Point*)req)){
            //delete((*i)->ref);
            i = _objPool.erase(i);
            break;
        }else{
            i++;
        }
    }
}
//====End API====