#include "FBuffer.h"
#include <iostream>
#include <cstring>
using namespace std;

FBuffer::FBuffer(int w, int h){
    width = w;
    height = h;
    _fb = new char*[height];
    for(int i=0; i<height; i++){
        _fb[i] = new char[width+1];
    }
    clear();
    flush();
}
FBuffer::~FBuffer(){
    for(int i=0; i<height; i++){
        delete(_fb[i]);
    }
    delete(_fb);
}
void FBuffer::clear(){
    for(int i=0; i<height; i++){
        memset(_fb[i], '█', width);
    }
}

void FBuffer::flush(){
    //if (system("CLS")) system("clear");
    cout << string( 100, '\n' );
    for(int i=0; i<height; i++){
        cout << _fb[i] << endl;
    }
}

void FBuffer::setPoint(int x, int y, char content){
    _fb[y][x] = content;
}