/*

斐波那契

*/

#include "iostream"

// 递归
unsigned long long Fib_recur(unsigned long long N)
{
    return N <= 1 ? 1 : Fib_recur(N - 1) + Fib_recur(N - 2);
}

// 尾递归
unsigned long long Fib_tailRecur(unsigned long long N, unsigned long long a = 1, unsigned long long b = 1)
{
    return N <= 1 ? a : Fib_tailRecur(N - 1, a + b, a);
}

// 循环
unsigned long long Fib_c(unsigned long long N)
{
    if (N <= 1)
        return 1;

    unsigned long long Answer = 0;
    unsigned long long Last = 1, NextToLast = 1;
    for (unsigned long long i = 2; i <= N; i++)
    {
        Answer = Last + NextToLast;
        NextToLast = Last;
        Last = Answer;
    }

    return Answer;
}

int main(int argc, char *argv[])
{
    // 0代表第一项，1代表第二项...以此类推

    const int n = 5;

    std::cout << "fib " << n << std::endl
              << "recur: " << Fib_recur(n) << std::endl
              << "tailRecur: " << Fib_tailRecur(n) << std::endl
              << "c: " << Fib_c(n) << std::endl;

    return 0;
}