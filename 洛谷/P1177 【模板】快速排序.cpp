/**
 * @file P1177 【模板】快速排序.cpp
 * @date 2022-06-01
 */

/*
# 【模板】快速排序

## 题目描述

利用快速排序算法将读入的 $N$ 个数从小到大排序后输出。

快速排序是信息学竞赛的必备算法之一。对于快速排序不是很了解的同学可以自行上网查询相关资料，掌握后独立完成。（C++ 选手请不要试图使用 `STL`，虽然你可以使用 `sort` 一遍过，但是你并没有掌握快速排序算法的精髓。）

## 输入格式

第 $1$ 行为一个正整数 $N$，第 $2$ 行包含 $N$ 个空格隔开的正整数 $a_i$，为你需要进行排序的数，数据保证了 $A_i$ 不超过 $10^9$。

## 输出格式

将给定的 $N$ 个数从小到大输出，数之间空格隔开，行末换行且无空格。

## 样例 #1

### 样例输入 #1

```
5
4 2 4 5 1
```

### 样例输出 #1

```
1 2 4 4 5
```

## 提示

对于 $20\%$ 的数据，有 $N\leq 10^3$；

对于 $100\%$ 的数据，有 $N\leq 10^5$。
*/

/* 快速排序 */

#include <cstdio>
#include <vector>
using namespace std;

template <typename T>
void quicksort(vector<T> &vec, int left, int right) {

    if (left >= right) return;

    int start = left, end = right;
    T tmp = vec[start];

    while (start < end) {
        while (start < end && vec[end] > tmp)
            end--;
        if (start < end) vec[start++] = vec[end];

        while (start < end && vec[start] < tmp)
            start++;
        if (start < end) vec[end--] = vec[start];
    }

    vec[start] = tmp;

    quicksort(vec, left, start - 1);
    quicksort(vec, start + 1, right);
}

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    quicksort(vec, 0, vec.size() - 1);

    for (int i = 0; i < vec.size() - 1; i++)
        printf("%d ", vec[i]);
    printf("%d\n", vec.back());

    return 0;
}