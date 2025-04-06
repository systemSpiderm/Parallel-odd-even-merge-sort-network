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
./benchmark "$thread_count" "$length"