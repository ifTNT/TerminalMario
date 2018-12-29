#ifndef POINT_H
#define POINT_H

#include "Game.h"
#include <string>
using namespace std;

class Game;
class Point{
    public:
        Point(int,int,Game&);
        ~Point();
        virtual int getX(){return originX+x;};
        virtual int getY(){return originY+y;};
        virtual Game& getAPI(){return father;};
        virtual string getContent(){return content;};
        virtual void update(){;};
        virtual void setX(int _x){x=_x;};
        virtual void setY(int _y){x=_y;};
        virtual void setContent(string newC){content.assign(newC);};
    private:
        int originX;
        int originY;
        int x;
        int y;
        string content;
        Game& father;
};

#endif