#include "keyLogger.h"
#include <string>
using namespace std;

//Must call the constructor of Point.
keyLogger::keyLogger(int x, int y, Game& _f):Point(x,y,_f){}

void keyLogger::update(){
    string userKey = string(1, api.getUserKey());
    if(api.getUserKey()==0) userKey.assign(" ");
    setContent(userKey);
}