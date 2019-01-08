#include "../Point.h"

class Barrier:public Point{
    public:
        Barrier(Game&);
        virtual void update();
    private:
        int offsetY;
        int used=0;
};