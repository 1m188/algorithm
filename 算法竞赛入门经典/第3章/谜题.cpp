#include "stdio.h"

void Puzzle(char inter[5][5], char *s)
{
    int x = 0, y = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (inter[i][j] == '0')
            {
                x = i;
                y = j;
                goto outside;
            }
        }
    }
outside:
    for (int i = 0; s[i] != '0'; i++)
    {
        if ((s[i] == 'A' && x == 0) || (s[i] == 'B' && x == 4) || (s[i] == 'L' && y == 0) || (s[i] == 'R' && y == 4))
        {
            printf("This puzzle has no final configuration\n");
            return;
        }
        else if (s[i] == 'A')
        {
            inter[x][y] = inter[x - 1][y];
            inter[x - 1][y] = '0';
            x--;
        }
        else if (s[i] == 'B')
        {
            inter[x][y] = inter[x + 1][y];
            inter[x + 1][y] = '0';
            x++;
        }
        else if (s[i] == 'L')
        {
            inter[x][y] = inter[x][y - 1];
            inter[x][y - 1] = '0';
            y--;
        }
        else if (s[i] == 'R')
        {
            inter[x][y] = inter[x][y + 1];
            inter[x][y + 1] = '0';
            y++;
        }
        else
        {
            printf("This puzzle has no final configuration\n");
            return;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (inter[i][j] == '0')
            {
                printf(" \t");
            }
            else
            {
                printf("%c\t", inter[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    char inter[5][5]{{'T', 'R', 'G', 'S', 'J'}, {'X', 'D', 'O', 'K', 'I'}, {'M', '0', 'V', 'L', 'N'}, {'W', 'P', 'A', 'B', 'E'}, {'U', 'Q', 'H', 'C', 'F'}};
    char s[]{"ARRBBL0"};
    Puzzle(inter, s);

    return 0;
}