/**
 * @file P1152 欢乐的跳.cpp
 * @date 2022-06-05
 */

/*
# 欢乐的跳

## 题目描述

一个$n$个元素的整数数组，如果数组两个连续元素之间差的绝对值包括了$[1,n-1]$之间的所有整数，则称之符合“欢乐的跳”，如数组$1 4 2 3$符合“欢乐的跳”，因为差的绝对值分别为：$3,2,1$。

给定一个数组，你的任务是判断该数组是否符合“欢乐的跳”。

## 输入格式

每组测试数据第一行以一个整数$n(1 \le n \le 1000)$开始，接下来$n$个空格隔开的在[$-10^8$,$10^8$]之间的整数。

## 输出格式

对于每组测试数据，输出一行若该数组符合“欢乐的跳”则输出"Jolly"，否则输出"Not jolly"。

## 样例 #1

### 样例输入 #1

```
4 1 4 2 3
```

### 样例输出 #1

```
Jolly
```

## 样例 #2

### 样例输入 #2

```
5 1 4 2 -1 6
```

### 样例输出 #2

```
Not jolly
```

## 提示

$1 \le n \le 1000$
*/

/* 输入，对两数之差进行排序，之后逐个检查 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec, diff;

int main() {

    int n = 0;
    scanf("%d", &n);

    vec.resize(n);
    diff.resize(n - 1);

    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    for (int i = 0; i < n - 1; i++)
        diff[i] = abs(vec[i + 1] - vec[i]);

    sort(diff.begin(), diff.end());

    for (int i = 0; i < n - 1; i++) {
        if (diff[i] != i + 1) {
            printf("Not jolly");
            return 0;
        }
    }
    printf("Jolly");

    return 0;
}