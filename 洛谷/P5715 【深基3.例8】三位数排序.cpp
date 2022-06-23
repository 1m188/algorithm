/**
 * @file P5715 【深基3.例8】三位数排序.cpp
 * @date 2022-06-23
 */

/*
# 【深基3.例8】三位数排序

## 题目描述

给出三个整数 $a,b,c(0\le a,b,c \le 100)$，要求把这三位整数从小到大排序。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
1 14 5
```

### 样例输出 #1

```
1 5 14
```

## 样例 #2

### 样例输入 #2

```
2 2 2
```

### 样例输出 #2

```
2 2 2
```
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int vec[3];
    scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
    sort(vec, vec + 3);
    printf("%d %d %d", vec[0], vec[1], vec[2]);
    return 0;
}