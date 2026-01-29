/**
 * @file P1271 【深基9.例1】选举学生会.cpp
 * @date 2022-06-05
 */

/*
# 【深基9.例1】选举学生会

## 题目描述

学校正在选举学生会成员，有 $n(n\le 999)$ 名候选人，每名候选人编号分别从 1 到 $n$，现在收集到了 $m(m<=2000000)$ 张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。

## 输入格式

输入 $n$ 和 $m$ 以及 $m$ 个选票上的数字。

## 输出格式

求出排序后的选票编号。

## 样例 #1

### 样例输入 #1

```
5 10
2 5 2 2 5 2 2 2 1 2
```

### 样例输出 #1

```
1 2 2 2 2 2 2 2 5 5
```
*/

/* 考虑到选票数实在是太多，不如用map记录每个数字及其出现的次数，
并且在输入map的时候也能按照key自动排序 */

#include <cstdio>
#include <map>
#include <utility>
using namespace std;

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    map<int, int> mp;

    for (int i = 0; i < m; i++) {
        int a = 0;
        scanf("%d", &a);
        mp[a]++;
    }

    for (const pair<int, int> &e : mp) {
        for (int i = 0; i < e.second; i++) {
            printf("%d ", e.first);
        }
    }

    return 0;
}