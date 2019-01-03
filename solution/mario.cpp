#include "mario.h"
#include <typeinfo>

Mario::Mario(Game& _f):Point(_f){
    px=0;
    py=0;
    vx=0;
    vy=0;
    g=0.1;
    setContent("♀");
}

void Mario::update(){
    vx=0;
    if(api.reachBottom(this)){
        vy=0;
    }else{
        vy-=g;
    }
    switch(api.getUserKey()){
        case '\0':

        break;
        case 'w':
            vy+=10;
        break;
        case 'a':
            vx=-1;
        break;
        case 'd':
            vx=1;
        break;
    }

    px+=vx;
    for(int i=py; i<=py+vy; i+=(vy>0 ? 1:-1)){
        if(api.whosThere((int)px, (int)i)!=&typeid(NULL)) break;
    }

    api.moveTo(this, (int)px, (int)py);
}