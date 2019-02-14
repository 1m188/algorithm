long Fib(int N)
{
    if (N <= 1)
    {
        return 1;
    }
    else
    {
        return Fib(N - 1) + Fib(N - 2);
    }
}