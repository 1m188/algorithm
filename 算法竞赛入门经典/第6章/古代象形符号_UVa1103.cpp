#include "iostream"
#include "string"
#include "cmath"
#include "map"
#include "algorithm"
#include "vector"
#include "queue"

struct Point
{
    bool isBlack;
    bool isWhite;
    bool isBackground;
    int num;

    Point() : isBlack(false), isWhite(false), isBackground(false), num(-1) {}
};
std::string sixteen2Two(std::string);

int main() //无测试，而且为了简便，只设计了给出一个图案的过程，对比原题肯定会WA
{
    int H = 0, W = 0;
    std::cin >> H >> W;
    std::vector<std::vector<Point>> matrix(H, std::vector<Point>(W * 8, Point()));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            std::string input{};
            std::cin >> input;
            std::string handle = sixteen2Two(input);
            for (int k = 0; k < handle.size(); k++)
            {
                if (handle[k] == '1')
                {
                    matrix[i][j * 8 + k].isBlack = true;
                }
                else if (handle[k] == '0')
                {
                    matrix[i][j * 8 + k].isWhite = true;
                }
            }
        }
    }

    std::queue<std::pair<int, int>> background{};
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W * 8; j++)
        {
            if ((i == 0 || i == H - 1) && (j == 0 || j == W * 8 - 1) && matrix[i][j].isWhite == true)
            {
                background.push(std::pair<int, int>{i, j});
                goto outside;
            }
        }
    }
outside:
    while (!background.empty())
    {
        int x = background.front().first;
        int y = background.front().second;
        matrix[x][y].isBackground = true;
        background.pop();
        if (x - 1 >= 0 && matrix[x - 1][y].isBlack == false && matrix[x - 1][y].isBackground == false)
        {
            background.push(std::pair<int, int>{x - 1, y});
        }
        if (x + 1 < H && matrix[x + 1][y].isBlack == false && matrix[x + 1][y].isBackground == false)
        {
            background.push(std::pair<int, int>{x + 1, y});
        }
        if (y - 1 >= 0 && matrix[x][y - 1].isBlack == false && matrix[x][y - 1].isBackground == false)
        {
            background.push(std::pair<int, int>{x, y - 1});
        }
        if (y + 1 < W * 8 && matrix[x][y + 1].isBlack == false && matrix[x][y + 1].isBackground == false)
        {
            background.push(std::pair<int, int>{x, y + 1});
        }
    }

    int num = 1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W * 8; j++)
        {
            if (matrix[i][j].isBackground == false && matrix[i][j].isWhite == true && matrix[i][j].num == -1)
            {
                std::queue<std::pair<int, int>> circle{};
                circle.push(std::pair<int, int>{i, j});
                while (!circle.empty())
                {
                    int x = circle.front().first;
                    int y = circle.front().second;
                    matrix[x][y].num = num;
                    circle.pop();
                    if (x - 1 >= 0 && matrix[x - 1][y].isBackground == false && matrix[x - 1][y].isWhite == true && matrix[x - 1][y].num == -1)
                    {
                        circle.push(std::pair<int, int>{x - 1, y});
                    }
                    if (x + 1 < H && matrix[x + 1][y].isBackground == false && matrix[x + 1][y].isWhite == true && matrix[x + 1][y].num == -1)
                    {
                        circle.push(std::pair<int, int>{x + 1, y});
                    }
                    if (y - 1 >= 0 && matrix[x][y - 1].isBackground == false && matrix[x][y - 1].isWhite == true && matrix[x][y - 1].num == -1)
                    {
                        circle.push(std::pair<int, int>{x, y - 1});
                    }
                    if (y + 1 < W * 8 && matrix[x][y + 1].isBackground == false && matrix[x][y + 1].isWhite == true && matrix[x][y + 1].num == -1)
                    {
                        circle.push(std::pair<int, int>{x, y + 1});
                    }
                }
                num++;
            }
        }
    }

    std::map<int, std::string> output{};
    output[1] = "Ankh";
    output[3] = "Wedjat";
    output[5] = "Djed";
    output[4] = "Scarab";
    output[0] = "Was";
    output[2] = "Akeht";
    std::cout << output[num - 1] << std::endl;

    return 0;
}

std::string sixteen2Two(std::string orginalNum)
{
    std::map<char, int> transport{};
    for (int i = 0; i < 10; i++)
    {
        transport[i + '0'] = i;
    }
    transport['a'] = 10;
    transport['b'] = 11;
    transport['c'] = 12;
    transport['d'] = 13;
    transport['e'] = 14;
    transport['f'] = 15;

    int tenNum = 0;
    for (int i = orginalNum.size() - 1; i >= 0; i--)
    {
        tenNum += transport[orginalNum[i]] * pow(16, orginalNum.size() - i - 1);
    }

    std::string twoNum{};
    while (tenNum)
    {
        twoNum += tenNum % 2 + '0';
        tenNum /= 2;
    }
    std::reverse(twoNum.begin(), twoNum.end());

    return twoNum;
}