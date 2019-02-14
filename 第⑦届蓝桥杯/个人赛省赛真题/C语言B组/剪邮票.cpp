/*
剪邮票

如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include "iostream"
#include "vector"
#include "queue"

bool BFS(std::vector<bool> &stamp)
{
    std::vector<bool> sign(stamp);
    std::queue<int> judge{};

    for (int i = 7; i <= 22;)
    {
        if (sign[i])
        {
            judge.push(i);
            sign[i] = 0;
            break;
        }
        if (i == 10 || i == 16)
        {
            i += 3;
        }
        else
        {
            i++;
        }
    }
    while (!judge.empty())
    {
        if (sign[judge.front() - 1])
        {
            judge.push(judge.front() - 1);
            sign[judge.front() - 1] = 0;
        }
        if (sign[judge.front() + 1])
        {
            judge.push(judge.front() + 1);
            sign[judge.front() + 1] = 0;
        }
        if (sign[judge.front() - 6])
        {
            judge.push(judge.front() - 6);
            sign[judge.front() - 6] = 0;
        }
        if (sign[judge.front() + 6])
        {
            judge.push(judge.front() + 6);
            sign[judge.front() + 6] = 0;
        }
        judge.pop();
    }
    for (int i = 7; i <= 22;)
    {
        if (sign[i])
        {
            return false;
        }
        if (i == 10 || i == 16)
        {
            i += 3;
        }
        else
        {
            i++;
        }
    }
    return true;
}

int CutStamp(std::vector<bool> &stamp, int x = 0, int index = 7)
{
    static int caseNum = 0;

    if (x == 5)
    {
        if (BFS(stamp))
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = index; i <= 22;)
    {
        if (!stamp[i])
        {
            stamp[i] = 1;
            CutStamp(stamp, x + 1, i);
            stamp[i] = 0;
        }
        if (i == 10 || i == 16)
        {
            i += 3;
        }
        else
        {
            i++;
        }
    }

    return caseNum;
}

int main()
{
    std::vector<bool> stamp(30, 0);
    std::cout << CutStamp(stamp) << std::endl;

    return 0;
}