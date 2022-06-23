/**
 * @file P5716 【深基3.例9】月份天数.cpp
 * @date 2022-06-23
 */

/*
# 【深基3.例9】月份天数

## 题目描述

输入年份和月份，输出这一年的这一月有多少天。需要考虑闰年。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
1926 8
```

### 样例输出 #1

```
31
```

## 样例 #2

### 样例输入 #2

```
2000 2
```

### 样例输出 #2

```
29
```
*/

#include <cstdio>
using namespace std;

bool isleap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int y = 0, m = 0;
    scanf("%d %d", &y, &m);
    switch (m) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("31");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30");
        break;
    case 2:
        if (isleap(y))
            printf("29");
        else
            printf("28");
    }
    return 0;
}