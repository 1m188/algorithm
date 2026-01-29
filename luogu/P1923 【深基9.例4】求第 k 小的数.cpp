/**
 * @file P1923 【深基9.例4】求第 k 小的数.cpp
 * @date 2022-06-01
 */

/*
# 【深基9.例4】求第 k 小的数

## 题目描述

输入 $n$（$1 \le n < 5000000$ 且 $n$ 为奇数）个数字 $a_i$（$1 \le a_i < {10}^9$），输出这些数字的第 $k$ 小的数。最小的数是第 $0$ 小。

请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
5 1
4 3 2 1 5
```

### 样例输出 #1

```
2
```
*/

/* 大顶堆求前k小的数，最后求出前k小的数中的最大的数，即为第k大的数，这里从0开始，
所以输入的k还要+1 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

template <typename T>
void adjust(vector<T> &vec, int x) {

    T tmp = vec[x];

    int k = x * 2 + 1;
    while (k < vec.size()) {
        if (k + 1 < vec.size() && vec[k + 1] > vec[k])
            k = k + 1;

        if (vec[k] > tmp)
            vec[x] = vec[k];
        else
            break;

        x = k;
        k = x * 2 + 1;
    }

    vec[x] = tmp;
}

template <typename T>
void build_heap(vector<T> &vec) {
    for (int i = (vec.size() - 1 - 1) / 2; i >= 0; i--)
        adjust(vec, i);
}

int main() {

    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    vector<int> vec(k + 1);

    for (int i = 0; i < k + 1; i++)
        scanf("%d", &vec[i]);

    build_heap(vec);

    for (int i = k + 1; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        if (a < vec[0]) {
            vec[0] = a;
            adjust(vec, 0);
        }
    }

    printf("%d", *max_element(vec.begin(), vec.end()));

    return 0;
}