/**
 * @file P4715 【深基16.例1】淘汰赛.cpp
 * @date 2022-07-20
 */

/*
# 【深基16.例1】淘汰赛

## 题目描述

有 $2^n(n\le7)$ 个国家参加世界杯决赛圈且进入淘汰赛环节。已经知道各个国家的能力值，且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。给出各个国家的能力值，请问亚军是哪个国家？

## 输入格式

第一行一个整数 $n$，表示一共 $2^n$ 个国家参赛。

第二行 $2^n$ 个整数，第 $i$ 个整数表示编号为 $i$ 的国家的能力值（$1\leq i \leq 2^n$）。

数据保证不存在平局。

## 输出格式

仅一个整数，表示亚军国家的编号。

## 样例 #1

### 样例输入 #1

```
3
4 2 3 1 10 5 9 7
```

### 样例输出 #1

```
1
```
*/

/* 两两匹配，按照能力值高低决出胜负，注意最后一把要保留，比较能力值找出亚军 */

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int ablity = 0, num = 0;
};

int n = 0, total = 0;
vector<Node> vec;

int main() {

    scanf("%d", &n);
    total = pow(2, n);

    vec.resize(total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &vec[i].ablity);
        vec[i].num = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        vector<Node> nvec;
        for (int j = 0; j < vec.size() - 1; j += 2) {
            if (vec[j].ablity > vec[j + 1].ablity)
                nvec.push_back(vec[j]);
            else
                nvec.push_back(vec[j + 1]);
        }
        vec = nvec;
    }

    printf("%d", vec[0].ablity < vec[1].ablity ? vec[0].num : vec[1].num);

    return 0;
}