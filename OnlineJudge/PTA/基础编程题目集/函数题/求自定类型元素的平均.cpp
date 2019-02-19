/*
6-4 求自定类型元素的平均 （10 分）
本题要求实现一个函数，求N个集合元素S[]的平均值，其中集合元素的类型为自定义的ElementType。

函数接口定义：

ElementType Average( ElementType S[], int N );
其中给定集合元素存放在数组S[]中，正整数N是数组元素个数。该函数须返回N个S[]元素的平均值，其值也必须是ElementType类型。

裁判测试程序样例：

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Average( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

你的代码将被嵌在这里

输入样例：

3
12.3 34 -5
输出样例：

13.77
*/

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Average(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

ElementType Average(ElementType S[], int N)
{
    ElementType average = 0;
    for (int i = 0; i < N; i++)
    {
        average += S[i];
    }
    average /= N;
    return average;
}