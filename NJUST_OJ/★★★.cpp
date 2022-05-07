/*
Description
任意输入一个数组，将数组的数据反向排列后输出（使用指针在函数间传递一维数组，注意空格和换行，不要多空格，也不要少了换行）

Input
第一行输入一个t（t<1000），接下来先输入一个n，然后再输入n个数（均不大于1000）

Output
输入反向排列后的数组

Sample Input
2
4
1 2 3 4
5
5 4 3 2 1

Sample Output
4 3 2 1
1 2 3 4 5
*/

#include "iostream"
#include "vector"
#include "algorithm"
int main() //PE。很简单的题，用了algorithm头文件后甚至都不是题目，但是总是PE，百思不得其解
{
    int t = 0;
    std::cin >> t;
    std::vector<std::vector<int>> a{};
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        std::cin >> n;
        std::vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp[j];
        }
        a.push_back(temp);
    }

    for (std::vector<std::vector<int>>::iterator it = a.begin(); it != a.end(); it++)
    {
        std::reverse((*it).begin(), (*it).end());
        for_each((*it).begin(), (*it).end() - 1, [&](int i) { std::cout << i << ' '; });
        std::cout << *((*it).end() - 1) << std::endl;
    }

    return 0;
}