#include "../Game.h"
#include "Monster.h"
#include "Mario.h"
#include "Brick.h"
#include <time.h>
#include <stdlib.h>
#include <random>
#include <iostream>
using namespace std;

int main(){
    Game TerminalMario;
    /*
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> x_rand(0, TerminalMario.getWidth());
    uniform_int_distribution<int> y_rand(10, TerminalMario.getHeight()-15);
    */

    //srand(time(NULL));
    for(int i=0; i<5; i++){
        int x = rand()%TerminalMario.getWidth();
        int y = rand()%(TerminalMario.getHeight()-15)+10;
        TerminalMario.create<Monster>(x,y);
    }
    for(int i=0; i<3; i++){
        int x = rand()%TerminalMario.getWidth();
        int y = rand()%(TerminalMario.getHeight()-15)+10;
        //int x = x_rand(mt);
        //int y = y_rand(mt);
        TerminalMario.create<Brick>(x,y);
    }
    /*TerminalMario.create<Monster>(20,0);
    TerminalMario.create<Monster>(20,5);
    TerminalMario.create<Monster>(30,20);
    TerminalMario.create<Monster>(40,0);*/
    TerminalMario.create<Mario>(10,10);
    //TerminalMario.create<Brick>(10,10);
    
    TerminalMario.start();
    return 0;
}