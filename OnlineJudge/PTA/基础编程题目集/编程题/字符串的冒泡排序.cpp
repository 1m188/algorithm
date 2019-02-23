/*
7-30 字符串的冒泡排序 （20 分）
我们已经知道了将N个整数按从小到大排序的冒泡排序法。本题要求将此方法用于字符串序列，并对任意给定的K（<N），输出扫描完第K遍后的中间结果序列。

输入格式：

输入在第1行中给出N和K（1≤K<N≤100），此后N行，每行包含一个长度不超过10的、仅由小写英文字母组成的非空字符串。

输出格式：

输出冒泡排序法扫描完第K遍后的中间结果序列，每行包含一个字符串。

输入样例：

6 2
best
cat
east
a
free
day
输出样例：

best
a
cat
day
east
free
*/

#include "iostream"
#include "string"
#include "vector"

int main()
{
    int N = 0, K = 0;
    std::cin >> N >> K;
    std::vector<std::string> vec(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> vec[i];
    }

    for (int i = N - 1; i > N - 1 - K; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    for (const std::string &s : vec)
    {
        std::cout << s << std::endl;
    }

    return 0;
}