#include "../Game.h"
#include "keyLogger.h"
#include "scoreLifeExample.h"
#include "barrier.h"
using namespace std;

int main(){
    Game newGame;

    //Create the keyLogger object in position (10,10)
    newGame.create<keyLogger>(10,10);
    
    //A dummy object in position (0,0)
    newGame.create<scoreLifeExample>(10000,10000);

    //Fallen barrier in position(40,10)
    newGame.create<barrier>(40,10);

    //Start the game(block until game end)
    newGame.start();
    return 0;
}