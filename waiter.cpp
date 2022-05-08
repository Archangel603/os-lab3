#include <cstdio>
#include "waiter.h"

Waiter::Waiter(HANDLE semaphore) {
    this->_semaphore = semaphore;
}

bool Waiter::requestForks(int maxWaitTime) {
    DWORD dwWaitResult;

    while (true) {
        dwWaitResult = WaitForSingleObject(this->_semaphore, maxWaitTime);

        switch (dwWaitResult)
        {
            case WAIT_OBJECT_0:
                return true;
            case WAIT_TIMEOUT:
                return false;
            case WAIT_FAILED:
                printf("Failed to wait: %d\n", GetLastError());
                return false;
        }
    }
}

void Waiter::returnForks() {
    if (!ReleaseSemaphore(this->_semaphore,1,NULL))
    {
        printf("Failed to return forks: %d\n", GetLastError());
    }
}
