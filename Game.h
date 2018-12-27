#ifndef GAME_H
#define GAME_H

#include <Point.h>
#include <Vector>
#include <condition_variable>

class Game{
    public:
        Game();
        ~Game();
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
        Vector<Point*> objPool;
        int score;
        int life;
        char userKey;
        int endFlag;
        condition_variable cv;
        void readUserKey();

};

#endif