/*
7-35 有理数均值 （20 分）
本题要求编写程序，计算N个有理数的平均值。

输入格式：

输入第一行给出正整数N（≤100）；第二行中按照a1/b1 a2/b2 …的格式给出N个分数形式的有理数，其中分子和分母全是整形范围内的整数；如果是负数，则负号一定出现在最前面。

输出格式：

在一行中按照a/b的格式输出N个有理数的平均值。注意必须是该有理数的最简分数形式，若分母为1，则只输出分子。

输入样例1：

4
1/2 1/6 3/6 -5/10
输出样例1：

1/6
输入样例2：

2
4/3 2/3
输出样例2：

1
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
    int N = 0;
    scanf("%d", &N);

    //求和
    int a = 0, b = 1;
    for (int i = 0; i < N; i++)
    {
        int at = 0, bt = 0;
        scanf("%d/%d", &at, &bt);
        a = a * bt + at * b;
        b *= bt;
        int g = gcd(a, b);
        a /= g, b /= g;
    }

    //求平均
    b *= N;
    int g = gcd(a, b);
    a /= g, b /= g;

    //输出
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