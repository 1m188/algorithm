/*
Description
似乎大家都有做电梯的习惯，现在为了锻炼身体，我们漂亮的贾琼姐姐提议大家天天走楼梯，另外一个方面，帆哥比较喜欢思考，他想知道到底有多少种方法能够走到楼顶。由于帆哥身体素质不够过关，他一次最多只能跨两个台阶，最少跨一个台阶。

Input
第一行给出测试样例的个数t（t<100)
接下来给出t行，每行给出楼梯的高度n(1<=n<=20)

Output
他一共有多少种不同的走法能够走到楼顶

Sample Input
2
2
19

Sample Output
2
6765
*/

#include "iostream"
#include "vector"

int Way(int stair, int x = 0) //递归求每个楼梯阶数的走法
{
    static int caseNum = 0;
    if (x == 0)
    {
        caseNum = 0; //避免上一次的结果影响这一次的结果
    }

    if (x > stair)
    {
        return 0; //边界条件
    }
    else if (x == stair)
    {
        caseNum++;
    }
    else
    {
        Way(stair, x + 1);
        Way(stair, x + 2);
    }

    return caseNum;
}

int main() //AC。打表匹配
{
    std::vector<int> way(20, 0);
    for (int i = 1; i <= 20; i++)
    {
        way[i - 1] = Way(i); //打表
    }

    int t = 0;
    std::cin >> t;
    std::vector<int> test(t, 0);
    for (int i = 0; i < t; i++)
    {
        std::cin >> test[i];
    }

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
    {
        std::cout << way[(*it) - 1];
        if (it != test.end() - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}