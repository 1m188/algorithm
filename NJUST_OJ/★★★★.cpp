/*
Description
求两个在不同进制下的数之和

Input
第一行输入一个t（t<1000），接下来每一行输入一个a和p，代表a在p进制下的数，一个b和一个q，代表b在q进制下的数（1<a,b<10000，1<p,q<11）

Output
输入a+b在十进制下的和

Sample Input
2
10 2 12 3
56 10 32 10

Sample Output
8
88
*/

#include "iostream"
#include "vector"
#include "cmath"
int main() //PE，很简单的转换进制，不知道为什么总是PE
{
    int t = 0;
    std::cin >> t;
    std::vector<std::pair<int, int>> num{};
    for (int i = 0; i < t; i++)
    {
        int a = 0, p = 0, b = 0, q = 0;
        std::cin >> a >> p >> b >> q;
        num.push_back(std::pair<int, int>(a, p));
        num.push_back(std::pair<int, int>(b, q));
    }

    for (std::vector<std::pair<int, int>>::iterator it = num.begin(); it <= num.end() - 2; it += 2)
    {
        int A = 0, B = 0, a = (*it).first, p = (*it).second, b = (*(it + 1)).first, q = (*(it + 1)).second;
        if (p == 10) //如果是十进制直接赋值
        {
            A = a;
        }
        else
        {
            for (int i = 0; a > 0; i++) //如果不是的话进制转换，下面对另一对数据的处理是一样的
            {
                A += a % 10 * pow(p, i);
                a /= 10;
            }
        }
        if (q == 10)
        {
            B = b;
        }
        else
        {
            for (int i = 0; b > 0; i++)
            {
                B += b % 10 * pow(q, i);
                b /= 10;
            }
        }
        std::cout << A + B << std::endl;
    }

    return 0;
}