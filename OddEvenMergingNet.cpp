#include "OddEvenMergingNet.hpp"

void CCI(int &a, int &b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

void SerialMerge(int* arr, int start, int n, int step) {
    if (step >= n) return;
    int mid = start + n / 2;
    int end = start + n;

    
    int *temp = new int[n / step];

    int i = start;    // 指向前半部分
    int j = mid;      // 指向后半部分
    int k = 0;        // 指向临时数组

    while (i < mid && j < end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i];
            i += step;
        } else {
            temp[k++] = arr[j];
            j += step;
        }
    }

    while (i < mid) {temp[k++] = arr[i]; i += step;}
    while (j < end) {temp[k++] = arr[j]; j += step;}

    // 拷贝回原数组
    for (int k = 0, i = start; k < n / step; k++, i += step) {
        arr[i] = temp[k];
    }
    delete[] temp;  // 释放动态分配的内存
}

void* pthread_OddEvenMergingNet(void* args) {
    ThreadData* data = static_cast<ThreadData*>(args);
    OddEvenMergingNet(data->arr, data->start, data->n, data->step, data->thread_count);
    return nullptr;
}


void OddEvenMergingNet(int* arr, int start, int n, int step, int thread_count) {
    if (step * 2 >= n) {
        CCI(arr[start], arr[start + step]);
        return;
    }
    // 递归深度控制
    if (step >= thread_count) {
        SerialMerge(arr, start, n, step);
        return;
    }

    pthread_t thread1, thread2;
    ThreadData* data1 = new ThreadData{arr, start, n, step * 2, thread_count};
    ThreadData* data2 = new ThreadData{arr, start + step, n, step * 2, thread_count};
    pthread_create(&thread1, nullptr, pthread_OddEvenMergingNet, data1);
    pthread_create(&thread2, nullptr, pthread_OddEvenMergingNet, data2);
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    delete data1;
    delete data2;

    for (int i = start + step; i + step < start + n; i += step * 2) {
        CCI(arr[i], arr[i + step]);
    }
}