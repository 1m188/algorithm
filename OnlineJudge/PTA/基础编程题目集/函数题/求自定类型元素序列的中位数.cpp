/*
6-11 求自定类型元素序列的中位数 （25 分）
本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第⌊N/2+1⌋大的元素。其中集合元素的类型为自定义的ElementType。

函数接口定义：

ElementType Median( ElementType A[], int N );
其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。

裁判测试程序样例：

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

你的代码将被嵌在这里

输入样例：

3
12.3 34 -5
输出样例：

12.30
*/

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

ElementType Median(ElementType A[], int N)
{
    //希尔排序，别人的思路，没看太懂...
    //大概是不断地分组，每组中对应的数据从小到大排列吧...(?)
    for (int i = N / 2; i > 0; i /= 2)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = j - i; k >= 0 && A[k] > A[k + i]; k -= i)
            {
                ElementType t = A[k];
                A[k] = A[k + i];
                A[k + i] = t;
            }
        }
    }

    return A[N / 2];
}