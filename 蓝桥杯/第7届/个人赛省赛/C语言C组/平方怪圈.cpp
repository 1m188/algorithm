/*
平方怪圈

如果把一个正整数的每一位都平方后再求和，得到一个新的正整数。
对新产生的正整数再做同样的处理。

如此一来，你会发现，不管开始取的是什么数字，
最终如果不是落入1，就是落入同一个循环圈。

请写出这个循环圈中最大的那个数字。

请填写该最大数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include "iostream"
#include "cmath"
#include "vector"
#include "algorithm"

int Square(int n)
{
    int num = 0;
    num += pow(n % 10, 2);
    while (n /= 10)
    {
        num += pow(n % 10, 2);
    }
    return num;
}

int main()
{
    int num = 0;
    std::cin >> num;
    std::vector<int> square{num};
    for (;;)
    {
        square.push_back(Square(square.back()));
        for (std::vector<int>::iterator it = square.begin(); it < square.end() - 1; it++)
        {
            if (*it == square.back())
            {
                square.erase(square.end() - 1);
                goto end;
            }
        }
    }
end:
    std::sort(square.begin(), square.end());
    std::cout << square.back() << std::endl;

    return 0;
}