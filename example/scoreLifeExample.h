#include "../Point.h"

class scoreLifeExample:public Point{
    public:
        scoreLifeExample(int,int,Game&);
        virtual void update();
    private:
        int counter;
};