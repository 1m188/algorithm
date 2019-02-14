/*
凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI
     
（如果显示有问题，可以参见【图1.jpg】）
	 
	 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。
*/

#include "iostream"
#include "vector"

int Cal(std::vector<int> &num, std::vector<bool> &sign, int x = 0)
{
    static int caseNum = 0;

    if (x == 9)
    {
        if (num[0] + static_cast<double>(num[1]) / num[2] + static_cast<double>(100 * num[3] + 10 * num[4] + num[5]) / (100 * num[6] + 10 * num[7] + num[8]) == 10)
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = 0; i < 9; i++)
    {
        if (!sign[i])
        {
            num.push_back(i + 1);
            sign[i] = 1;
            Cal(num, sign, x + 1);
            num.pop_back();
            sign[i] = 0;
        }
    }

    return caseNum;
}

int main()
{
    std::vector<int> num{};
    std::vector<bool> sign(9, 0);
    std::cout << Cal(num, sign) << std::endl;

    return 0;
}