#ifndef MONSTER_H
#define MONSTER_H
#include "../Point.h"
class Monster :public Point {
    public:
        Monster(Game&_f);
        void update();
    private:
        double mx;
        double my;
        int flag = 0;
        int value = 0;
};
#endif