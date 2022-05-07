/*
7-33 有理数加法 （15 分）
本题要求编写程序，计算两个有理数的和。

输入格式：

输入在一行中按照a1/b1 a2/b2的格式给出两个分数形式的有理数，其中分子和分母全是整形范围内的正整数。

输出格式：

在一行中按照a/b的格式输出两个有理数的和。注意必须是该有理数的最简分数形式，若分母为1，则只输出分子。

输入样例1：

1/3 1/6
输出样例1：

1/2
输入样例2：

4/3 2/3
输出样例2：

2
*/

#include "cstdio"

int gcd(int a, int b)
{
    int c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    int a = a1 * b2 + a2 * b1, b = b1 * b2;
    int g = gcd(a, b);
    a /= g, b /= g;

    if (b != 1)
    {
        printf("%d/%d", a, b);
    }
    else
    {
        printf("%d", a);
    }

    return 0;
}