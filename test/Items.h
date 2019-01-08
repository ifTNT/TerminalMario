#ifndef ITEMS_H
#define ITEMS_H
#include"../Point.h"
class Items:public Point{
    public:
        Items(Game&);
        virtual void update();
    private:
        int offsetY;
        int offsetX;
};
#endif