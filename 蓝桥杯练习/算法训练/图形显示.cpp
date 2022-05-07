/*
问题描述
　　编写一个程序，首先输入一个整数，例如5，然后在屏幕上显示如下的图形（5表示行数）：
　　* * * * *
　　* * * *
　　* * *
　　* *
　　*
*/

#include "iostream"

int main()
{
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            std::cout << '*' << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}