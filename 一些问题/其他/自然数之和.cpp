//一个无序自然数数列，给定一个数M，选取自然数数列中两个数，其中他们的和是M，打印所有这样的自然数对

#include "iostream"
void printAnd(int *num, int N, int M)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (num[i] + num[j] == M)
            {
                std::cout << num[i] << ',' << num[j] << '\n';
            }
        }
    }
}