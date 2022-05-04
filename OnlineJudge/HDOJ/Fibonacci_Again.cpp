/*
Description
There are another kind of Fibonacci numbers: F(0) = 7, F(1) = 11, F(n) = F(n-1) + F(n-2) (n>=2).

Input
Input consists of a sequence of lines, each containing an integer n. (n < 1,000,000).

Output
Print the word "yes" if 3 divide evenly into F(n).

Print the word "no" if not.

Sample Input
0
1
2
3
4
5

Sample Output
no
no
yes
no
no
no
*/

#include "iostream"
#include "vector"

int Fib(int n, int a = 7, int b = 4)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return a;
    }
    else
    {
        return Fib(n - 1, a + b, a);
    }
}

int main() //WA.不知道为什么，觉得主要是由于输入结束的条件没有给出，不知道怎么判断输入结束
{
    std::vector<int> input{};
    for (int i = 0; i < 6; i++) //处理输入，根据示例写的，六个输入，实际上应该不是
    {
        int x = 0;
        std::cin >> x;
        input.push_back(x);
    }

    for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        if (Fib(*it) % 3)
        {
            std::cout << "no\n";
        }
        else
        {
            std::cout << "yes\n";
        }
    }

    return 0;
}