/**
 * @file P1157 组合的输出.cpp
 * @date 2022-06-09
 */

/*
# 组合的输出

## 题目描述

排列与组合是常用的数学方法，其中组合就是从$n$个元素中抽出$r$个元素(不分顺序且$r \le n)$，我们可以简单地将$n$个元素理解为自然数$1,2,…,n$，从中任取$r$个数。

现要求你输出所有组合。

例如$n=5,r=3$，所有组合为：

$12 3 ,   1 2 4  ,  1 2 5  ,  1 3 4   ,1 3 5 ,   1 4 5 ,   2 3 4 ,   2 3 5  ,  2 4 5  ,  3 4 5$

## 输入格式

一行两个自然数$n,r(1<n<21,0 \le r \le n)$。

## 输出格式

所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。

**注意哦!输出时，每个数字需要$3$个场宽，pascal可以这样：

write(ans:3);

## 样例 #1

### 样例输入 #1

```
5 3
```

### 样例输出 #1

```
1  2  3
  1  2  4
  1  2  5
  1  3  4
  1  3  5
  1  4  5
  2  3  4
  2  3  5
  2  4  5
  3  4  5
```
*/

/* 注意组合，不是排序 */

#include <cstdio>
#include <vector>
using namespace std;

int n = 0, r = 0;
vector<bool> flags; // 该数是否被选过，其索引就是该数
vector<int> num;    // 组合

/**
 * @brief 递归r次选数
 * @param cnt 选了几个数
 * @param idx 从哪个索引（数）开始选数
 */
void calc(int cnt = 0, int idx = 1) {
    if (cnt == r) {
        for (const auto &e : num)
            printf("%3d", e);
        printf("\n");
        return;
    }

    for (int i = idx; i <= n; i++) {
        if (!flags[i]) {
            flags[i] = true;
            num.push_back(i);
            calc(cnt + 1, i + 1);
            num.pop_back();
            flags[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &r);
    flags.resize(n + 1);
    calc();
    return 0;
}