#include <iostream>
#include <windows.h>
#include "utils.h"
#include "waiter.h"
#include "philosopher.h"

void waitUser() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
}

int main(int argc, char* args[]) {
    const int totalPhilosophers = 5;

    auto semaphore = CreateSemaphore(
            NULL,
            totalPhilosophers / 2,
            totalPhilosophers / 2,
            NULL
    );

    Waiter waiter(semaphore);
    DWORD simulationTime = 10000; // 10s
    vector<int> lifespans = {3000, 3000, 3000, 3000, 3000}; // 3s
    vector<int> thinkTimes = {1000, 1000, 1000, 1000, 1000}; // 1s
    vector<int> eatTimes = {500, 500, 500, 500, 500}; // 0.5s

    if (argc > 1) {
        simulationTime = atol(args[1]);
    }

    if (argc > 2) {
        lifespans = splitToInt(args[2], ",");
    }

    if (argc > 3) {
        thinkTimes = splitToInt(args[3], ",");
    }

    if (argc > 4) {
        eatTimes = splitToInt(args[4], ",");
    }

    HANDLE threads[totalPhilosophers];

    for (int i = 0; i < totalPhilosophers; i++) {
        auto p = new Philosopher(&waiter, lifespans[i], thinkTimes[i], eatTimes[i]);

        auto handler = [](LPVOID lpParam) -> DWORD {
            ((Philosopher*)lpParam)->live();
            return 0;
        };

        threads[i] = CreateThread(
            NULL,
            0,
            handler,
            p,
            0,
            NULL
        );

        if(threads[i] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
    }

    WaitForMultipleObjects(totalPhilosophers, threads, TRUE, simulationTime);

    for (int i = 0; i < totalPhilosophers; i++) {
        TerminateThread(threads[i], 0);
        CloseHandle(threads[i]);
    }

    CloseHandle(semaphore);
    waitUser();

    return 0;
}
