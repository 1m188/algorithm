/*
方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include "cmath"
#include "iostream"

const int FillNumber(int *num, int *vis, int x = 0)
{
    static int caseNum = 0;

    if (x > 9)
    {
        if (abs(num[0] - num[1]) > 1 && abs(num[0] - num[3]) > 1 && abs(num[0] - num[4]) > 1 && abs(num[0] - num[5]) > 1 && abs(num[1] - num[2]) > 1 && abs(num[1] - num[4]) > 1 && abs(num[1] - num[5]) > 1 && abs(num[1] - num[6]) > 1 && abs(num[2] - num[5]) > 1 && abs(num[2] - num[6]) > 1 && abs(num[3] - num[4]) > 1 && abs(num[3] - num[7]) > 1 && abs(num[3] - num[8]) > 1 && abs(num[4] - num[5]) > 1 && abs(num[4] - num[7]) > 1 && abs(num[4] - num[8]) > 1 && abs(num[4] - num[9]) > 1 && abs(num[5] - num[6]) > 1 && abs(num[5] - num[6]) > 1 && abs(num[5] - num[8]) > 1 && abs(num[5] - num[9]) > 1 && abs(num[6] - num[9]) > 1 && abs(num[7] - num[8]) > 1 && abs(num[8] - num[9]) > 1)
        {
            caseNum++;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            num[x] = i;
            FillNumber(num, vis, x + 1);
            vis[i] = 0;
        }
    }

    return caseNum;
}

int main()
{
    int num[10]{}, vis[10]{};
    std::cout << FillNumber(num, vis);

    return 0;
}