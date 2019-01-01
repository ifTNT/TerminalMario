#include "barrier.h"

barrier::barrier(Game& _f):Point(_f){
    offsetY=0;
    setContent("█");
}

void barrier::update(){
    if(!api.reachBottom(this)){
        offsetY++;
        api.moveTo(this, 0, offsetY);
    }
}