/*
Description
某数列a[]满足，a[0]=1，a[1]=1，a[n]=a[0]+a[1]+...+a[n-1]，现在让你求第n项是什么？(本题用函数递归调用做,数列为等比数列)

Input
第一行输入一个t, 表示有t组数据，然后每行输入一个正整数n（1<=n<=30）

Output
输出第n项

Sample Input
3
2
3
4

Sample Output
2
4
8
*/

#include "cstdio"

int Fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            num += Fib(i); //递归
        }
        return num;
    }
}

int main() //TLE...明明题目里没写时间要求居然还有超时...
{
    int t = 0;
    scanf("%d", &t);
    int *a = new int[t]{};
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d", Fib(a[i]));
        if (i != t - 1)
        {
            printf("\n");
        }
    }

    return 0;
}