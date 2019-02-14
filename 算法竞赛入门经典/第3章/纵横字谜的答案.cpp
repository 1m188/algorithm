#include "stdio.h"

void Answer(char **word, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((word[i][j] != '*' && j - 1 < 0) || (word[i][j] != '*' && word[i][j - 1] == '*'))
            {
                for (int k = j; k < c; k++)
                {
                    if (word[i][k] != '*')
                    {
                        printf("%c", word[i][k]);
                    }
                    else
                    {
                        break;
                    }
                }
                printf("\n");
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((word[i][j] != '*' && i - 1 < 0) || (word[i][j] != '*' && word[i - 1][j] == '*'))
            {
                for (int k = i; k < r; k++)
                {
                    if (word[k][j] != '*')
                    {
                        printf("%c", word[k][j]);
                    }
                    else
                    {
                        break;
                    }
                }
                printf("\n");
            }
        }
    }
}