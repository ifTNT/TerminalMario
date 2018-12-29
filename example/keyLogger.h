#include "../Point.h"

//Inherit Point
class keyLogger: public Point{
    public:
        //Fixed form
        keyLogger(int,int,Game&);

        //Override update
        virtual void update();
};
