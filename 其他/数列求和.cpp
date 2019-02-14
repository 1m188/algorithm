//数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

#include "cmath"

double sumAdd(double n, int m)
{
    if (n <= 0 || m == 0)
    {
        return 0;
    }
    else
    {
        return n + sumAdd(pow(n, 0.5), m - 1);
    }
}