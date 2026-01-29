/**
 * @file P1996 约瑟夫问题.cpp
 * @date 2022-06-12
 */

/*
# 约瑟夫问题

## 题目描述

$n$ 个人围成一圈，从第一个人开始报数,数到 $m$ 的人出列，再由下一个人重新从 $1$ 开始报数，数到 $m$ 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。

**注意：本题和《深入浅出-基础篇》上例题的表述稍有不同。书上表述是给出淘汰 n-1 名小朋友，而该题是全部出圈。**

## 输入格式

输入两个整数 $n,m$。

## 输出格式

输出一行 $n$ 个整数，按顺序输出每个出圈人的编号。

## 样例 #1

### 样例输入 #1

```
10 3
```

### 样例输出 #1

```
3 6 9 2 7 1 8 5 10 4
```

## 提示

$1 \le m, n \le 100$
*/

#include <cstdio>
#include <vector>
using namespace std;

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++)
        vec[i] = i + 1;

    auto it = vec.begin();
    int num = 1;
    while (!vec.empty()) {
        if (num == m) {
            printf("%d ", *it);
            it = vec.erase(it);
            if (it == vec.end()) it = vec.begin();
            num = 1;
        } else {
            it++;
            if (it == vec.end()) it = vec.begin();
            num++;
        }
    }

    return 0;
}