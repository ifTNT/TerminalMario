#include<iostream> 
#include "Brick.h" 
#include "Mario.h"
#include "Items.h"
#include <time.h>
#include <stdlib.h>
using namespace std; 
Brick::Brick(Game&_f):Point(_f){ 
    setContent(L'█');
    srand(time(NULL)); 
    used = false;
} 
void Brick::update(){ 
    if(!used && api.whosThere(this,0, -1)==&typeid(Mario)){ 
        api.create<Items>(api.getAbsX(this),api.getAbsY(this)+1); 
        used = true;
        //api.Delete(this); 
    } 
    if(used && api.whosThere(this,0,1)==&typeid(Mario)){ 
        api.create<Brick>(rand()%api.getWidth(),(rand()%(api.getHeight()-15)+10)); 
        //api.setScore(api.getScore()+1); 
        api.Delete(this); 
    } 
}