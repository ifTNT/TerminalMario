#include "scoreLifeExample.h"
#include <string>
using namespace std;

scoreLifeExample::scoreLifeExample(Game& _f):Point(_f){
       counter = 0;
       setContent(" ");
}
void scoreLifeExample::update(){
    api.setScore((api.getScore()+1)%10000);
    if(counter==30){
        counter=0;
        api.setLife((api.getLife()+1)%6);
    }
    counter++;
}