/*

快速幂

*/

#include "iostream"

int64_t quickpow(int64_t n, uint p)
{
    if (p == 0)
        return 1;
    else if (p == 1)
        return n;
    else
    {
        uint pp = p / 2;
        int ppn = quickpow(n, pp);
        return p % 2 ? ppn * ppn * n : ppn * ppn;
    }
}

int main(int argc, char *aargv[])
{
    std::cout << quickpow(3, 18) << '\n'
              << quickpow(5, 5) << '\n'
              << quickpow(-2, 9) << '\n';

    return 0;
}