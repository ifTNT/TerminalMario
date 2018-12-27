#ifndef FB_H
#define FB_H

#include <string>
using namespace std;
class FBuffer{
    public:
        FBuffer(int,int);
        ~FBuffer();
        int getWidth();
        int getHeight();
        void setPoint(int, int, char);
        void getPoint(int, int, char);
        void clearPoint(int, int);
        void drawRect(int, int, int, int, char);
        void drawLine(int, int, int, int, char);
        void flush();
        void clear();
    private:
        int width;
        int height;
        string** _fb;
};

#endif