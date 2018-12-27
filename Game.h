#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include <vector>
#include <condition_variable>
using namespace std;

class Game{
    public:
        Game();
        bool moveTo(int,int);
        bool create(int, int, int);
        void setScore(int);
        int getScore();
        void setLife(int);
        int getLife();
        void endGame();
        char getUserKey();
        void start();
    private:
        vector<Point*> objPool;
        int score;
        int life;
        static char userKey;
        int endFlag;
        static condition_variable cv;
        static void readUserKey();

};

#endif