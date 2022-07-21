/**
 * @file P1551 亲戚.cpp
 * @date 2022-07-21
 */

/*
# 亲戚

## 题目背景

若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。

## 题目描述

规定：$x$ 和 $y$ 是亲戚，$y$ 和 $z$ 是亲戚，那么 $x$ 和 $z$ 也是亲戚。如果 $x$，$y$ 是亲戚，那么 $x$ 的亲戚都是 $y$ 的亲戚，$y$ 的亲戚也都是 $x$ 的亲戚。

## 输入格式

第一行：三个整数 $n,m,p$，（$n,m,p \le 5000$），分别表示有 $n$ 个人，$m$ 个亲戚关系，询问 $p$ 对亲戚关系。

以下 $m$ 行：每行两个数 $M_i$，$M_j$，$1 \le M_i,~M_j\le N$，表示 $M_i$ 和 $M_j$ 具有亲戚关系。

接下来 $p$ 行：每行两个数 $P_i,P_j$，询问 $P_i$ 和 $P_j$ 是否具有亲戚关系。

## 输出格式

$p$ 行，每行一个 `Yes` 或 `No`。表示第 $i$ 个询问的答案为“具有”或“不具有”亲戚关系。

## 样例 #1

### 样例输入 #1

```
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
```

### 样例输出 #1

```
Yes
Yes
No
```
*/

/* 并查集 */
// 这里按照编号更小者为根的原则进行集合的合并

#include <cstdio>
#include <vector>
using namespace std;

int n = 0, m = 0, p = 0;
vector<int> vec;

int uffind(int x) {
    if (vec[x] != x) vec[x] = uffind(vec[x]);
    return vec[x];
}

void ufunion(int x, int y) {
    int rx = uffind(x), ry = uffind(y);
    if (rx < ry)
        vec[ry] = rx;
    else
        vec[rx] = ry;
}

int main() {

    scanf("%d %d %d", &n, &m, &p);

    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        vec[i] = i;

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        ufunion(a, b);
    }

    for (int i = 0; i < p; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (uffind(a) == uffind(b))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}