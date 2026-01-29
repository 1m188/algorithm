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

/* 原来如此，在洛谷的oj系统里，回车是两个字符，或许是"\r\n"？不太清楚，
这种换行符似乎都在Windows里，而一般oj里面应该用的是Linux啊？不太明白
这其中的联系，但只要在scanf读入数字后面加入两个getchar就没问题了，
或者直接后面读入字符的时候%c前面加空格，忽略掉之前所有的空白字符 */

#include <algorithm>
#include <cstdio>
using namespace std;

int main() {

    int vec[3];
    scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
    // getchar(); // 如果后面scanf里面%c前面不加空格的话，需要两个getchar，吃掉换行符，避免读入换行
    // getchar();
    char A, B, C;
    scanf(" %c%c%c", &A, &B, &C); // 注意%c前面的空格，忽略前面所有的空白字符

    sort(vec, vec + 3);

    printf("%d %d %d", vec[A - 'A'], vec[B - 'A'], vec[C - 'A']);

    return 0;
}