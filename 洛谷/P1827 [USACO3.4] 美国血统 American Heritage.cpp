/**
 * @file P1827 [USACO3.4] 美国血统 American Heritage.cpp
 * @date 2022-07-20
 */

/*
# [USACO3.4] 美国血统 American Heritage

## 题目描述

农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他的奶牛 们的家谱作成二叉树，并且把二叉树以更线性的“树的中序遍历”和“树的前序遍历”的符号加以记录而 不是用图形的方法。

你的任务是在被给予奶牛家谱的“树中序遍历”和“树前序遍历”的符号后，创建奶牛家谱的“树的 后序遍历”的符号。每一头奶牛的姓名被译为一个唯一的字母。（你可能已经知道你可以在知道树的两 种遍历以后可以经常地重建这棵树。）显然，这里的树不会有多于 26 个的顶点。  这是在样例输入和 样例输出中的树的图形表达方式：


```
　　　　　　　　 C
　　　　　　   /  \
　　　　　　  /　　\
　　　　　　 B　　  G
　　　　　　/ \　　/
　　　　   A   D  H
　　　　　　  / \
　　　　　　 E   F

```

树的中序遍历是按照左子树，根，右子树的顺序访问节点。

树的前序遍历是按照根，左子树，右子树的顺序访问节点。

树的后序遍历是按照左子树，右子树，根的顺序访问节点。

## 输入格式

第一行： 树的中序遍历

第二行： 同样的树的前序遍历

## 输出格式

单独的一行表示该树的后序遍历。

## 样例 #1

### 样例输入 #1

```
ABEDFCHG
CBADEFGH
```

### 样例输出 #1

```
AEFDBHGC
```

## 提示

题目翻译来自NOCOW。

USACO Training Section 3.4
*/

/* 数组存储树，并且使用先序序列和中序序列模拟后序遍历 */

#include <cstdio>
#include <string>
using namespace std;

string inorder, preorder, postorder;

void calc(int is = 0, int ie = inorder.size() - 1, int ps = 0, int pe = preorder.size() - 1) {
    if (is > ie || ps > pe) return;
    if (is == ie || ps == pe) {
        postorder.push_back(inorder[is]);
        return;
    }

    char root = preorder[ps];
    int ri = is;
    while (inorder[ri] != root)
        ri++;

    calc(is, ri - 1, ps + 1, ps + ri - is);
    calc(ri + 1, ie, ps + ri - is + 1, pe);

    postorder.push_back(root);
}

int main() {

    inorder.resize(26, '\0'), preorder.resize(26, '\0');
    scanf("%s %s", &inorder[0], &preorder[0]);
    for (int i = 0; i < 26; i++) {
        if (inorder[i] == '\0') {
            inorder.resize(i);
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (preorder[i] == '\0') {
            preorder.resize(i);
            break;
        }
    }

    calc();

    printf("%s", postorder.c_str());

    return 0;
}