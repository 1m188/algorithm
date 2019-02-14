#include "stdio.h"
int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    printf("%.3f\n", (a + b + c) / 3.0);

    return 0;
}