#ifndef POINT_H
#define POINT_H

#include <Game.h>

class Point{
    public:
        Point(int,int,Game&);
        ~Point();
        int x;
        int y;
        int getX();
        int getY();
        char getContent();
        void update();
    private:
        int x;
        int y;
        char content;
        void setX(int);
        void setY(int);
};

#endif