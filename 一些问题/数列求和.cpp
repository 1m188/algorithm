/*

数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

*/

#include "cmath"
#include "iostream"

double sumAdd(double n, int m)
{
    return n <= 0 || m == 0 ? 0 : n + sumAdd(pow(n, 0.5), m - 1);
}

double sumAddnr(double n, int m) // 无递归
{
    if (n <= 0 || m == 0)
        return 0;

    double t = n;
    m--;
    while (m--)
        n += t = pow(t, 0.5);
    return n;
}

int main(int argc, char *argv[])
{
    std::cout << sumAdd(81, 3) << '\n'
              << sumAddnr(81, 3) << '\n';

    return 0;
}