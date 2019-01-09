#include<iostream> 
#include "Monster.h" 
#include "Mario.h" 
#include <time.h>
#include <stdlib.h>
using namespace std; 
Monster::Monster(Game&_f) :Point(_f) { 
    srand(time(NULL)); 
    mx = 0; 
    my = 0; 
    setContent(L'&'); 
    flag = rand() % 2;
    value=0;
} 
void Monster::update() { 
    if(value==0){
        value = (rand()%9)+1;
        setContent(L'0'+value);
    }
    if (!api.reachBottom(this)) { 
        my -= 0.35; 
        api.moveTo(this, mx, my); 
    } 

    if (api.whosThere(this, mx, my + 1) == &typeid(Mario)) 
    {
        api.setScore(api.getScore()+value); 
        api.Delete(this);
        api.create<Monster>(rand()%api.getWidth(), rand()%(api.getHeight()/2));
    } 

    if (!api.moveTo(this, mx - 1, my)) 
    { 
        flag = 1; 
        mx += 1; 
    } 
    else if (!api.moveTo(this, mx + 1, my)) 
    { 
        flag = 0; 
        mx -= 1; 
    } 

    if (flag == 1) 
    { 
        mx += 0.35; 
        api.moveTo(this, mx, my); 
    } 
    else if (flag == 0) 
    { 
        mx -= 0.35; 
        api.moveTo(this, mx, my); 
    } 

}