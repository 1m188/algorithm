/**
 * @file P1149 [NOIP2008 提高组] 火柴棒等式.cpp
 * @date 2022-06-06
 */

/*
# [NOIP2008 提高组] 火柴棒等式

## 题目描述

给你n根火柴棍，你可以拼出多少个形如“$A+B=C$”的等式？等式中的$A$、$B$、$C$是用火柴棍拼出的整数（若该数非零，则最高位不能是$0$）。用火柴棍拼数字$0-9$的拼法如图所示：

 ![](https://cdn.luogu.com.cn/upload/pic/49.png) 

注意：

1. 加号与等号各自需要两根火柴棍

2. 如果$A≠B$，则$A+B=C$与$B+A=C$视为不同的等式($A,B,C>=0$)

3. $n$根火柴棍必须全部用上

## 输入格式

一个整数$n(n<=24)$。

## 输出格式

一个整数，能拼成的不同等式的数目。

## 样例 #1

### 样例输入 #1

```
14
```

### 样例输出 #1

```
2
```

## 样例 #2

### 样例输入 #2

```
18
```

### 样例输出 #2

```
9
```

## 提示

【输入输出样例1解释】

$2$个等式为$0+1=1$和$1+0=1$。

【输入输出样例2解释】

$9$个等式为：

```cpp
0+4=4
0+11=11
1+10=11
2+2=4
2+7=9
4+0=4
7+2=9
10+1=11
11+0=11
```
*/

/* 暴力搜索

但要注意尽量的剪枝

事先求出1000以内所有数字的火柴个数，然后穷举 */

#include <cstdio>
#include <vector>
using namespace std;

// 这里是打表做的
vector<int> nums = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6,
                    8, 4, 7, 7, 6, 7, 8, 5, 9, 8, 11, 7, 10, 10, 9, 10, 11, 8, 12, 11, 11, 7, 10, 10, 9, 10, 11, 8, 12, 11, 10, 6, 9, 9, 8, 9, 10, 7, 11, 10, 11, 7, 10, 10, 9, 10, 11, 8, 12, 11, 12, 8, 11, 11, 10, 11, 12, 9, 13, 12, 9, 5, 8, 8, 7, 8, 9, 6, 10, 9, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 12, 8, 11, 11, 10, 11, 12, 9, 13, 12, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 10, 6, 9, 9, 8, 9, 10, 7, 11, 10, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 12, 8, 11, 11, 10, 11, 12, 9, 13, 12, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 11, 7, 10, 10, 9, 10, 11, 8, 12, 11, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 12, 8, 11, 11, 10, 11, 12, 9, 13, 12, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 19, 15, 18, 18, 17, 18, 19, 16, 20, 19, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 11, 7, 10, 10, 9, 10, 11, 8, 12, 11, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 13, 9, 12, 12, 11, 12, 13, 10, 14, 13, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 12, 8, 11, 11, 10, 11, 12, 9, 13, 12, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 19, 15, 18, 18, 17, 18, 19, 16, 20, 19, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 19, 15, 18, 18, 17, 18, 19, 16, 20, 19, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 20, 16, 19, 19, 18, 19, 20, 17, 21, 20, 19, 15, 18, 18, 17, 18, 19, 16, 20, 19, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 14, 10, 13, 13, 12, 13, 14, 11, 15, 14, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 16, 12, 15, 15, 14, 15, 16, 13, 17, 16, 17, 13, 16, 16, 15, 16, 17, 14, 18, 17, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18, 15, 11, 14, 14, 13, 14, 15, 12, 16, 15, 19, 15, 18, 18, 17, 18, 19, 16, 20, 19, 18, 14, 17, 17, 16, 17, 18, 15, 19, 18};

/**
 * @brief 打表求1000以内的所有数字火柴数
 */
void table() {
    vector<int> vec = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 10; i < 1000; i++) {
        int num = 0;
        for (int t = i; t; t /= 10)
            num += vec[t % 10];
        printf("%d,", num);
    }
}

/**
 * @brief 计算
 * @param n 
 * @return int 
 */
int calc(int n) {
    if (n <= 0) return 0;

    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            // 这里要注意，没有用三重循环，下面这个i+j已经暗含了两个数字相加相等的情况了
            if (i + j >= nums.size()) break;
            if (nums[i] + nums[j] + nums[i + j] == n)
                cnt++;
        }
    }

    return cnt;
}

int main() {

    // table();

    int n = 0;
    scanf("%d", &n);
    printf("%d", calc(n - 4));

    return 0;
}