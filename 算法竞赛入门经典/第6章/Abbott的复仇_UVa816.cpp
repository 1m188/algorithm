#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"

struct Node
{
    std::pair<int, int> pos;
    std::map<char, std::string> dir;

    Node() : pos({}), dir({}) {}
};
std::vector<std::pair<int, int>> printMinRode(const std::vector<std::vector<Node>> &, std::pair<int, int>, char, std::pair<int, int>);

int main() //无测试
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    int nodeNumX = 0, nodeNumY = 0;
    std::cin >> nodeNumX >> nodeNumY;
    std::vector<std::vector<Node>> nodes(nodeNumX, std::vector<Node>(nodeNumY, Node()));
    for (int i = 0; i < nodeNumX * nodeNumY; i++)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        x--, y--;
        nodes[x][y].pos.first = x + 1;
        nodes[x][y].pos.second = y + 1;
        std::string input{};
        while (std::cin >> input && input != "*")
        {
            char c = input[0];
            input.erase(input.begin());
            nodes[x][y].dir[c] = input;
        }
    }
    std::pair<int, int> initPos{}, endPos{};
    char dir = '\0';
    std::cin >> initPos.first >> initPos.second >> dir >> endPos.first >> endPos.second;

    std::vector<std::pair<int, int>> minRode = printMinRode(nodes, initPos, dir, endPos);
    for_each(minRode.begin(), minRode.end(), [&](std::pair<int, int> i) { std::cout << '(' << i.first << ',' << i.second << ')' << std::endl; });

    return 0;
}

std::vector<std::pair<int, int>> printMinRode(const std::vector<std::vector<Node>> &nodes, std::pair<int, int> initPos, char dir, std::pair<int, int> endPos)
{
    static std::vector<std::pair<int, int>> minRode(1000, std::pair<int, int>{});
    static std::vector<std::pair<int, int>> tempMinRode{};

    tempMinRode.push_back(initPos);
    if (initPos == endPos)
    {
        if (tempMinRode.size() < minRode.size())
        {
            minRode = tempMinRode;
            tempMinRode.clear();
        }
    }
    else
    {
        for (std::string::const_iterator it = nodes[initPos.first - 1][initPos.second - 1].dir.at(dir).begin(); it != nodes[initPos.first - 1][initPos.second - 1].dir.at(dir).end(); it++)
        {
            std::pair<int, int> nextPos{};
            char d = ' ';
            if (*it == 'F')
            {
                if (dir == 'N')
                {
                    nextPos.first = initPos.first - 1;
                    nextPos.second = initPos.second;
                }
                else if (dir == 'S')
                {
                    nextPos.first = initPos.first + 1;
                    nextPos.second = initPos.second;
                }
                else if (dir == 'W')
                {
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second - 1;
                }
                else if (dir == 'E')
                {
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second + 1;
                }
            }
            else if (*it == 'L')
            {
                if (dir == 'N')
                {
                    d = 'W';
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second - 1;
                }
                else if (dir == 'S')
                {
                    d = 'E';
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second + 1;
                }
                else if (dir == 'W')
                {
                    d = 'S';
                    nextPos.first = initPos.first + 1;
                    nextPos.second = initPos.second;
                }
                else if (dir == 'E')
                {
                    d = 'N';
                    nextPos.first = initPos.first - 1;
                    nextPos.second = initPos.second;
                }
            }
            else if (*it == 'R')
            {
                if (dir == 'N')
                {
                    d = 'E';
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second + 1;
                }
                else if (dir == 'S')
                {
                    d = 'W';
                    nextPos.first = initPos.first;
                    nextPos.second = initPos.second - 1;
                }
                else if (dir == 'W')
                {
                    d = 'N';
                    nextPos.first = initPos.first - 1;
                    nextPos.second = initPos.second;
                }
                else if (dir == 'E')
                {
                    d = 'S';
                    nextPos.first = initPos.first + 1;
                    nextPos.second = initPos.second;
                }
            }
            printMinRode(nodes, nextPos, d, endPos);
        }
    }
    return minRode;
}