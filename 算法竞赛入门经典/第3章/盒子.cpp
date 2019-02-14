#include "iostream"
#include "vector"
int main() //一个糟糕的算法，各种goto跳转多个return，根据长方体的直接性质定义来写的，应该有更加巧妙的算法
{
    std::vector<std::vector<int>> wh;
    for (int i = 0; i < 6; i++)
    {
        int a = 0, b = 0;
        std::cin >> a >> b;
        wh.push_back(std::vector<int>{a, b});
    }

    for (int i = 1; i < 6; i++)
    {
        if (wh[i][0] == wh[0][0] && wh[i][1] != wh[0][1])
        {
            std::swap(wh[i], wh[1]);
            goto next1;
        }
    }
    std::cout << "no\n";
    return 0;

next1:
    for (int i = 2; i < 6; i++)
    {
        if ((wh[i][0] == wh[0][1] && wh[i][1] == wh[1][1]) || (wh[i][0] == wh[1][1] && wh[i][1] == wh[0][1]))
        {
            std::swap(wh[2], wh[i]);
            goto next2;
        }
    }
    std::cout << "no\n";
    return 0;

next2:
    for (int i = 3; i < 6; i++)
    {
        if (wh[i][0] == wh[0][0] && wh[i][1] == wh[0][1])
        {
            continue;
        }
        else if (wh[i][0] == wh[1][0] && wh[i][1] == wh[1][1])
        {
            continue;
        }
        else if (wh[i][0] == wh[2][0] && wh[i][1] == wh[2][1])
        {
            continue;
        }
        std::cout << "no\n";
        return 0;
    }

    std::cout << "yes\n";

    return 0;
}