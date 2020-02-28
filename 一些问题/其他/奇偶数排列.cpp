//输入一个数组，实现一个函数，让所有奇数都在偶数前面

#include "memory"

std::shared_ptr<int> odd_even_numSort(int *num, int N)
{
    std::shared_ptr<int> newNum(new int[N]{0});
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (num[i] % 2 != 0)
        {
            newNum.get()[j++] = num[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (num[i] % 2 == 0)
        {
            newNum.get()[j++] = num[i];
        }
    }
    return newNum;
}