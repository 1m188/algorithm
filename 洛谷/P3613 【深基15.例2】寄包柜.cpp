/**
 * @file P3613 【深基15.例2】寄包柜.cpp
 * @date 2022-06-12
 */

/*
# 【深基15.例2】寄包柜

## 题目描述

超市里有 $n(n\le10^5)$ 个寄包柜。每个寄包柜格子数量不一，第 $i$ 个寄包柜有 $a_i(a_i\le10^5)$ 个格子，不过我们并不知道各个 $a_i$ 的值。对于每个寄包柜，格子编号从 1 开始，一直到 $a_i$。现在有 $q(q\le10^5)$ 次操作：

- `1 i j k`：在第 $i$ 个柜子的第 $j$ 个格子存入物品 $k(0\le k\le 10^9)$。当 $k=0$ 时说明清空该格子。
- `2 i j`：查询第 $i$ 个柜子的第 $j$ 个格子中的物品是什么，保证查询的柜子有存过东西。

已知超市里共计不会超过 $10^7$ 个寄包格子，$a_i$ 是确定然而未知的，但是保证一定不小于该柜子存物品请求的格子编号的最大值。当然也有可能某些寄包柜中一个格子都没有。

## 输入格式

第一行 2 个整数 n 和 q，寄包柜个数和询问次数。

接下来 q 个整数，表示一次操作。

## 输出格式

对于查询操作时，输出答案。

## 样例 #1

### 样例输入 #1

```
5 4
1 3 10000 118014
1 1 1 1
2 3 10000
2 1 1
```

### 样例输出 #1

```
118014
1
```
*/

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> vec;

int main() {

    int n = 0, q = 0;
    scanf("%d %d", &n, &q);
    vec.resize(n);

    while (q--) {
        int op = 0;
        scanf("%d", &op);
        if (op == 1) {
            int i = 0, j = 0, k = 0;
            scanf("%d %d %d", &i, &j, &k);
            if (vec[i - 1].size() < j) vec[i - 1].resize(j);
            vec[i - 1][j - 1] = k;
        } else {
            int i = 0, j = 0;
            scanf("%d %d", &i, &j);
            printf("%d\n", vec[i - 1][j - 1]);
        }
    }

    return 0;
}