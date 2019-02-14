/*
Description
给定两个字符串 A和B，我们定义一个A*B的是他们的串联。例如，如果一个A="abc"的和B ="def"，那么A*B的="abcdef"。我们定义串联的幂运算，由一个非负整数幂的定义是正常的方式：a^0 = "" (空串) ， a^(n+1) = a*(a^n).

Input
每个测试案例是一个s字符串，s长度是1-10000000个字符，没有空格。当s="."时结束。
最多有100个字符串

Output
求最大的n使得s由n个相同的字符串a连接而成，即s=a^n;注意s="."没有输出。

Sample Input
abcd
aaaa
ababab
.

Sample Output
1
4
3
*/

#include "iostream"
#include "string"
#include "vector"
int main()
{
    std::string temp = "";
    std::vector<std::string> str{};
    while (std::cin >> temp && temp != ".")
    {
        str.push_back(temp);
    }

    for (std::vector<std::string>::iterator it = str.begin(); it != str.end(); it++)
    {
        int maxn = 1;
        int size = (*it).size();
        for (int i = size; i >= 2; i--)
        {
            if (!(size % i))
            {
                std::string s = (*it).substr(0, size / i);
                std::string news = "";
                for (int j = 0; j < i; j++)
                {
                    news += s;
                }
                if (news == (*it))
                {
                    maxn = i;
                    break;
                }
            }
        }
        std::cout << maxn;
        if (it != str.end() - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}