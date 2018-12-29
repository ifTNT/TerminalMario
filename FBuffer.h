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
        void setPoint(int, int, string);
        void getPoint(int, int);
        void clearPoint(int, int);
        void drawRect(int, int, int, int, string);
        void drawLine(int, int, int, int, string);
        void flush();
        void clear();
    private:
        int width;
        int height;
        string*** _fb;
        bool _inBoundary(int, int);
};

#endif