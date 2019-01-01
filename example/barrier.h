#include "../Point.h"

class barrier:public Point{
    public:
        barrier(Game&);
        virtual void update();
    private:
        int offsetY;
};