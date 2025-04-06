#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <chrono>

#include "OddEvenMergingSort.hpp"


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Please enter thread_count(1, 2, 4, 8) and length of array. " << std::endl;
        exit(1);
    }
    srand(time(0));

    int thread_count = atoi(argv[1]);
    int N = atoi(argv[2]);
    if (thread_count != 1 && thread_count != 2 && thread_count != 4 && thread_count != 8) {
        std::cerr << "Invalid thread_count! " << std::endl;
        exit(1);
    }
    if (N <= 0) {
        std::cout << "length must be positive! " << std::endl;
        exit(1);
    }

    
    int N1 = pow(2, ceil(log2(N))); // 确保N是2的幂次

    int* original_arr = new int[N1];
    for (int i = 0; i < N1; i++) {
        if (i < N) {
            original_arr[i] = rand() % 1919810;
        } else {
            original_arr[i] = 1919810;
        }
    }

    std::vector<int> stdarr(original_arr, original_arr + N1);
    
    auto start_parallel = std::chrono::high_resolution_clock::now();
    
    OddEvenMergingSort(original_arr, 0, N1, thread_count);

    auto end_parallel = std::chrono::high_resolution_clock::now();
    auto parallel_duration = std::chrono::duration<double>(end_parallel - start_parallel).count();
    std::cout << "Running time of odd-even merging sort: " << parallel_duration << " seconds\n";

    auto start_std = std::chrono::high_resolution_clock::now();
    sort(stdarr.begin(), stdarr.end());
    auto end_std = std::chrono::high_resolution_clock::now();
    auto std_duration = std::chrono::duration<double>(end_std - start_std).count();
    std::cout << "Running time of std sort: " << std_duration << " seconds\n";

    // 验证排序正确性
    bool is_correct = true;
    for (int i = 0; i < N1; i++) {
        if (original_arr[i] != stdarr[i]) {
            is_correct = false;
            break;
        }
    }
    if (is_correct) {
        std::cout << "Sorting is correct!" << std::endl;
    } else {
        std::cout << "Sorting is incorrect!" << std::endl;
    }

    return 0;
}


