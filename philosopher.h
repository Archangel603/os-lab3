#ifndef LAB3_PHILOSOPHER_H
#define LAB3_PHILOSOPHER_H

#include <cstdio>
#include "waiter.h"

class Philosopher {

public:
    Philosopher(Waiter* waiter, int lifespan, int thinkTime, int eatTime);

    void live();
    bool eat();
    void think();

private:
    Waiter* _waiter;
    int _lifeTimeRemaining;
    int _thinkTime;
    int _eatTime;
    bool _dead = false;

    bool checkDead();
};


#endif //LAB3_PHILOSOPHER_H
