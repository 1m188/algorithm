/*
6-8 简单阶乘计算 （10 分）
本题要求实现一个计算非负整数阶乘的简单函数。

函数接口定义：

int Factorial( const int N );
其中N是用户传入的参数，其值不超过12。如果N是非负整数，则该函数必须返回N的阶乘，否则返回0。

裁判测试程序样例：

#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

你的代码将被嵌在这里

输入样例：

5
输出样例：

5! = 120
*/

#include <stdio.h>

int Factorial(const int N);

int main()
{
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)
        printf("%d! = %d\n", N, NF);
    else
        printf("Invalid input\n");

    return 0;
}

int Factorial(const int N)
{
    if (N < 0)
    {
        return 0;
    }
    else if (N == 0)
    {
        return 1;
    }
    else
    {
        return N * Factorial(N - 1);
    }
}