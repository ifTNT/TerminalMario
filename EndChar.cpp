#include<iostream> 
#include "EndChar.h" 
using namespace std; 
EndChar::EndChar(Game&_f) :Point(_f) { 
    mx = 0; 
    my = 0; 
    flag = 1;
} 
void EndChar::update() { 
    if (!api.reachBottom(this)) { 
        my -= 0.35; 
        api.moveTo(this, mx, my); 
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