//改正错误，程序意图统计字符串中字符1的个数

#include "stdio.h"
#include "string.h" //没有包含string.h文件导致strlen函数不能够使用，从而程序无法通过编译
#define maxn 10000000 + 10
int main()
{
    char s[maxn];
    scanf("%s", s);
    int tot = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++) //将strlen函数放在判断条件之中，每一次判断条件都要使用一次strlen函数，导致效率低下，使用外部变量保存调用即可
    {
        if (s[i] == '1') //==1中1是一个数字，不是‘1’这种字符，因此判断出来只是ASSCI码为1的字母，而非‘1’
        {
            tot++;
        }
    }
    printf("%d\n", tot);
}