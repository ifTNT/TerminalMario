#include "FBuffer.h"
#include <iostream>
#include <string>
#include <cmath>
#include <locale.h>
#ifdef __linux__
    #include <curses.h>
#elif _WIN32
    #include <ncursesw/curses.h>
#endif
using namespace std;

FBuffer::FBuffer(int w, int h){
    width = w;
    height = h;

    setlocale(LC_ALL,"");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    clear();
    flush();
}
FBuffer::~FBuffer(){
    endwin();
}
bool FBuffer::_inBoundary(int x, int y){
    if(x<0 || x>=width) return false;
    if(y<0 || y>=height) return false;
    return true;
}

void FBuffer::flush(){
    refresh();
}

void FBuffer::setPoint(int x, int y, wchar_t content){
    if(!_inBoundary(x,y)) return;
    wstring buf(1,content);
    mvaddwstr(y,x,buf.c_str());
}
void FBuffer::drawLine(int x0, int y0, int x1, int y1, wchar_t content){
    if(!_inBoundary(x0,y0)) return;
    if(!_inBoundary(x1,y1)) return;
    wstring buf(1, content);
    if(y1!=y0){
        for(int i=min(y0,y1); i<=max(y0,y1); i++){
           mvaddwstr(i, x0+(int)((float)(x1-x0)/(float)(y1-y0)*i), buf.c_str());
        }
    }
    if(x1!=x0){
        for(int i=min(x0,x1); i<=max(x0,x1); i++){
           mvaddwstr(y0+(int)((float)(y1-y0)/(float)(x1-x0)*i),i, buf.c_str());
        }
    }
}
void FBuffer::drawNumber(int x, int y, int content){
    if(content<0 || content>9) return;
    for(int i=0; i<7; i++){
        for(int j=0; j<5; j++){
            setPoint(x+j, y+i,numFont[content][i][j]);
        }
    }
    return;
}