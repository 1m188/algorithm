/**
 * @file 7-4 关于奇数的等式.cpp
 * @date 2022-05-20
 */

/*
给定任一正奇数 n>3 和一个解的上界 m>3，求三个正奇数 x、y、z，满足 0<x<y<z≤m 且有等式 3/n=1/x+1/y+1/z。

输入格式：
输入给出正奇数 3<n<400 和解的上界 m≤1000。

输出格式：
在一行中输出给定范围内最小的一组解 x y z（即存在多组解时取最小的 x，并列时取最小的 y）。数字间以 1 个空格分隔，行首尾不得有多余空格。

如果给定范围内无解，则输出 No solution in (3, m]. 其中 m 是给定的上界。

输入样例 1：
27 500
输出样例 1：
11 55 495
输入样例 2：
27 50
输出样例 2：
No solution in (3, 50].
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cmath>
#include <cstdio>
using namespace std;

#define point 1e-9 /* 注意精度！！！ */

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    double ans = 3.0 / n;

    for (int x = 1; x <= m; x += 2)
        for (int y = x % 2 ? x + 2 : x + 1; y <= m; y += 2)
            for (int z = y % 2 ? y + 2 : y + 1; z <= m; z += 2) {
                if (abs(ans - 1.0 / x - 1.0 / y - 1.0 / z) < point) {
                    printf("%d %d %d", x, y, z);
                    return 0;
                }
            }
    printf("No solution in (3, %d].", m);

    return 0;
}