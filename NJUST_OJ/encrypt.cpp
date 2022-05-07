/*
Description
将一段明文加密。加密的规则如下：将每个字符的ascii码的值减去24作为每个字符加密后的值，例如'a'的ascii码的值为97，那么加密后就变成了73。"73"就是'a'的密文。现在请你编写程序，对一段文字加密。请定义并使用如下函数： 
void encrypt(char *plain, char *cipher) 
{
    //把原文字符串plain加密后存入字符串cipher 
}

Input
第一行输入一个t，代表t组数据，接下来输入一串字符串，只包含数字和字母，最长为200.

Output
输出加密后的字符串。

Sample Input
2
a
zero12

Sample Output
73
987790872526
*/

#include "cstdio"
#include "cstring"

void encrypt(char *plain, char *cipher)
{
    for (int i = 0; plain[i] != '\0'; i++)
    {
        int tempNum = plain[i] - 24; //加密转换
        char *tempStr = new char[3]{};
        sprintf(tempStr, "%d", tempNum); //格式化字符串，把int变成str
        strcat(cipher, tempStr);         //这个地方似乎用不了strcat_s，不知道为什么...
        delete[] tempStr;
    }
}

int main() //PE...又不清楚了...
{
    int t = 0;
    scanf("%d", &t);
    char **str = new char *[t] {};
    for (int i = 0; i < t; i++)
    {
        str[i] = new char[200]{}; //处理输入
        scanf("%s", str[i]);
    }

    for (int i = 0; i < t; i++)
    {
        char *cipher = new char[600]{};
        encrypt(str[i], cipher); //调用关键函数
        printf("%s\n", cipher);
        delete[] cipher; //释放内存，防止泄漏
        delete[] str[i];
    }

    return 0;
}