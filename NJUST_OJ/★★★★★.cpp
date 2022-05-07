/*
Description
任意给定一个数组a[],我们对数组有两种操作：
1、将前n-1个数从小到大排序
2、将后n-1个数从小到大排序
现在，你有一个数组，长度为n，你每一次可以执行上面的操作之一，请问最少需要几次操作可以将一个数组按照升序的方式排列好

Input
第一行输入一个t（t<1000），接下来输入一个n代表数组的长度，接下来输入n个数

Output
输出最少操作次数

Sample Input
2
5
1 2 3 5 4
6
6 4 3 1 2 5

Sample Output
1
2
*/

#include "iostream"
#include "vector"
#include "algorithm"

template <typename T>
int Sort(const std::vector<T> &v, const std::vector<T> &finished)
{ //由于每次要么对前n-1个数排序，要么对后n-1个数排序（不重复操作），这样就可以把所有情况分为两种情况来写了，之后取最小的那个方案数即可
    int caseNum = 0;
    std::vector<T> one = v, two = v;

    for (int i = 0;; i++)
    {
        if (one == finished)
        {
            caseNum = i; //第一种情况直接取
            break;
        }
        else
        {
            if (i % 2)
            {
                std::sort(one.begin(), one.end() - 1);
            }
            else
            {
                std::sort(one.begin() + 1, one.end());
            }
        }
    }

    for (int i = 0;; i++)
    {
        if (two == finished)
        {
            caseNum = caseNum < i ? caseNum : i; //第二种情况要和第一种情况比较取最小
            break;
        }
        else
        {
            if (i % 2)
            {
                std::sort(two.begin() + 1, two.end());
            }
            else
            {
                std::sort(two.begin(), two.end() - 1);
            }
        }
    }

    return caseNum;
}

int main() //Presentation Error 输出格式不对？？？
{
    int t = 0;
    std::cin >> t;
    std::vector<std::vector<int>> a{};
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        std::cin >> n;
        std::vector<int> temp{};
        for (int i = 0; i < n; i++)
        {
            int _t = 0;
            std::cin >> _t;
            temp.push_back(_t);
        }
        a.push_back(temp);
    }

    for (std::vector<std::vector<int>>::iterator it = a.begin(); it != a.end(); it++)
    {
        std::vector<int> finished = *it;
        std::sort(finished.begin(), finished.end());
        std::cout << Sort(*it, finished) << std::endl;
    }

    return 0;
}