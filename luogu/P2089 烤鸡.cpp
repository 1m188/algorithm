/**
 * @file P2089 烤鸡.cpp
 * @date 2022-06-08
 */

/*
# 烤鸡

## 题目背景

猪猪 Hanke 得到了一只鸡。

## 题目描述

猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。

## 输入格式

一个正整数 $n$，表示美味程度。

## 输出格式

第一行，方案总数。

第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 $0$。

## 样例 #1

### 样例输入 #1

```
11
```

### 样例输出 #1

```
10
1 1 1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 1 2 1 
1 1 1 1 1 1 1 2 1 1 
1 1 1 1 1 1 2 1 1 1 
1 1 1 1 1 2 1 1 1 1 
1 1 1 1 2 1 1 1 1 1 
1 1 1 2 1 1 1 1 1 1 
1 1 2 1 1 1 1 1 1 1 
1 2 1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 1 1
```

## 提示

对于 $100\%$ 的数据，$n \leq 5000$。
*/

/* 递归求10次，暴力枚举 */

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> ans; // 最终答案
vector<int> tmp;         // 中间结果

/**
 * @brief 枚举
 * @param x 剩余的美味程度
 * @param cnt 计数，一共有10种调料
 */
void calc(int x, int cnt = 0) {
    if (cnt == 10) { // 递归出口
        if (x == 0)  // 注意一定剩余的要为0
            ans.push_back(tmp);
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (x - i >= 0) {
            tmp.push_back(i);
            calc(x - i, cnt + 1);
            tmp.pop_back();
        }
    }
}

int main() {

    int n = 0;
    scanf("%d", &n);

    if (n < 10 || n > 30) { // 不可能情况
        printf("0");
        return 0;
    }

    calc(n);

    printf("%zu\n", ans.size());
    for (const auto &vec : ans) {
        printf("%d", vec[0]);
        for (int i = 1; i < vec.size(); i++)
            printf(" %d", vec[i]);
        printf("\n");
    }

    return 0;
}