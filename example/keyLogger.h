#include "../Point.h"

//Inherit Point
class keyLogger: public Point{
    public:
        //Fixed form
        keyLogger(Game&);

        //Override update
        virtual void update();
};
