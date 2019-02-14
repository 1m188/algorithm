long Fib(int N, int a, int b)
{
    if (N <= 0)
    {
        return 0;
    }
    else if (N <= 2 && N > 0)
    {
        return a;
    }
    else
    {
        return Fib(N - 1, a + b, a);
    }
}