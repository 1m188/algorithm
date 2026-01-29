/**
 * @file P5705 【深基2.例7】数字反转.cpp
 * @date 2022-06-08
 */

/*
# 【深基2.例7】数字反转

## 题目描述

输入一个不小于 $100$ 且小于 $1000$，同时包括小数点后一位的一个浮点数，例如 $123.4$ ，要求把这个数字翻转过来，变成 $4.321$ 并输出。

## 输入格式

一行一个浮点数

## 输出格式

一行一个浮点数

## 样例 #1

### 样例输入 #1

```
123.4
```

### 样例输出 #1

```
4.321
```
*/

#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {

    string s(5, '\0');
    scanf("%s", &s[0]);
    reverse(s.begin(), s.end());
    printf("%s", s.c_str());

    return 0;
}