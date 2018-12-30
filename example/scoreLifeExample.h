#include "../Point.h"

class scoreLifeExample:public Point{
    public:
        scoreLifeExample(Game&);
        virtual void update();
    private:
        int counter;
};