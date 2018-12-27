#include "Game.h"
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

Game::Game(){
    userKey = '\0';
    endFlag = 0;
}

void Game::readUserKey(){
    while(endFlag==0){
        userKey = getch();
    }
}

char Game::getUserKey(){
    char buf = userKey;
    if(buf!=(char)0){
        userKey = (char)0;
        return buf;
    }else{
        return 0;
    }
}

void Game::start(){
    thread th(readUserKey);
    while(endFlag==0){
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Tick\n";
        char key = getUserKey();
        if(key!=(char)0){
            cout << "key " << key << " detected\n";
            endFlag=1;
            break;
        }
    }
    cout << "Press any key to end the game." << endl;
    th.join();
}