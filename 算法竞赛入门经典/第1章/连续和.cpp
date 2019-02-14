#include "stdio.h"
int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Error\n");
        return 0;
    }
    else
    {
        printf("%d\n", n * (n + 1) / 2);
    }

    return 0;
}