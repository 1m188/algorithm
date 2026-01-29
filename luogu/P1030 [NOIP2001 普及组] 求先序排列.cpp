/**
 * @file P1030 [NOIP2001 普及组] 求先序排列.cpp
 * @date 2022-07-16
 */

/*
# [NOIP2001 普及组] 求先序排列

## 题目描述

给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，且二叉树的节点个数 $ \le 8$）。

## 输入格式

共两行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。

## 输出格式

共一行一个字符串，表示一棵二叉树的先序。

## 样例 #1

### 样例输入 #1

```
BADC
BDCA
```

### 样例输出 #1

```
ABCD
```

## 提示

**【题目来源】**

NOIP 2001 普及组第三题
*/

/* 递归求取树根、左子树和右子树，按照先序遍历的顺序进行，挨个压入先序序列之中，
注意递归出口的处理 */

#include <cstdio>
#include <string>
using namespace std;

string inorder, postorder, preorder;

void calc(int is = 0, int ie = inorder.size() - 1, int ps = 0, int pe = postorder.size() - 1) {
    if (is > ie || ps > pe) return;
    if (is == ie || ps == pe) {
        preorder.push_back(inorder[is]);
        return;
    }

    char root = postorder[pe];
    preorder.push_back(root);

    int idx = is;
    while (inorder[idx] != root)
        idx++;

    calc(is, idx - 1, ps, ps + idx - 1 - is);
    calc(idx + 1, ie, ps + idx - 1 - is + 1, pe - 1);
}

int main() {

    inorder.resize(8, '\0'), postorder.resize(8, '\0');
    scanf("%s %s", &inorder[0], &postorder[0]);
    for (int i = 0; i < 8; i++) {
        if (inorder[i] == '\0') {
            inorder.resize(i);
            break;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (postorder[i] == '\0') {
            postorder.resize(i);
            break;
        }
    }

    calc();
    printf("%s", preorder.c_str());

    return 0;
}