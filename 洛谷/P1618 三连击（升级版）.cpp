/**
 * @file P1618 三连击（升级版）.cpp
 * @date 2022-06-09
 */

/*
# 三连击（升级版）

## 题目描述

将 $1, 2,\ldots, 9$ 共 $9$ 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 $A:B:C$，试求出所有满足条件的三个三位数，若无解，输出 `No!!!`。


//感谢黄小U饮品完善题意

## 输入格式

三个数，$A,B,C$。

## 输出格式

若干行，每行 $3$ 个数字。按照每行第一个数字升序排列。

## 样例 #1

### 样例输入 #1

```
1 2 3
```

### 样例输出 #1

```
192 384 576
219 438 657
273 546 819
327 654 981
```

## 提示

保证 $A<B<C$。
*/

/* 暴力枚举第一个数，之后按照预定比例求出另外两个数，并且验证其每一位的数字是否已被占用 */

#include <cstdio>
using namespace std;

bool flags[10];          // 每位数字是否已被占用
int a = 0, b = 0, c = 0; // 比例
int num[3];              // 第一个数的每一位
bool f = false;          // 是否有结果

/**
 * @brief 递归枚举第一个数的每一位，并且最后计算另外两个数并验证
 * @param x 当前已经枚举了多少位
 */
void calc(int x = 0) {

    if (x == 3) { // 已经枚举三位，计算另外两个数并且验证

        int aa = num[0] * 100 + num[1] * 10 + num[2];
        int bb = double(b) / a * aa;
        int cc = double(c) / a * aa;

        bool tflags[10]; // 将验证数组复制一份，避免后面不合格的时候可以直接返回
        for (int i = 0; i < 10; i++)
            tflags[i] = flags[i];

        for (int tbb = bb; tbb; tbb /= 10) {
            int t = tbb % 10;
            if (t == 0) return; // 注意数位不能为0
            if (!tflags[t])
                tflags[t] = true;
            else
                return;
        }
        for (int tcc = cc; tcc; tcc /= 10) {
            int t = tcc % 10;
            if (t == 0) return;
            if (!tflags[t])
                tflags[t] = true;
            else
                return;
        }

        f = true; // 有结果，如果最后没有结果的话就要输出no
        printf("%d %d %d\n", aa, bb, cc);

        return;
    }

    // 枚举第一个数的每一位
    for (int i = 1; i <= 9; i++) {
        if (!flags[i]) {
            flags[i] = true;
            num[x] = i;
            calc(x + 1);
            flags[i] = false;
        }
    }
}

int main() {

    scanf("%d %d %d", &a, &b, &c);

    // 初始化验证数组
    for (int i = 0; i < 10; i++)
        flags[i] = false;

    calc();

    if (!f) printf("No!!!");

    return 0;
}