//  compile: g++ -o test -lpthread test.cpp OddEvenMergingSort.cpp OddEvenMergingNet.cpp
//  run: ./test


#include <iostream>
#include "OddEvenMergingSort.hpp"

int main() {
    int arr[16] = {5, 2, 9, 1, 5, 6, 7, 3, 8, 4, 0, 10, 12, 11, 14, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int thread_count = 4; // 线程数
    OddEvenMergingSort(arr, 0, n, thread_count);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

