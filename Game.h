#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include "FBuffer.h"
#include <vector>
//#include <condition_variable>
using namespace std;

class Point;
class Game{
    public:
        Game();
        ~Game();
        bool moveTo(Point&,int,int);
        template <class T> bool create(int, int);
        void setScore(int);
        int getScore();
        void setLife(int);
        int getLife();
        void endGame();
        static char getUserKey();
        void start();
    private:
        vector<Point*> objPool;
        int score;
        int life;
        int width;
        int height;
        static char userKey;
        static int endFlag;
        //static condition_variable cv;
        static void readUserKey();
        bool validPosition(int,int);
        int offsetX(int);
        int offsetY(int);
        FBuffer* fb;

};

//Must place here to avoid linking error
template<class T> bool Game::create(int x, int y){
    if(!validPosition(x,y)) return false;
    T* newObj = new T(x, y, *this);
    objPool.push_back((Point*)newObj);
    return true;
}

#endif