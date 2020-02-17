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
const int Homework(double homework[12], bool sign[13], int x)
{
    static int caseNum = 0;

    if (x == 3)
    {
        if (homework[0] + homework[1] != homework[2])
        {
            return 0;
        }
    }
    else if (x == 6)
    {
        if (homework[3] - homework[4] != homework[5])
        {
            return 0;
        }
    }
    else if (x == 9)
    {
        if (homework[6] * homework[7] != homework[8])
        {
            return 0;
        }
    }
    else if (x == 12)
    {
        if (homework[9] / homework[10] == homework[11])
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = 0; i < 13; i++)
    {
        if (!sign[i])
        {
            homework[x] = i + 1;
            sign[i] = 1;
            Homework(homework, sign, x + 1);
            sign[i] = 0;
        }
    }

    return caseNum;
}