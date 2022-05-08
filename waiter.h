//
// Created by mikha on 01.05.2022.
//

#ifndef LAB3_WAITER_H
#define LAB3_WAITER_H

#include "windows.h"

class Waiter {

public:
    explicit Waiter(HANDLE semaphore);

    bool requestForks(int maxWaitTime);

    void returnForks();

private:
    int _maxClientsCount;
    HANDLE _semaphore;
};

#endif //LAB3_WAITER_H
