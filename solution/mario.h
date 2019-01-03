#include "../Point.h"

class Mario:public Point{
    public:
        Mario(Game&);
        void update();
    private:
       float px,py,vx,vy,g;
};