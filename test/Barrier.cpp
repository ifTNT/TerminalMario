#include "Barrier.h"

Barrier::Barrier(Game& _f):Point(_f){
    offsetY=0;
    setContent(L'█');
}

void Barrier::update(){
    if(!api.reachBottom(this)){
        offsetY--;
        api.moveTo(this, 0, offsetY);
    }
}