/*
Description
南京理工大学acm集训队即将迎来一批新人，他们身高各异，鱼头很想知道谁是最高的。

Input
输入数据的第一行是测试的个数T（T<= 50），下面就是T个测试;
每个测试一行，第一个数字是n,表示人数，随后有n个整数x1,x2,x3,…,xn，表示每个人的身高;

Output
输出最高的那个人。

Sample Input
2
5 1 2 3 4 5
3 122 134 155

Sample Output
5
155
*/

#include "iostream"
#include "vector"
#include "algorithm"
int main()
{
    int T = 0;
    std::cin >> T;
    std::vector<std::vector<int>> test(T, std::vector<int>{});
    for (int i = 0; i < T; i++)
    {
        int n = 0;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            std::cin >> temp;
            test[i].push_back(temp);
        }
    }

    for (std::vector<std::vector<int>>::iterator it = test.begin(); it != test.end(); it++)
    {
        std::cout << *(std::max_element((*it).begin(), (*it).end())); //注意max_element这个函数，返回最大值的迭代器，min_element返回最小值的迭代器，distance返回两个迭代器之间基于0的索引
        if (it != test.end() - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}