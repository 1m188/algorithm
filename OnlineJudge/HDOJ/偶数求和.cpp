/*
Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。

Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。

Sample Input
3 2
4 2

Sample Output
3 6
3 7
*/

#include "cstdio"
#include "vector"
int main() //AC.
{
    std::vector<std::pair<int, int>> numList{};
    int n = 0, m = 0;
    while (scanf("%d%d", &n, &m) != EOF) //注意文件输入C风格的判断结尾
    {
        numList.push_back(std::pair<int, int>(n, m));
    }

    for (std::vector<std::pair<int, int>>::iterator it = numList.begin(); it != numList.end(); it++)
    {
        int num = 0, count = (*it).first, lastNum = 2;
        while (count >= (*it).second)
        {
            for (int i = 0; i < (*it).second; i++)
            {
                num += lastNum;
                count--;
                lastNum += 2;
            }
            num /= (*it).second;
            printf("%d", num);
            if (count)
            {
                printf(" ");
            }
            num = 0;
        }
        if (count)
        {
            for (int i = 0; i < count; i++)
            {
                num += lastNum;
                lastNum += 2;
            }
            num /= count;
            printf("%d", num);
        }
        printf("\n");
    }

    return 0;
}