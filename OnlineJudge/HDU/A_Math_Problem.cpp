/*
Description
You are given a positive integer n, please count how many positive integers k satisfy kk≤n.

Input
There are no more than 50 test cases.

Each case only contains a positivse integer n in a line.

1≤n≤1018

Output
For each test case, output an integer indicates the number of positive integers k satisfy kk≤n in a line.

Sample Input
1
4

Sample Output
1
2
*/

#include "cstdio"

long long QPow(long long k, long long n); //快速幂

int main() //k肯定是小于等于15的，可以遍历
{
    long long n = 0;
    while (scanf("%lld", &n) != EOF)
    {
        for (int k = 15; k >= 1; k--)
        {
            if (QPow(k, k) <= n)
            {
                printf("%d\n", k);
                break;
            }
        }
    }

    return 0;
}

long long QPow(long long k, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res *= k;
        }
        k *= k;
        n >>= 1;
    }
    return res;
}