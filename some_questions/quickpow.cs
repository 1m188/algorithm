/*

基于 C# 实现的快速幂算法

*/

using System.Diagnostics;

static long quickpow(long x, ulong n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    return quickpow(x * x, n / 2) * ((n & 0x1) == 1 ? x : 1);
}

Trace.Assert(quickpow(2, 0) == 1);
Trace.Assert(quickpow(2, 1) == 2);
Trace.Assert(quickpow(2, 10) == 1024);
Trace.Assert(quickpow(-2, 10) == 1024);
Trace.Assert(quickpow(-2, 9) == -512);

Console.WriteLine("All tests passed!");
