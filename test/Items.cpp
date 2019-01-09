#include<iostream> 
#include "Items.h" 
#include "Mario.h"

using namespace std; 
Items::Items(Game&_f):Point(_f){ 
    setContent(L'+'); 
} 
void Items::update(){ 
    if(api.whosThere(this,0,1)==&typeid(Mario)){ 
        api.setLife(api.getLife()+1); 
        api.Delete(this); 
    } 
}