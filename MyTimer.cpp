#include "MyTimer.h"
#include <stdio.h>

MyTimer::MyTimer()
{
    start = std::chrono::high_resolution_clock::now();
}

void MyTimer::startTimer()
{
    start = std::chrono::high_resolution_clock::now();
}

void MyTimer::stopTimer()
{
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_base{};

    duration_base = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::chrono::nanoseconds time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(duration_base);
    duration = time_in_ns.count() * 1e-6;
}

void MyTimer::printTime()
{
    printf("Czas wykonania: %.4f ms\n", duration);
}
