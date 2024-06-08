#ifndef MYTIMER_H
#define MYTIMER_H

#include <iostream>
#include <chrono>

class MyTimer {

public:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    double duration;
    double sum = 0;

    MyTimer();
    void startTimer();
    void stopTimer();
    void printTime();
};

#endif