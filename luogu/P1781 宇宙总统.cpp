/**
 * @file P1781 宇宙总统.cpp
 * @date 2022-06-05
 */

/*
# 宇宙总统

## 题目描述

地球历公元 6036 年，全宇宙准备竞选一个最贤能的人当总统，共有 $n$ 个非凡拔尖的人竞选总统，现在票数已经统计完毕，请你算出谁能够当上总统。

## 输入格式

第一行为一个整数 $n$，代表竞选总统的人数。

接下来有 $n$ 行，分别为第一个候选人到第 $n$ 个候选人的票数。

## 输出格式

共两行，第一行是一个整数 $m$，为当上总统的人的号数。

第二行是当上总统的人的选票。

## 样例 #1

### 样例输入 #1

```
5
98765
12365
87954
1022356
985678
```

### 样例输出 #1

```
4
1022356
```

## 提示

票数可能会很大，可能会到 $100$ 位数字。

$1 \leq n \leq 20$
*/

/* 注意字符串数字的比较大小 */

/* 感觉在洛谷的oj系统里getchar总有点问题 */

/* 明白了，原来洛谷里的回车有两个字符，如果要吃掉回车，必须使用getchar连续两次，
而不是普通的一次，或者使用scanf自带的某些去除空白字符的功能 */

#include <cstdio>
#include <string>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);

    int num = 0;
    string points;

    for (int i = 1; i <= n; i++) {
        string s(100, '\0');
        scanf("%s", &s[0]);
        for (int i = 0; i < 100; i++) {
            if (s[i] == '\0') {
                s.resize(i);
                break;
            }
        }

        // 注意字符串数字比较大小
        if (s.size() > points.size() || (s.size() == points.size() && s > points)) {
            points = s;
            num = i;
        }
    }

    printf("%d\n%s", num, points.c_str());

    return 0;
}