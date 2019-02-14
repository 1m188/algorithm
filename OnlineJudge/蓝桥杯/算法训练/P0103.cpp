/*
　从键盘输入一个大写字母，要求改用小写字母输出。
输入
　　A
输出
　　a
*/

#include "iostream"

int main()
{
    char alphabet = '\0';
    std::cin >> alphabet;

    std::cout << char(alphabet - 'A' + 'a');

    return 0;
}