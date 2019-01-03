#include "../Game.h"
#include "mario.h"

int main(){
    Game TerminalMario;

    TerminalMario.create<Mario>(0,10);
    TerminalMario.start();
    return 0;
}