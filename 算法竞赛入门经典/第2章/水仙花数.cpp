#include "stdio.h"
#include "math.h"
int main()
{
    for (int i = 100; i <= 999; i++)
    {
        if (i == pow(i / 100 % 10, 3) + pow(i / 10 % 10, 3) + pow(i % 10, 3))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}