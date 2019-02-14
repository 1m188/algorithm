/*
问题描述
对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：

00000

00001

00010

00011

00100

请按从小到大的顺序输出这32种01串。

输入格式
本试题没有输入。
输出格式
输出32行，按从小到大的顺序每行一个长度为5的01串。
样例输出
00000
00001
00010
00011
<以下部分省略>
*/

#include "iostream"
#include "string"

std::string str;

//递归，对字符串的每一个位进行枚举，并输出每个字符串
void printStr(int bit = 0)
{
    if (bit <= 4)
    {
        for (int i = 0; i <= 1; i++)
        {
            str[bit] = i + '0';
            printStr(bit + 1);
        }
    }
    else
    {
        std::cout << str << std::endl;
    }
}

int main()
{
    str.resize(5);
    printStr();

    return 0;
}