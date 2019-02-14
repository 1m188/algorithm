#include "stdio.h"
int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Error\n");
    }
    else if (a + b > c && b + c > a && c + a > b)
    {
        if (a ^ 2 + b ^ 2 == c ^ 2 || a ^ 2 + c ^ 2 == b ^ 2 || b ^ 2 + c ^ 2 == a ^ 2)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    else
    {
        printf("not a triangle\n");
    }

    return 0;
}