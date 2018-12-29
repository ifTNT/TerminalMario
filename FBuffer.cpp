#include "FBuffer.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

FBuffer::FBuffer(int w, int h){
    width = w;
    height = h;
    _fb = new string**[height];
    for(int i=0; i<height; i++){
        _fb[i] = new string*[width];
        for(int j=0; j<width; j++){
            _fb[i][j] = new string();
        }
    }
    clear();
    flush();
}
FBuffer::~FBuffer(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            delete(_fb[i][j]);
        }
        delete(_fb[i]);
    }
    delete(_fb);
}
bool FBuffer::_inBoundary(int x, int y){
    if(x<0 || x>=width) return false;
    if(y<0 || y>=height) return false;
    return true;
}
void FBuffer::clear(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            *(_fb[i][j]) = " ";
        }
    }
}

void FBuffer::flush(){
    //if (system("CLS")) system("clear");
    cout << string( 100, '\n' );
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout << *(_fb[i][j]);
        }
        cout << endl;
    }
}

void FBuffer::setPoint(int x, int y, char content){
    if(!_inBoundary(x,y)) return;
    _fb[y][x]->assign(1, content);
}
void FBuffer::setPoint(int x, int y, string content){
    if(!_inBoundary(x,y)) return;
    _fb[y][x]->assign(content);
}
void FBuffer::drawLine(int x0, int y0, int x1, int y1, string content){
    if(!_inBoundary(x0,y0)) return;
    if(!_inBoundary(x1,y1)) return;
    if(y1!=y0){
        for(int i=min(y0,y1); i<=max(y0,y1); i++){
           _fb[i][x0+(int)((float)(x1-x0)/(float)(y1-y0)*i)]->assign(content);
        }
    }
    if(x1!=x0){
        for(int i=min(x0,x1); i<=max(x0,x1); i++){
           _fb[y0+(int)((float)(y1-y0)/(float)(x1-x0)*i)][i]->assign(content);
        }
    }
}