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
        void setPoint(int, int, wchar_t);
        //void setPoint(int, int, wstring);
        void getPoint(int, int);
        void clearPoint(int, int);
        void drawRect(int, int, int, int, wchar_t);
        void drawLine(int, int, int, int, wchar_t);
        void drawNumber(int,int,int);
        void flush();
        //void clear();
    private:
        int width;
        int height;
        wstring** _fb;
        bool _inBoundary(int, int);
        const wchar_t numFont[10][7][5]={
            {
                {L'█',L'█',L'█',L'█',L'█'},
                {L'█',L' ',L' ',L' ',L'█'},
                {L'█',L' ',L' ',L' ',L'█'},
                {L'█',L' ',L' ',L' ',L'█'},
                {L'█',L' ',L' ',L' ',L'█'},
                {L'█',L' ',L' ',L' ',L'█'},
                {L'█',L'█',L'█',L'█',L'█'}
            },{
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L'█', L'█', L'█', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'}
            },{
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'}
            },{
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L' ', L' ', L' ', L' '},
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'}
            },{
                {L'█', L'█', L'█', L'█', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L' ', L' ', L' ', L'█'},
                {L'█', L'█', L'█', L'█', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'},
                {L' ', L' ', L' ', L' ', L'█'}
            }
        };
};

#endif