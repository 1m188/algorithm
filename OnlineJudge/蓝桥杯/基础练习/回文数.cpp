/*
问题描述
　　1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。
输出格式
　　按从小到大的顺序输出满足条件的四位十进制数。
*/

#include "iostream"
#include "vector"

int main()
{
    std::vector<int> numVec;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int num = 0;
            num += i;
            num *= 10;
            num += j;
            num *= 10;
            num += j;
            num *= 10;
            num += i;
            numVec.push_back(num);
        }
    }

    for (int i = 0; i < numVec.size(); i++)
    {
        std::cout << numVec[i] << std::endl;
    }

    return 0;
}