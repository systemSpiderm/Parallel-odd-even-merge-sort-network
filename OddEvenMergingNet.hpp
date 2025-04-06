#ifndef ODDEVENMERGINGNET_HPP
#define ODDEVENMERGINGNET_HPP
#include "ThreadData.hpp"
#include <pthread.h>


// compare and conditionally interchange
void CCI(int &a, int &b);

void SerialMerge(int* arr, int start, int n, int step);

void* pthread_OddEvenMergingNet(void* args);

void OddEvenMergingNet(int* arr, int start, int n, int step, int thread_count);

#endif