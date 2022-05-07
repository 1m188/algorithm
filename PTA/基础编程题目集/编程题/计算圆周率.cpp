/*
7-15 计算圆周率 （15 分）
根据下面关系式，求圆周率的值，直到最后一项的值小于给定阈值。

​2
​
​π
​​ =1+
​3
​
​1
​​ +
​3×5
​
​2!
​​ +
​3×5×7
​
​3!
​​ +⋯+
​3×5×7×⋯×(2n+1)
​
​n!
​​ +⋯

输入格式：

输入在一行中给出小于1的阈值。

输出格式：

在一行中输出满足阈值条件的近似圆周率，输出到小数点后6位。

输入样例：

0.01
输出样例：

3.132157
*/

/*
别人总结的，我也是看了这个最后才写出来

这道题看似简单，实则有大坑，首先你不能是计算好整型再转换，这里又有个坑，如果你要写整型，
那么必须是long long，否则过不了几个测试点，其次如果你是long long类型，那么转换成double，就会出问题，
因为当数值超大时，double是无法全部转换long long的，它会转换为负数。。所以你既不能是普通整型，又不能
用double转换大数值，那么你只有一开始计算的时候都是用double来计算。
*/

#include "cstdio"

double threshold = 0;

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

double calc(int n = 0, double molecular = 1, double denominator = 1)
{
    double newMolecular = molecular;
    if (n > 1)
    {
        newMolecular *= n;
    }
    double newDenominator = denominator * (2 * n + 1);
    int g = gcd(newMolecular, newDenominator);
    newMolecular /= g, newDenominator /= g;
    double value = newMolecular / newDenominator;
    if (value < threshold)
    {
        return value;
    }
    else
    {
        return value + calc(n + 1, newMolecular, newDenominator);
    }
}

int main()
{
    scanf("%lf", &threshold);

    printf("%.6f", calc() * 2);

    return 0;
}