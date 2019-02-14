#include "stdio.h"
int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n <= 0 || n > 20)
    {
        printf("Error\n");
        return 0;
    }
    else
    {
        for (int i = n; i > 0; i--)
        {
            for (int spacef = 0; spacef < ((2 * n - 1) - (2 * i - 1)) / 2; spacef++)
            {
                printf(" ");
            }
            for (int num = 0; num < 2 * i - 1; num++)
            {
                printf("#");
            }
            for (int spacef = 0; spacef < ((2 * n - 1) - (2 * i - 1)) / 2; spacef++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}