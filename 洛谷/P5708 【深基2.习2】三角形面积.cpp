/**
 * @file P5708 【深基2.习2】三角形面积.cpp
 * @date 2022-06-11
 */

/*
# 【深基2.习2】三角形面积

## 题目描述

一个三角形的三边长分别是 $a$、$b$、$c$，那么它的面积为 $\sqrt{p(p-a)(p-b)(p-c)}$，其中 $p=\frac{1}{2}(a+b+c)$。输入这三个数字，计算三角形的面积，四舍五入精确到 1 位小数。

保证能构成三角形，$0\leq a,b,c\leq 1000$，每个边长输入时不超过2位小数。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
3 4 5
```

### 样例输出 #1

```
6.0
```
*/

#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double a = 0, b = 0, c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a + b + c) / 2;
    printf("%.1lf", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}