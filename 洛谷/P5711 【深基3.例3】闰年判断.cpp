/**
 * @file P5711 【深基3.例3】闰年判断.cpp
 * @date 2022-06-22
 */

/*
# 【深基3.例3】闰年判断

## 题目描述

输入一个年份（大于 1582 的整数 ），判断这一年是否是闰年，如果是输出 1，否则输出 0。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
1926
```

### 样例输出 #1

```
0
```

## 样例 #2

### 样例输入 #2

```
1900
```

### 样例输出 #2

```
0
```

## 样例 #3

### 样例输入 #3

```
2000
```

### 样例输出 #3

```
1
```

## 样例 #4

### 样例输入 #4

```
1996
```

### 样例输出 #4

```
1
```
*/

#include <cstdio>
using namespace std;

int main() {
    int y = 0;
    scanf("%d", &y);
    printf(((!(y % 4) && (y % 100))) || !(y % 400) ? "1" : "0");
    return 0;
}