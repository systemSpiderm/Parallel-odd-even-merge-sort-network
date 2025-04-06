#ifndef ODD_EVEN_MERGING_SORT_HPP
#define ODD_EVEN_MERGING_SORT_HPP

#include "OddEvenMergingNet.hpp"


void* pthread_OddEvenMergingSort(void* args);

void OddEvenMergingSort(int* arr, int start, int n, int thread_count);

#endif