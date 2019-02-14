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

#include "queue"
#include "iostream"

const bool Judge(bool stamp[30]) //BFS判断连通
{
    std::queue<int> isConnectQueue = std::queue<int>();
    bool sign[30]{};
    for (int i = 0; i < 30; i++)
    {
        sign[i] = stamp[i];
    }
    const int dir[4]{-6, +6, -1, +1};

    for (int i = 7; i <= 22; [&]() -> int { if(i==10||i==16) i+=3;else i++;return i; }())
    {
        if (sign[i])
        {
            isConnectQueue.push(i);
            sign[i] = 0;
            break;
        }
    }

    while (!isConnectQueue.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (sign[isConnectQueue.front() + dir[i]])
            {
                isConnectQueue.push(isConnectQueue.front() + dir[i]);
                sign[isConnectQueue.front() + dir[i]] = 0;
            }
        }
        isConnectQueue.pop();
    }

    for (int i = 7; i <= 22; [&]() -> int { if(i==10||i==16) i+=3;else i++;return i; }())
    {
        if (sign[i])
        {
            return false;
        }
    }
    return true;
}

const int CutStamp(bool stamp[30], int x = 0, int it = 7) //DFS选取五个数的组合
{
    static int caseNum = 0;

    if (x > 4)
    {
        if (Judge(stamp))
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = it; i <= 22; [&]() -> int { if(i==10||i==16) i+=3;else i++;return i; }())
    {
        if (!stamp[i])
        {
            stamp[i] = 1;
            CutStamp(stamp, x + 1, i);
            stamp[i] = 0;
        }
    }

    return caseNum;
}

int main()
{
    bool stamp[30]{};
    std::cout << CutStamp(stamp);

    return 0;
}