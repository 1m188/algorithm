/**
 * @file P5712 【深基3.例4】Apples.cpp
 * @date 2022-06-23
 */

/*
# 【深基3.例4】Apples

## 题目描述

八尾勇喜欢吃苹果。她今天吃掉了 $x(0\le x \le 100)$ 个苹果。英语课上学到了 apple 这个词语，想用它来造句。如果她吃了 1 个苹果，就输出 `Today, I ate 1 apple.`；如果她没有吃，那么就把 1 换成 0；如果她吃了不止一个苹果，别忘了 `apple` 这个单词后面要加上代表复数的 `s`。你能帮她完成这个句子吗？

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
1
```

### 样例输出 #1

```
Today, I ate 1 apple.
```

## 样例 #2

### 样例输入 #2

```
3
```

### 样例输出 #2

```
Today, I ate 3 apples.
```
*/

#include <cstdio>
using namespace std;

int main() {
    int x = 0;
    scanf("%d", &x);
    if (x <= 1)
        printf("Today, I ate %d apple.", x);
    else
        printf("Today, I ate %d apples.", x);
    return 0;
}