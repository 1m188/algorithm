/*
Description
Eddy's company publishes a kind of lottery.This set of lottery which are numbered 1 to n, and a set of one of each is required for a prize .With one number per lottery, how many lottery on average are required to make a complete set of n coupons?

Input
Input consists of a sequence of lines each containing a single positive integer n, 1<=n<=22, giving the size of the set of coupons.

Output
For each input line, output the average number of lottery required to collect the complete set of n coupons. If the answer is an integer number, output the number. If the answer is not integer, then output the integer part of the answer followed by a space and then by the proper fraction in the format shown below. The fractional part should be irreducible. There should be no trailing spaces in any line of ouput. 

Sample Input
2
5
17

Sample Output
3 
   5
11 --
   12
   340463
58 ------
   720720
*/

#include "iostream"
#include "vector"

int Gcd(int a, int b) //辗转相除法求最大公约数
{
    if (a < b)
    {
        std::swap(a, b);
    }
    int c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() //AC.这道题是求数学期望，第一张彩票买到的一定有用，但是第二张就只有n-1/n的概率有用，于是要买n/n-1张才行，以此类推，有购买张数=n/n+n/n-1+n/n-2+......+n，之后再化简就行了
{
    int n = 0;
    std::vector<int> data{};
    while (std::cin >> n && !std::cin.eof())
    {
        data.push_back(n);
    }

    for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
    {
        std::pair<int, int> last{(*it), (*it)};
        std::pair<int, int> next{(*it), (*it) - 1};
        while (next.second) //模拟前后两个分数相加
        {
            last.first = last.first * next.second + last.second * next.first;
            last.second *= next.second;             //这里要注意要先算分子的之后算分母的，如果先算分母的话之后的分子会受到变化的分母的影响
            int gcd = Gcd(last.first, last.second); //约公因数，因为在计算的过程中有时候数字实在太大，因此要约一下
            last.first /= gcd;
            last.second /= gcd;
            next.second--;
        }
        if (!(last.first % last.second))
        {
            std::cout << last.first / last.second << std::endl;
        }
        else //当为非整数的时候的输出，稍微有点麻烦，注意格式就行
        {
            int integer = 0;
            while (last.first > last.second)
            {
                last.first -= last.second;
                integer++;
            }
            int secondBit = 0, second = last.second;
            while (second)
            {
                secondBit++;
                second /= 10;
            }
            int integerBit = 0, _integer = integer;
            while (_integer)
            {
                integerBit++;
                _integer /= 10;
            }
            for (int i = 0; i <= integerBit; i++)
            {
                std::cout << ' ';
            }
            std::cout << last.first << std::endl;
            std::cout << integer << ' ';
            for (int i = 0; i < secondBit; i++)
            {
                std::cout << '-';
            }
            std::cout << std::endl;
            for (int i = 0; i <= integerBit; i++)
            {
                std::cout << ' ';
            }
            std::cout << last.second << std::endl;
        }
    }

    return 0;
}