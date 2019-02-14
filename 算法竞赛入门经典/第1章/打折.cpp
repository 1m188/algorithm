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
        if (95 * n >= 300)
        {
            printf("%.2f\n", 95 * n * 0.85);
        }
        else
        {
            printf("%.2f\n", 95.0 * n);
        }
    }

    return 0;
}