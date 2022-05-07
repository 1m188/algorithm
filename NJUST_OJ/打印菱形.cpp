/*
Description
打印边长为n的菱形

Input
多个case，以文件尾结束.
每个case输入一个整数n (1<=n<=50),表示菱形的边长

Output
边长为N的菱形，不要有多余的空格（每行均以'*'结尾）

Sample Input
6

Sample Output
     *
    ***
   *****
  *******
 *********
***********
 *********
  *******
   *****
    ***
     *
*/

#include "iostream"
#include "vector"
#include "cmath"
int main() //WA，应该是文件输入这一块有问题
{
    int n = 0;
    std::vector<int> N{};
    std::cin >> n;
    while (!std::cin.eof())
    {
        N.push_back(n);
        std::cin >> n;
    }

    while (!N.empty())
    {
        for (int i = N[0] - 1; i >= 1 - N[0]; i--)
        {
            for (int j = 0; j < abs(i); j++)
            {
                std::cout << ' ';
            }
            for (int j = 0; j < 2 * (6 - abs(i)) - 1; j++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
        N.erase(N.begin());
    }

    return 0;
}