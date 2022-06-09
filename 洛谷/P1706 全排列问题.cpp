/**
 * @file P1706 全排列问题.cpp
 * @date 2022-06-09
 */

/*
# 全排列问题

## 题目描述

按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

## 输入格式

一个整数 $n$。

## 输出格式

由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。

每个数字保留 $5$ 个场宽。

## 样例 #1

### 样例输入 #1

```
3
```

### 样例输出 #1

```
1    2    3
    1    3    2
    2    1    3
    2    3    1
    3    1    2
    3    2    1
```

## 提示

$1 \leq n \leq 9$。
*/

/* 注意排列和组合的区别，当组合的时候，每次选数应该在上一个数选完之后的下一个数继续选，
避免第一个数选了a，第二个数选了b，之后第一个数选到b第二个数又选a了，这种是只有排列
才会这么做的情况 */

#include <cstdio>
#include <vector>
using namespace std;

int n = 0;
vector<bool> flags;
vector<int> num;

void calc(int cnt = 0) {
    if (cnt == n) {
        for (const auto &e : num)
            printf("%5d", e);
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!flags[i]) {
            flags[i] = true;
            num.push_back(i);
            calc(cnt + 1);
            num.pop_back();
            flags[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    flags.resize(n + 1);
    calc();
    return 0;
}