#include "stdio.h"
#include "string.h"
int main()
{
    char s[100]{};
    scanf("%s", s);
    int num = 0;
    int score = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'X')
        {
            num = 0;
        }
        else if (s[i] == 'O')
        {
            num++;
            score += num;
        }
    }
    printf("%d\n", score);

    return 0;
}