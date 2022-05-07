/*
问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。
样例输入
5
8 3 6 4 9
样例输出
3 4 6 8 9
*/

#include "iostream"
#include "vector"

int main()
{
    //输入
    int n = 0;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    //冒泡排序
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (num[j] < num[j - 1])
            {
                int temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
        }
    }

    //输出
    for (int i = 0; i < n; i++)
    {
        std::cout << num[i] << ' ';
        if (i == n - 1)
        {
            std::cout << '\b';
        }
    }

    return 0;
}