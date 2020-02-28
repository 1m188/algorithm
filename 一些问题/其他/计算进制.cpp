//转换各种进制

#include "cmath"

int two2ten(int sum) //二进制转十进制
{
    int newsum = 0;

    for (int i = 0;; i++)
    {
        if (sum / pow(10, i) < 1)
        {
            return newsum;
        }
        else
        {
            newsum += static_cast<int>(sum / pow(10, i)) % 10 * pow(2, i);
        }
    }

    return newsum;
}