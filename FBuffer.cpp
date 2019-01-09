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
    /*_fb = new wstring*[height];
    for(int i=0; i<height; i++){
        _fb[i] = new wstring[width];
        for(int j=0; j<width; j++){
            _fb[i][j] = new wstring(L" ");
        }
    */
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
    /*for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            delete(_fb[i][j]);
        }
        delete(_fb[i]);
    }
    delete(_fb);*/
    endwin();
}
bool FBuffer::_inBoundary(int x, int y){
    if(x<0 || x>=width) return false;
    if(y<0 || y>=height) return false;
    return true;
}
/*void FBuffer::clear(){
    /*wstring space(L" ");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            _fb[i][j] = space;
        }
    }*
}*/

void FBuffer::flush(){
    //if (system("CLS")) system("clear");
    //cout << string( 100, '\n' );
    /*for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            mvaddwstr(i,j,(_fb[i][j]).c_str());
        }
    }*/
    refresh();
}

void FBuffer::setPoint(int x, int y, wchar_t content){
    if(!_inBoundary(x,y)) return;
    wstring buf(1,content);
    //printw("ABC");
    mvaddwstr(y,x,buf.c_str());
    //_fb[y][x]->assign(1, content);
}
/*void FBuffer::setPoint(int x, int y, string content){
    if(!_inBoundary(x,y)) return;
    _fb[y][x]->assign(content);
}*/
void FBuffer::drawLine(int x0, int y0, int x1, int y1, wchar_t content){
    if(!_inBoundary(x0,y0)) return;
    if(!_inBoundary(x1,y1)) return;
    wstring buf(1, content);
    if(y1!=y0){
        for(int i=min(y0,y1); i<=max(y0,y1); i++){
           mvaddwstr(i, x0+(int)((float)(x1-x0)/(float)(y1-y0)*i), buf.c_str());
           //_fb[i][x0+(int)((float)(x1-x0)/(float)(y1-y0)*i)]->assign(content);
        }
    }
    if(x1!=x0){
        for(int i=min(x0,x1); i<=max(x0,x1); i++){
           mvaddwstr(y0+(int)((float)(y1-y0)/(float)(x1-x0)*i),i, buf.c_str());
           //_fb[y0+(int)((float)(y1-y0)/(float)(x1-x0)*i)][i]->assign(content);
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