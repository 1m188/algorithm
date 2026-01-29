/**
 * @file P1036 [NOIP2002 普及组] 选数.cpp
 * @date 2022-06-09
 */

/*
# [NOIP2002 普及组] 选数

## 题目描述

已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$ 个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：

$3+7+12=22$

$3+7+19=29$

$7+12+19=38$

$3+12+19=34$

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：$3+7+19=29$。

## 输入格式

第一行两个空格隔开的整数 $n,k$（$1 \le n \le 20$，$k<n$）。

第二行 $n$ 个整数，分别为 $x_1,x_2,\cdots,x_n$（$1 \le x_i \le 5\times 10^6$）。

## 输出格式

输出一个整数，表示种类数。

## 样例 #1

### 样例输入 #1

```
4 3
3 7 12 19
```

### 样例输出 #1

```
1
```

## 提示

**【题目来源】**

NOIP 2002 普及组第二题
*/

/* 暴力枚举组合，之后判断是否是质数 */

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;    // 待选的数
int n = 0,          // 总共多少数
    k = 0;          // 选多少数
vector<bool> flags; // 该数是否被选过
int sum = 0;        // 选数之和
int ans = 0;        // 最终结果

/**
 * @brief 判断是否是素数？
 * @param x 
 * @return true 
 * @return false 
 */
bool is_prime(int x) {
    if (x <= 2) return true;
    if (x % 2 == 0) return false;
    double a = sqrt(x);
    for (int i = 3; i <= a; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

/**
 * @brief 递归选数，并验算
 * @param cnt 已经选了几个数
 * @param idx 当前从哪个索引开始选数
 */
void calc(int cnt = 0, int idx = 0) {
    if (cnt == k) {
        ans += is_prime(sum);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!flags[i]) {
            flags[i] = true;
            sum += vec[i];
            calc(cnt + 1, i + 1);
            sum -= vec[i];
            flags[i] = false;
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);
    vec.resize(n);
    flags.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    calc();
    printf("%d", ans);

    return 0;
}