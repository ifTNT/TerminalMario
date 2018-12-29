#include "../Game.h"
#include "keyLogger.h"
#include "scoreLifeExample.h"
using namespace std;

int main(){
    Game newGame;

    //Create the keyLogger object in position (10,10)
    newGame.create<keyLogger>(10,10);
    
    //A dummy object in position (0,0)
    newGame.create<scoreLifeExample>(0,0);

    //Start the game(block until game end)
    newGame.start();
    return 0;
}