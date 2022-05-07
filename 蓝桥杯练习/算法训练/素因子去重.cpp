/*
问题描述
　　给定一个正整数n，求一个正整数p，满足p仅包含n的所有素因子，且每个素因子的次数不大于1
输入格式
　　一个整数，表示n
输出格式
　　输出一行，包含一个整数p。
样例输入
1000
样例输出
10
数据规模和约定
　　n<=10^12
　　样例解释：n=1000=2^3*5*3，p=2*5=10
*/

#include "iostream"
#include "set"

//set容器是集合，具有唯一性，可以确保不会有重复的因子加入
std::set<int> set;

//递归找因子
void find(long long num)
{
    if (num > 1)
    {
        for (long long i = 2; i <= num; i++)
        {
            if (num % i == 0)
            {
                set.insert(i);
                num /= i;
                break;
            }
        }
        find(num);
    }
    else
    {
        set.insert(1);
    }
}

//判定是否是素数
bool isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n = 0;
    std::cin >> n;

    find(n);
    int p = 1;
    for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
    {
        if (isPrime(*it))
        {
            p *= *it;
        }
    }

    std::cout << p;

    return 0;
}