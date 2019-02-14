#include "iostream"
#include "vector"
#include "string"
#include "cmath"

void MoveOnto(std::vector<std::vector<int>> &blocks, int a, int b);
void MoveOver(std::vector<std::vector<int>> &blocks, int a, int b);
void PileOnto(std::vector<std::vector<int>> &blocks, int a, int b);
void PileOver(std::vector<std::vector<int>> &blocks, int a, int b);

int main() //没测试
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> blocks(n, std::vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> blocks[i][j];
        }
    }

    std::string oper = "";
    std::cin >> oper;
    while (oper != "quit")
    {
        oper += ' ';
        std::string oper1 = oper.substr(0, oper.find(' '));
        oper.erase(oper.begin(), oper.begin() + oper.find(' ') + 1);
        std::string aStr = oper.substr(0, oper.find(' '));
        oper.erase(oper.begin(), oper.begin() + oper.find(' ') + 1);
        std::string oper2 = oper.substr(0, oper.find(' '));
        oper.erase(oper.begin(), oper.begin() + oper.find(' ') + 1);
        std::string bStr = oper.substr(0, oper.find(' '));
        if (aStr != bStr)
        {
            int a = 0, b = 0;
            for (int i = aStr.size() - 1; i >= 0; i--)
            {
                a += pow(10, aStr.size() - 1 - i) * (aStr[i] - '0');
            }
            for (int i = bStr.size() - 1; i >= 0; i--)
            {
                b += pow(10, bStr.size() - 1 - i) * (bStr[i] - '0');
            }
            if (oper1 == "move" && oper2 == "onto")
            {
                MoveOnto(blocks, a, b);
            }
            else if (oper1 == "move" && oper2 == "over")
            {
                MoveOver(blocks, a, b);
            }
            else if (oper1 == "pile" && oper2 == "onto")
            {
                PileOnto(blocks, a, b);
            }
            else if (oper1 == "pile" && oper2 == "over")
            {
                PileOver(blocks, a, b);
            }
        }
        std::cin >> oper;
    }
    for (int i = 0; i < blocks.size(); i++)
    {
        std::cout << i << " :";
        for (int j = 0; j < blocks[0].size(); j++)
        {
            if (blocks[i][j] != -1)
            {
                if (j != 0)
                {
                    std::cout << ' ';
                }
                std::cout << blocks[i][j];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

void MoveOnto(std::vector<std::vector<int>> &blocks, int a, int b)
{
    for (int i = 1; i < blocks[a].size(); i++)
    {
        if (blocks[a][i] != -1)
        {
            blocks[blocks[a][i]][0] = blocks[a][i];
            blocks[a][i] = -1;
        }
    }
    for (int i = 1; i < blocks[b].size(); i++)
    {
        if (blocks[b][i] != -1)
        {
            blocks[blocks[b][i]][0] = blocks[b][i];
            blocks[b][i] = -1;
        }
    }
    blocks[b][1] = blocks[a][0];
    blocks[a][0] = -1;
}

void MoveOver(std::vector<std::vector<int>> &blocks, int a, int b)
{
    for (int i = 1; i < blocks[a].size(); i++)
    {
        if (blocks[a][i] != -1)
        {
            blocks[blocks[a][i]][0] = blocks[a][i];
            blocks[a][i] = -1;
        }
    }
    for (int i = 1; i < blocks[b].size(); i++)
    {
        if (blocks[b][i] != -1)
        {
            blocks[b][i] = blocks[a][0];
            break;
        }
    }
    blocks[a][0] = -1;
}

void PileOnto(std::vector<std::vector<int>> &blocks, int a, int b)
{
    for (int i = 1; i < blocks[b].size(); i++)
    {
        if (blocks[b][i] != -1)
        {
            blocks[blocks[b][i]][0] = blocks[b][i];
            blocks[b][i] = -1;
        }
    }
    for (int i = 0; i < blocks[a].size(); i++)
    {
        if (blocks[a][i] != -1)
        {
            blocks[b][i + 1] = blocks[a][i];
            blocks[a][i] = -1;
        }
    }
}

void PileOver(std::vector<std::vector<int>> &blocks, int a, int b)
{
    int x = 0;
    while (blocks[b][x] != -1)
    {
        x++;
    }
    for (int i = 0; i < blocks[a].size(); i++)
    {
        if (blocks[a][i] != -1)
        {
            blocks[b][x] = blocks[a][i];
            blocks[a][i] = -1;
            x++;
        }
    }
}