/**
 * @file P4913 【深基16.例3】二叉树深度.cpp
 * @date 2022-06-12
 */

/*
# 【深基16.例3】二叉树深度

## 题目描述

给出每个节点的两个儿子节点，建立一棵二叉树（根节点为 $1$），如果是叶子节点，则输入`0 0`。建好树后希望知道这棵二叉树的深度。二叉树的**深度**是指从根节点到叶子结点时，最多经过了几层。

最多有 $10^6$ 个结点。

## 输入格式

第一行一个整数 $n$，表示节点数。

之后 $n$ 行，第 $i$ 行两个整数 $l$、$r$，分别表示节点 $i$ 的左右子节点。若 $l=0$ 则表示无左子节点，$r=0$ 同理。

## 输出格式

一个整数，表示最大节点深度。

## 样例 #1

### 样例输入 #1

```
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0
```

### 样例输出 #1

```
4
```
*/

/* 递归求树的深度，只不过换成了数组 */

#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;

int max_depth(int x = 1) {
    if (!x) return 0;
    return max(max_depth(vec[x].first), max_depth(vec[x].second)) + 1;
}

int main() {

    int n = 0;
    scanf("%d", &n);
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &vec[i].first, &vec[i].second);
    printf("%d", max_depth());

    return 0;
}