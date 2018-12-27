#include "Game.h"
#include "FBuffer.h"
#include <iostream>
#include <stdio.h>
#include <thread>
#include <chrono>

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
    fb = new FBuffer(80,20);
}

Game::~Game(){
    delete(fb);
}

void Game::readUserKey(){
    while(endFlag==0){
        userKey = getch();
    }
}

char Game::getUserKey(){
    return userKey;
}

void Game::start(){
    thread th(readUserKey);
    while(endFlag==0){
        int counter;
        this_thread::sleep_for(chrono::milliseconds(100));
        //======begin Tick======
        //cout << "Tick\n";
        fb->clear();
        fb->setPoint(1,1,(char)('0'+(counter++)%10));
        for(vector<Point*>::iterator i=objPool.begin(); i<objPool.end(); i++){
            //(*i)->update();
        }
        if(userKey!=(char)0) userKey=0;
        fb->flush();
        //======End Tick========
    }
    cout << "Press any key to end the game." << endl;
    th.join();
}