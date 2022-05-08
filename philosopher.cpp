#include "philosopher.h"

Philosopher::Philosopher(Waiter *waiter, int lifespan, int thinkTime, int eatTime) {
    this->_waiter = waiter;
    this->_lifeTimeRemaining = lifespan;
    this->_thinkTime = thinkTime;
    this->_eatTime = eatTime;
}

void Philosopher::live() {
    while (!this->_dead) {
        this->think();

        if (this->checkDead())
            return;

        this->eat();
    }
}

bool Philosopher::eat() {
    printf("The philosopher %d is starving\n", GetCurrentThreadId());

    if (!this->_waiter->requestForks(this->_lifeTimeRemaining)) {
        printf("Unable to get forks. The philosopher %d died\n", GetCurrentThreadId());
        this->_dead = true;
        return false;
    }

    printf("The philosopher %d is eating...\n", GetCurrentThreadId());

    Sleep(this->_eatTime);

    this->_waiter->returnForks();

    printf("The philosopher %d returned forks to the waiter\n", GetCurrentThreadId());

    this->_lifeTimeRemaining += this->_eatTime;

    printf("The philosopher %d has %d life time left\n", GetCurrentThreadId(), this->_lifeTimeRemaining);

    return true;
}

void Philosopher::think() {
    printf("The philosopher %d is thinking...\n", GetCurrentThreadId());

    Sleep(this->_thinkTime);
    this->_lifeTimeRemaining -= this->_thinkTime;

    printf("The philosopher %d finished thinking\n", GetCurrentThreadId());
}

bool Philosopher::checkDead() {
    if (this->_lifeTimeRemaining <= 0) {
        this->_dead = true;
        printf("The philosopher %d died\n", GetCurrentThreadId());
    }

    return this->_dead;
}
