/**
 * @file L1-084 拯救外星人.cpp
 * @date 2022-05-21
 */

/*
T.jpg
你的外星人朋友不认得地球上的加减乘除符号，但是会算阶乘 —— 正整数 N 的阶乘记为 “N!”，是从 1 到 N 的连乘积。所以当他不知道“5+7”等于多少时，如果你告诉他等于“12!”，他就写出了“479001600”这个答案。

本题就请你写程序模仿外星人的行为。

输入格式：
输入在一行中给出两个正整数 A 和 B。

输出格式：
在一行中输出 (A+B) 的阶乘。题目保证 (A+B) 的值小于 12。

输入样例：
3 6
输出样例：
362880
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
using namespace std;

/**
 * @brief 递归计算阶乘
 * @param a 计算a!
 * @return int 结果
 */
int fact(int a) {
    return a <= 0 ? 1 : a * fact(a - 1);
}

int main() {

    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d", fact(a + b));

    return 0;
}