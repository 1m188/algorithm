/**
 * @file P1305 新二叉树.cpp
 * @date 2022-07-17
 */

/*
# 新二叉树

## 题目描述

输入一串二叉树，输出其前序遍历。

## 输入格式

第一行为二叉树的节点数 $n$。($1 \leq n \leq 26$)

后面 $n$ 行，每一个字母为节点，后两个字母分别为其左右儿子。特别地，数据保证第一行读入的节点必为根节点。

空节点用 `*` 表示

## 输出格式

二叉树的前序遍历。

## 样例 #1

### 样例输入 #1

```
6
abc
bdi
cj*
d**
i**
j**
```

### 样例输出 #1

```
abdicj
```
*/

/* 数组存储树，树节点比较少，用数字代替节点编号，做好转换关系处理，递归先序遍历 */

#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int left = -1, right = -1;
};

int n = 0;
int root = -1;

vector<Node> tree;

void preorder(int r = root) {
    if (r != -1) {
        printf("%c", 'a' + r);
        preorder(tree[r].left);
        preorder(tree[r].right);
    }
}

int main() {

    scanf("%d", &n);
    tree.resize(26);

    for (int i = 0; i < n; i++) {
        char a, b, c;
        scanf(" %c%c%c", &a, &b, &c);
        if (i == 0) root = a - 'a';
        if (b != '*') tree[a - 'a'].left = b - 'a';
        if (c != '*') tree[a - 'a'].right = c - 'a';
    }

    preorder();

    return 0;
}