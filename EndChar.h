#ifndef ENDCHAR_H
#define ENDCHAR_H
#include "Point.h"
class EndChar :public Point {
    public:
        EndChar(Game&_f);
        void update();
    private:
        double mx;
        double my;
        int flag = 0;
};
#endif