/*
6-2 多项式求值 （15 分）
本题要求实现一个函数，计算阶数为n，系数为a[0] ... a[n]的多项式f(x)=∑
​i=0
​n
​​ (a[i]×x
​i
​​ ) 在x点的值。

函数接口定义：

double f( int n, double a[], double x );
其中n是多项式的阶数，a[]中存储系数，x是给定点。函数须返回多项式f(x)的值。

裁判测试程序样例：

#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf(“%lf”, &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

 你的代码将被嵌在这里 
输入样例：

2 1.1
1 2.5 -38.7
输出样例：

-43.1
*/

#include <stdio.h>

#define MAXN 10

double f(int n, double a[], double x);

int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for (i = 0; i <= n; i++)
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

#include "math.h"
double f(int n, double a[], double x)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        //这里的pow函数怕是用了快速幂算法优化了
        result += a[i] * pow(x, i);
    }
    return result;
}