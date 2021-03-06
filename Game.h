#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include "FBuffer.h"
#include <vector>
#include <typeinfo>
//#include <condition_variable>
using namespace std;

class Point;

struct GameChar{
    Point* ref;
    const type_info* type;
    int originX;
    int originY;
    int x;
    int y;
};
class Game{
    public:
        Game();
        ~Game();
        bool moveTo(void*,int,int);
        const type_info* whosThere(void*,int,int);
        template <class T> bool create(int, int);
        void setScore(int);
        int getScore();
        void setLife(int);
        int getLife();
        void endGame();
        static char getUserKey();
        bool reachBottom(void*);
        void start();
        int getWidth();
        int getHeight();
        int getFrameCount();
        int getAbsX(void*);
        int getAbsY(void*);
        void Delete(void*);
    private:
        vector<GameChar*> objPool;
        vector<GameChar*> _objPool;
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
        int getRealX(GameChar);
        int getRealY(GameChar);
        struct GameChar* getRealReq(Point*);
        FBuffer* fb;
        unsigned long long int _frameCnt;

};

//Must place here to avoid linking error
template<class T> bool Game::create(int x, int y){
    //if(!validPosition(x,y)) return false;
    T* newObj = new T(*this);
    struct GameChar* newGameChar= new GameChar{
        (Point*)newObj,
        &typeid(T)
    };
    newGameChar->originX = x;
    newGameChar->originY = y;
    newGameChar->x = 0;
    newGameChar->y = 0;
    _objPool.push_back(newGameChar);
    return true;
}

#endif