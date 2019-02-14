/*
问题描述
　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
FFFF
样例输出
65535
*/

#include "iostream"
#include "string"
#include "cmath"

int main()
{
    std::string s;
    std::cin >> s;

    int size = s.size();
    unsigned int num = 0; //注意类型，避免溢出
    for (int i = size - 1; i >= 0; i--)
    {
        int n = 0;
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = s[i] - '0';
        }
        else
        {
            n = s[i] - 'A' + 10;
        }
        num += n * pow(16, size - i - 1);
    }

    std::cout << num;

    return 0;
}