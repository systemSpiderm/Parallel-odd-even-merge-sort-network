#!/bin/bash

# 编译程序
echo "Compiling the program..."
g++ -o benchmark benchmark.cpp OddEvenMergingSort.cpp OddEvenMergingNet.cpp -lpthread

# 检查编译是否成功
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

echo "Compilation successful."

# 提示用户输入线程数和数组长度
echo "Please input thread_count(1,2,4,8) and length of array:"

# 读取用户输入
read -p "Thread count: " thread_count
read -p "Length of array: " length

# 检查输入合法性
if [[ ! "$thread_count" =~ ^(1|2|4|8)$ ]]; then
    echo "Invalid thread count. Must be one of 1, 2, 4, 8."
    exit 1
fi

if [[ ! "$length" =~ ^[0-9]+$ ]]; then
    echo "Invalid length of array. Must be a positive integer."
    exit 1
fi

# 运行程序
echo "Running the program with thread count $thread_count and array length $length..."
./benchmark "$thread_count" "$length"