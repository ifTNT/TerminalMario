#ifndef BRICK_H
#define BRICK_H
#include "../Point.h"
class Brick:public Point{
    public:
        Brick(Game&);
        virtual void update();
    private:
        bool used=false;
};
#endif