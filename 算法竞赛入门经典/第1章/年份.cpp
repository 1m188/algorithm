#include "stdio.h"
int main()
{
    int year = 0;
    scanf("%d", &year);
    if (year <= 0)
    {
        printf("Error\n");
    }
    else
    {
        if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) || (year > 3200 && year % 3200 == 0 && year % 172800 == 0))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}