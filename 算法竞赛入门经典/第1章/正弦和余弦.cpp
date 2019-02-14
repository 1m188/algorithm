#include "math.h"
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
        printf("%f\n", sin(n));
        printf("%f\n", cos(n));
    }

    return 0;
}