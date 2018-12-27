#include "FBuffer.h"
#include <iostream>
#include <string>
using namespace std;

FBuffer::FBuffer(int w, int h){
    width = w;
    height = h;
    _fb = new string*[height];
    for(int i=0; i<height; i++){
        _fb[i] = new string[width+1];
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
        for(int j=0; j<width; j++){
            _fb[i][j] = "█";
        }
    }
}

void FBuffer::flush(){
    //if (system("CLS")) system("clear");
    cout << string( 100, '\n' );
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout << _fb[i][j];
        }
        cout << endl;
    }
}

void FBuffer::setPoint(int x, int y, char content){
    _fb[y][x] = content;
}