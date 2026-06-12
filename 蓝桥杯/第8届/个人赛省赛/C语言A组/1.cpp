/*
标题：迷宫

X星球的一处迷宫游乐场建在某个小山坡上。
它是由10x10相互连通的小房间组成的。

房间的地板上写着一个很大的字母。
我们假设玩家是面朝上坡的方向站立，则：
L表示走到左边的房间，
R表示走到右边的房间，
U表示走到上坡方向的房间，
D表示走到下坡方向的房间。

X星球的居民有点懒，不愿意费力思考。
他们更喜欢玩运气类的游戏。这个游戏也是如此！

开始的时候，直升机把100名玩家放入一个个小房间内。
玩家一定要按照地上的字母移动。

迷宫地图如下：
------------
UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR
------------

请你计算一下，最后，有多少玩家会走出迷宫? 
而不是在里边兜圈子。

请提交该整数，表示走出迷宫的玩家数目，不要填写任何多余的内容。

如果你还没明白游戏规则，可以参看一个简化的4x4迷宫的解说图：
p1.png
*/

#include "iostream"
#include "vector"
#include "map"
#include "string"

//清空标志位
void clearJudge(std::vector<std::vector<bool>> &jud)
{
    for (std::vector<bool> &v : jud)
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i] = false;
        }
    }
}

int main()
{
    int num = 0;                                                                                                                                                                       //数目
    const std::map<char, std::pair<int, int>> dir = {{'U', {0, -1}}, {'D', {0, 1}}, {'L', {-1, 0}}, {'R', {1, 0}}};                                                                    //移动方向从字符到xy坐标变动的映射
    const std::vector<std::string> map = {"UDDLUULRUL", "UURLLLRRRU", "RRUURLDLRD", "RUDDDDUUUU", "URUDLLRRUU", "DURLRLDLRL", "ULLURLLRDU", "RDLULLRDDD", "UUDDUDUDLL", "ULRDLUURRR"}; //地图
    std::vector<std::vector<bool>> jud(10, std::vector<bool>(10, false));                                                                                                              //标志位，标识是否走过这个地方

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //走一个
            std::pair<int, int> pos = {j, i};
            char c = map[i][j];
            pos.first += dir.at(c).first;
            pos.second += dir.at(c).second;
            //走出去了
            if (pos.first < 0 || pos.first >= 10 || pos.second < 0 || pos.second >= 10)
            {
                num++;
            }
            else
            {
                //否则将上一个地方的标志位置true
                jud[i][j] = true;
                //除非走到走过的地方
                while (!jud[pos.second][pos.first])
                {
                    jud[pos.second][pos.first] = true;
                    char c = map[pos.second][pos.first];
                    pos.first += dir.at(c).first;
                    pos.second += dir.at(c).second;
                    //如果走出去了
                    if (pos.first < 0 || pos.first >= 10 || pos.second < 0 || pos.second >= 10)
                    {
                        num++;
                        clearJudge(jud);
                        break;
                    }
                }
            }
        }
    }

    std::cout << num << std::endl;

    return 0;
}