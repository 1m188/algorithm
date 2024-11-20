/**
 * @file HJ58 输入n个整数，输出其中最小的k个.cpp
 * @date 2024-11-20
 */

/*
描述
输入n个整数，找出其中最小的k个整数并按升序输出

本题有多组输入样例

数据范围：
1
≤
n
≤
1000

1≤n≤1000  ，输入的整数满足
1
≤
v
a
l
≤
10000

1≤val≤10000
输入描述：
第一行输入两个整数n和k
第二行输入一个整数数组

输出描述：
从小到大输出最小的k个整数，用空格分开。

示例1
输入：
5 2
1 3 5 7 2
复制
输出：
1 2
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void adjust(vector<T> &heap, int index, int n) {
    while (true) {
        int idx = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left <= n && heap[left] > heap[idx]) idx = left;
        if (right <= n && heap[right] > heap[idx]) idx = right;
        if (idx == index) break;
        swap(heap[idx], heap[index]);
        index = idx;
    }
}

template <typename T>
void build_heap(vector<T> &heap) {
    for (int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        adjust(heap, i, heap.size() - 1);
}

template <typename T>
void heap_sort(vector<T> &heap) {
    for (int i = heap.size() - 1; i >= 0; i--) {
        adjust(heap, 0, i);
        swap(heap[0], heap[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> heap(k);
    for (int i = 0; i < k; i++) {
        cin >> heap[i];
    }
    build_heap(heap);
    for (int i = k; i < n; i++) {
        int x = 0;
        cin >> x;
        if (x < heap[0]) {
            heap[0] = x;
            adjust(heap, 0, heap.size() - 1);
        }
    }

    heap_sort(heap);

    cout << heap[0];
    for (int i = 1; i < k; i++) {
        cout << ' ' << heap[i];
    }

    return 0;
}
