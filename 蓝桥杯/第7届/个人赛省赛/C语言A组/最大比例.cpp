/*
最大比例

X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16,24,36,54
其等比值为：3/2

现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。

输入格式：
第一行为数字 N (0<N<100)，表示接下的一行包含N个正整数
第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额

要求输出：
一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数

测试数据保证了输入格式正确，并且最大比例是存在的。

例如，输入：
3
1250 200 32

程序应该输出：
25/4

再例如，输入：
4
3125 32 32 200

程序应该输出：
5/2

再例如，输入：
3
549755813888 524288 2

程序应该输出：
4/1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

#include "iostream"
#include "vector"

void Cal(std::vector<long long> &v)
{
    long long a = 0, b = 0, c = 0;
    int size = v.size();

    for (int i = 0; i < size - 1; i++)
    {
        a = v[i], b = v[i + 1], c = a % b;
        while (c)
        {
            a = b;
            b = c;
            c = a % b;
        }
        v.push_back(v[i] / b);
        v.push_back(v[i + 1] / b);
    }
    for (std::vector<long long>::iterator it = v.begin();;)
    {
        if (size)
        {
            v.erase(it);
            size--;
        }
        else
        {
            break;
        }
    }
    while (v.size() > 2)
    {
        if (static_cast<double>(v[0]) / v[1] == static_cast<double>(v[2]) / v[3])
        {
            break;
        }
        size = v.size();
        for (int i = 0; i < size - 2; i++)
        {
            a = v[i], b = v[i + 2], c = a % b;
            while (c)
            {
                a = b;
                b = c;
                c = a % b;
            }
            v.push_back(v[i] / b);
            v.push_back(v[i + 2] / b);
        }
        for (std::vector<long long>::iterator it = v.begin();;)
        {
            if (size)
            {
                v.erase(it);
                size--;
            }
            else
            {
                break;
            }
        }
        for (std::vector<long long>::iterator it = v.begin(); it != v.end();)
        {
            if (*it == 1)
            {
                v.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
}

template <typename T>
void Sort(std::vector<T> &v)
{
    for (int i = v.size() - 2; i >= 0; i--)
    {
        for (int j = i; j < v.size() - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        T temp = *it;
        if (*(++it) == temp)
        {
            it--;
            v.erase(it);
        }
        else
        {
            it--;
        }
    }
}

int main()
{
    std::vector<long long> money;
    int N = 0;
    long long x = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> x;
        money.push_back(x);
    }
    Sort(money);
    Cal(money);
    std::cout << money[0] << '/' << money[1] << std::endl;

    return 0;
}