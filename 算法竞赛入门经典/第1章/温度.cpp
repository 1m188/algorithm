#include "stdio.h"
int main()
{
    int f = 0;
    double c = 0;
    scanf("%d", &f);
    c = 5 * (f - 32) / 9.0;
    printf("%.3f\n", c);

    return 0;
}