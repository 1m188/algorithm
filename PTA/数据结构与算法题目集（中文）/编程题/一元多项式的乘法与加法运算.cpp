/*
7-2 一元多项式的乘法与加法运算 （20 分）
设计函数分别求两个一元多项式的乘积与和。

输入格式:

输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:

输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

#include "iostream"
#include "vector"
#include "algorithm"

std::vector<std::pair<int, int>> add(const std::vector<std::pair<int, int>> &vec1, const std::vector<std::pair<int, int>> &vec2)
{
    std::vector<std::pair<int, int>> sum = vec1;
    for (auto &num : vec2)
    {
        auto it = std::find_if(sum.begin(), sum.end(), [&](const std::pair<int, int> &p) { return p.second == num.second; });
        if (it != sum.end())
        {
            it->first += num.first;
        }
        else
        {
            sum.push_back(num);
        }
    }
    for (auto it = sum.begin(); it < sum.end();)
    {
        if (it->first == 0)
        {
            it = sum.erase(it);
        }
        else
        {
            it++;
        }
    }
    std::sort(sum.begin(), sum.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) { return p1.second >= p2.second; });
    return sum;
}

std::vector<std::pair<int, int>> multiply(const std::vector<std::pair<int, int>> &vec1, const std::vector<std::pair<int, int>> &vec2)
{
    std::vector<std::pair<int, int>> product;
    for (auto &vec1Num : vec1)
    {
        for (auto &vec2Num : vec2)
        {
            product.push_back({vec1Num.first * vec2Num.first, vec1Num.second + vec2Num.second});
        }
    }
    for (auto it = product.begin(); it < product.end();)
    {
        for (auto itt = it + 1; itt < product.end(); itt++)
        {
            if (it->second == itt->second)
            {
                itt->first += it->first;
                it = product.erase(it);
                goto next;
            }
        }
        it++;
    next:;
    }
    for (auto it = product.begin(); it < product.end();)
    {
        if (it->first == 0)
        {
            it = product.erase(it);
        }
        else
        {
            it++;
        }
    }
    std::sort(product.begin(), product.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) { return p1.second >= p2.second; });
    return product;
}

int main()
{
    int num = 0;
    std::cin >> num;
    std::vector<std::pair<int, int>> vec1(num);
    for (int i = 0; i < num; i++)
    {
        std::cin >> vec1[i].first >> vec1[i].second;
    }
    std::cin >> num;
    std::vector<std::pair<int, int>> vec2(num);
    for (int i = 0; i < num; i++)
    {
        std::cin >> vec2[i].first >> vec2[i].second;
    }

    std::vector<std::pair<int, int>> &&sum = add(vec1, vec2), &&product = multiply(vec1, vec2);

    int size = product.size();
    if (size == 0)
    {
        std::cout << "0 0";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << product[i].first << ' ' << product[i].second;
            if (i != size - 1)
            {
                std::cout << ' ';
            }
        }
    }
    std::cout << std::endl;
    size = sum.size();
    if (size == 0)
    {
        std::cout << "0 0";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << sum[i].first << ' ' << sum[i].second;
            if (i != size - 1)
            {
                std::cout << ' ';
            }
        }
    }

    return 0;
}