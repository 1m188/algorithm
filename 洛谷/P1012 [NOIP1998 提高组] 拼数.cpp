/**
 * @file P1012 [NOIP1998 提高组] 拼数.cpp
 * @date 2022-06-04
 */

/*
# [NOIP1998 提高组] 拼数

## 题目描述

设有 $n$ 个正整数 $a_1 \dots a_n$，将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。

## 输入格式

第一行有一个整数，表示数字个数 $n$。

第二行有 $n$ 个整数，表示给出的 $n$ 个整数 $a_i$。

## 输出格式

一个正整数，表示最大的整数

## 样例 #1

### 样例输入 #1

```
3
13 312 343
```

### 样例输出 #1

```
34331213
```

## 样例 #2

### 样例输入 #2

```
4
7 13 4 246
```

### 样例输出 #2

```
7424613
```

## 提示

对于全部的测试点，保证 $1 \leq n \leq 20$，$1 \leq a_i \leq 10^9$。
*/

/* 排序，对于a和b两个字符串而言，如果ab组成的数字大于ba组成的数字，那么
a就应该排在b前面 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<string> vec;
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        vec.push_back(to_string(a));
    }

    sort(vec.begin(), vec.end(), [](const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    });

    string ans;
    for_each(vec.begin(), vec.end(), [&](const string &s) {
        ans += s;
    });

    printf("%s", ans.c_str());

    return 0;
}