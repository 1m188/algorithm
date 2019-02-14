#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main()
{
    char s[100]{};
    scanf("%s", s);
    int length = strlen(s);
    double formula = 0.0;
    double temp = 0.0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'C')
        {
            temp = 12.01;
        }
        else if (s[i] == 'H')
        {
            temp = 1.008;
        }
        else if (s[i] == 'O')
        {
            temp = 16.00;
        }
        else if (s[i] == 'N')
        {
            temp = 14.01;
        }
        else
        {
            continue;
        }
        if (s[i + 1] != '\0')
        {
            if (isdigit(s[i + 1]))
            {
                temp *= s[i + 1] - '0';
            }
        }
        formula += temp;
    }
    printf("%lgg/mol\n", formula);

    return 0;
}