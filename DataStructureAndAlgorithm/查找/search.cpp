/*
基于 C++ 实现的常用查找算法
*/

#include <cassert>
#include <iostream>
#include <vector>

// 顺序查找
template <typename T>
int64_t sequential_search(const std::vector<T> &arr, const T &target) {
    for (int64_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 二分查找
template <typename T>
int64_t binary_search(const std::vector<T> &arr, const T &target) {
    int64_t left = 0, right = arr.size() - 1;
    while (left <= right) {
        int64_t mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {

    auto arr = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(sequential_search(arr, 1) == 0);
    assert(sequential_search(arr, 10) == 9);
    assert(sequential_search(arr, 5) == 4);
    assert(sequential_search(arr, 11) == -1);

    arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    assert(sequential_search(arr, 1) == 9);
    assert(sequential_search(arr, 10) == 0);
    assert(sequential_search(arr, 5) == 5);
    assert(sequential_search(arr, 11) == -1);

    arr = {1};
    assert(sequential_search(arr, 1) == 0);
    assert(sequential_search(arr, 11) == -1);

    arr = {};
    assert(sequential_search(arr, 11) == -1);

    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binary_search(arr, 1) == 0);
    assert(binary_search(arr, 10) == 9);
    assert(binary_search(arr, 5) == 4);
    assert(binary_search(arr, 11) == -1);

    arr = {1};
    assert(binary_search(arr, 1) == 0);
    assert(binary_search(arr, 11) == -1);

    arr = {};
    assert(binary_search(arr, 11) == -1);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
