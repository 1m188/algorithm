/*
7-31 字符串循环左移 （20 分）
输入一个字符串和一个非负整数N，要求将字符串循环左移N次。

输入格式：

输入在第1行中给出一个不超过100个字符长度的、以回车结束的非空字符串；第2行给出非负整数N。

输出格式：

在一行中输出循环左移N次后的字符串。

输入样例：

Hello World!
2
输出样例：

llo World!He
*/

#include "iostream"
#include "string"

int main()
{
    std::string str;
    std::getline(std::cin, str);
    int N = 0;
    std::cin >> N;

    int size = str.size();
    N %= size;
    std::cout << str.substr(N) + str.substr(0, N);

    return 0;
}