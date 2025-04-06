#ifndef THREADDATA_HPP
#define THREADDATA_HPP

typedef struct {
    int* arr;
    int start;
    int n;
    int step;
    int thread_count;
} ThreadData;

#endif
