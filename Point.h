#ifndef POINT_H
#define POINT_H

#include "Game.h"
#include <string>
using namespace std;

class Game;
class Point{
    public:
        Point(Game&);
        ~Point(){};
        //virtual int getX(){return originX+x;};
        //virtual int getY(){return originY+y;};
        virtual wchar_t getContent(){return content;};
        virtual void setContent(wchar_t newC){content = newC;};
        virtual void update(){;};
        //virtual void setX(int _x){x=_x;};
        //virtual void setY(int _y){x=_y;};
    private:
        //int originX;
        //int originY;
    protected:
        //int x;
        //int y;
        wchar_t content;
        Game& api;
};

#endif