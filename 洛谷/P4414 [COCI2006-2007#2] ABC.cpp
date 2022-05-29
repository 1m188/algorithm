/**
 * @file P4414 [COCI2006-2007#2] ABC.cpp
 * @date 2022-05-29
 */

/*
# [COCI2006-2007#2] ABC

## 题面翻译

**【题目描述】**

三个整数分别为 $A,B,C$。这三个数字不会按照这样的顺序给你，但它们始终满足条件：$A < B < C$。为了看起来更加简洁明了，我们希望你可以按照给定的顺序重新排列它们。

**【输入格式】**

第一行包含三个正整数 $A,B,C$，不一定是按这个顺序。这三个数字都小于或等于 $100$。第二行包含三个大写字母 $A$、$B$ 和 $C$（它们之间**没有**空格）表示所需的顺序。

**【输出格式】**

在一行中输出 $A$，$B$ 和 $C$，用一个 ` `（空格）隔开。

感谢 @smartzzh 提供的翻译

## 题目描述

You will be given three integers A, B and C. The numbers will not be given in that exact order, but we do know that A is less than B and B less than C.
In order to make for a more pleasant viewing, we want to rearrange them in the given order.

## 输入格式

The first line contains three positive integers A, B and C, not necessarily in that order. All three numbers will be less than or equal to 100.
The second line contains three uppercase letters 'A', 'B' and 'C' (with no spaces between them) representing the desired order.

## 输出格式

Output the A, B and C in the desired order on a single line, separated by single spaces.

## 样例 #1

### 样例输入 #1

```
1 5 3
ABC
```

### 样例输出 #1

```
1 3 5
```

## 样例 #2

### 样例输入 #2

```
6 4 2
CAB
```

### 样例输出 #2

```
6 2 4
```
*/

/* 不知道为什么，用scanf总是出错，用cin输入就没问题 */

#include <algorithm>
// #include <cstdio>
#include <iostream>
using namespace std;

int main() {

    int vec[3];
    // scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
    // getchar();
    char A, B, C;
    // scanf("%c%c%c", &A, &B, &C);

    cin >> vec[0] >> vec[1] >> vec[2] >> A >> B >> C;

    sort(vec, vec + 3);

    printf("%d %d %d", vec[A - 'A'], vec[B - 'A'], vec[C - 'A']);

    return 0;
}