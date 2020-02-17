/*
寒假作业

现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：

   □ + □ = □
   □ - □ = □
   □ × □ = □
   □ ÷ □ = □
   
   (如果显示不出来，可以参见【图1.jpg】)
   
每个方块代表1~13中的某一个数字，但不能重复。
比如：
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

以及： 
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）
 
你一共找到了多少种方案？


请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include "iostream"
#include "vector"

int Homework(std::vector<int> &num, std::vector<bool> &sign, int x = 0)
{
    static int caseNum = 0;

    if (x == 3)
    {
        if (num[0] + num[1] != num[2])
        {
            return 0;
        }
    }
    else if (x == 6)
    {
        if (num[3] - num[4] != num[5])
        {
            return 0;
        }
    }
    else if (x == 9)
    {
        if (num[6] * num[7] != num[8])
        {
            return 0;
        }
    }
    else if (x == 12)
    {
        if (num[10] != 0 && static_cast<double>(num[9]) / num[10] == num[11]) //在判断除法这里需要避免int型数据的取整，需首先转换为double型数据进行判断，这样才准确
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = 0; i < 13; i++)
    {
        if (!sign[i])
        {
            num.push_back(i + 1);
            sign[i] = 1;
            Homework(num, sign, x + 1);
            num.pop_back();
            sign[i] = 0;
        }
    }

    return caseNum;
}

int main()
{
    std::vector<int> num{};
    std::vector<bool> sign(13, 0);
    std::cout << Homework(num, sign) << std::endl;

    return 0;
}