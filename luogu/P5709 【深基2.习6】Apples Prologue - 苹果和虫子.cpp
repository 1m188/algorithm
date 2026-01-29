/**
 * @file P5709 【深基2.习6】Apples Prologue - 苹果和虫子.cpp
 * @date 2022-06-11
 */

/*
# 【深基2.习6】Apples Prologue / 苹果和虫子

## 题目描述

八尾勇喜欢吃苹果。她现在有 $m$（$1 \le m \le 100$）个苹果，吃完一个苹果需要花费 $t$（$0 \le t \le 100$）分钟，吃完一个后立刻开始吃下一个。现在时间过去了 $s$（$1 \le s \le 10000$）分钟，请问她还有几个完整的苹果？

## 输入格式

输入三个**非负整数**表示 $m, t, s$。

## 输出格式

输出一个整数表示答案。

如果你出现了 RE，不如检查一下被零除？

## 样例 #1

### 样例输入 #1

```
50 10 200
```

### 样例输出 #1

```
30
```
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int m = 0, t = 0, s = 0;
    scanf("%d %d %d", &m, &t, &s);
    if (t == 0) {
        printf("0");
    } else if (s % t == 0) {
        printf("%d", max(m - s / t, 0)); // 正好吃完
    } else {
        printf("%d", max(m - s / t - 1, 0)); // 正好吃完
    }
    return 0;
}