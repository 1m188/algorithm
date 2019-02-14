/*
问题描述
　　123321是一个非常特殊的数，它从左边读和从右边读是一样的。
　　输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
输入格式
　　输入一行，包含一个正整数n。
输出格式
　　按从小到大的顺序输出满足条件的整数，每个整数占一行。
样例输入
52
样例输出
899998
989989
998899
数据规模和约定
　　1<=n<=54。
*/

#include "iostream"
#include "vector"
#include "algorithm"

int n = 0;
std::vector<int> bit5Num;
std::vector<int> bit6Num;

//通过枚举前几位数，之后用回文的方法判定，确定之后获取数字
void findNNum(int N)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                //对于5位数，前两位和最后两位对称出现，中间的一位单位
                if (N == 5)
                {
                    if (i * 2 + j * 2 + k == n)
                    {
                        int num = 0;
                        num += i;
                        num *= 10;
                        num += j;
                        num *= 10;
                        num += k;
                        num *= 10;
                        num += j;
                        num *= 10;
                        num += i;
                        bit5Num.push_back(num);
                    }
                }
                //对于6位数，前三位和后三位对称出现
                else if (N == 6)
                {
                    if (i * 2 + j * 2 + k * 2 == n)
                    {
                        int num = 0;
                        num += i;
                        num *= 10;
                        num += j;
                        num *= 10;
                        num += k;
                        num *= 10;
                        num += k;
                        num *= 10;
                        num += j;
                        num *= 10;
                        num += i;
                        bit6Num.push_back(num);
                    }
                }
            }
        }
    }
}

int main()
{
    std::cin >> n;

    //这里对5位数组和6位数组进行排序，并先输出5位数组再输出6位数组，以小大顺序输出
    findNNum(5);
    std::sort(bit5Num.begin(), bit5Num.end());
    for (int i = 0; i < bit5Num.size(); i++)
    {
        std::cout << bit5Num[i] << std::endl;
    }

    findNNum(6);
    std::sort(bit6Num.begin(), bit6Num.end());
    for (int i = 0; i < bit6Num.size(); i++)
    {
        std::cout << bit6Num[i] << std::endl;
    }

    return 0;
}