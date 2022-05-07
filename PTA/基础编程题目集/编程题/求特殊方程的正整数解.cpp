/*
7-21 求特殊方程的正整数解 （15 分）
本题要求对任意给定的正整数N，求方程X
​2
​​ +Y
​2
​​ =N的全部正整数解。

输入格式：

输入在一行中给出正整数N（≤10000）。

输出格式：

输出方程X
​2
​​ +Y
​2
​​ =N的全部正整数解，其中X≤Y。每组解占1行，两数字间以1空格分隔，按X的递增顺序输出。如果没有解，则输出No Solution。

输入样例1：

884
输出样例1：

10 28
20 22
输入样例2：

11
输出样例2：

No Solution
*/

#include "cstdio"
#include "cmath"

int main()
{
    int N = 0;
    scanf("%d", &N);

    bool isSolution = false;
    int sq = sqrt(N / 2);         //这里用/2后的开方是为了避免重复的问题
    for (int X = 1; X <= sq; X++) //这里通过判断余下的差是否是完全平方数来判定是否存在解
    {
        double sqq = sqrt(N - X * X);
        //这里判断整数
        if (int(sqq) == sqq)
        {
            isSolution = true;
            printf("%d %d\n", X, int(sqq));
        }
    }
    if (!isSolution)
    {
        printf("No Solution");
    }

    return 0;
}