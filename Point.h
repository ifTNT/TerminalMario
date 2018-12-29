#ifndef POINT_H
#define POINT_H

#include "Game.h"
#include <string>
using namespace std;

class Game;
class Point{
    public:
        Point(int,int,Game&);
        ~Point(){};
        virtual int getX(){return originX+x;};
        virtual int getY(){return originY+y;};
        virtual string getContent(){return content;};
        virtual void setContent(string newC){content.assign(newC);};
        virtual void update(){;};
        virtual void setX(int _x){x=_x;};
        virtual void setY(int _y){x=_y;};
    private:
        int originX;
        int originY;
    protected:
        int x;
        int y;
        string content;
        Game& api;
};

#endif