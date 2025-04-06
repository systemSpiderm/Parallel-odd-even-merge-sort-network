#include "OddEvenMergingSort.hpp"

void* pthread_OddEvenMergingSort(void* args) {
    ThreadData* data = static_cast<ThreadData*>(args);
    OddEvenMergingSort(data->arr, data->start, data->n, data->thread_count);
    return nullptr;
}

void OddEvenMergingSort(int* arr, int start, int n, int thread_count) {
    if (n <= 1) return;

    // 如果线程数大于1，则并行执行左右两半
    if (thread_count > 1) {
        pthread_t thread1, thread2;

        ThreadData* data1 = new ThreadData{arr, start, n / 2, -1, thread_count / 2};
        ThreadData* data2 = new ThreadData{arr, start + n / 2, n / 2, -1, thread_count - thread_count / 2};

        pthread_create(&thread1, nullptr, pthread_OddEvenMergingSort, data1);
        pthread_create(&thread2, nullptr, pthread_OddEvenMergingSort, data2);
        pthread_join(thread1, nullptr);
        pthread_join(thread2, nullptr);

        delete data1;
        delete data2;
    } else {
        // 串行递归左右两半
        OddEvenMergingSort(arr, start, n / 2, 1);
        OddEvenMergingSort(arr, start + n / 2, n / 2, 1);
    }

    // 合并两半（调用归并网络）
    OddEvenMergingNet(arr, start, n, 1, thread_count);
}