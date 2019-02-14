#include "stdio.h"
int main()
{
    FILE *fin;
    fin = fopen("hanxin.txt", "rb");
    int a = 0, b = 0, c = 0;
    for (int Case = 1;; Case++)
    {
        if (feof(fin))
        {
            break;
        }
        fscanf(fin, "%d", &a);
        fscanf(fin, "%d", &b);
        fscanf(fin, "%d", &c);
        for (int i = 10; i <= 100; i++)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                printf("Case %d: %d\n", Case, i);
                goto next;
            }
        }
        printf("Case %d: No answer\n", Case);
    next:;
    }
    fclose(fin);

    return 0;
}