#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

#ifdef __linux__ 
    #include "linuxGetchPatch.h"
#elif _WIN32
    #include <conio.h>
#else
#endif

using namespace std;

char Game::userKey;
condition_variable Game::cv;

Game::Game(){
    userKey = '\0';
    endFlag = 0;
}

void Game::readUserKey(){
    userKey = getch();
    cv.notify_one();
}

void Game::start(){
    while(endFlag==0){
        thread th(readUserKey);

        mutex mtx;
        unique_lock<mutex> lck(mtx);
        while (cv.wait_for(lck, chrono::milliseconds(1000)) == cv_status::timeout){
            cout << "Tick\n";
        }
        cout << "key " << (unsigned int)userKey << " detected\n";

        th.join();
    }
}