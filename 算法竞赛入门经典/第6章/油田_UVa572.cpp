#include "iostream"
#include "vector"
#include "queue"

int find(std::vector<std::vector<bool>> charMat); //BFS查找联通块

int main()
{
    int m = 0, n = 0;
    std::cin >> m >> n;
    std::vector<std::vector<bool>> charMat(m, std::vector<bool>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c{};
            std::cin >> c;
            if (c == '@')
            {
                charMat[i][j] = 1;
            }
        }
    }
    std::cout << find(charMat) << std::endl;

    return 0;
}

int find(std::vector<std::vector<bool>> charMat)
{
    int num = 0;
    std::queue<std::pair<int, int>> pos{};

    for (int i = 0; i < charMat.size(); i++)
    {
        for (int j = 0; j < charMat[0].size(); j++)
        {
            if (charMat[i][j] == 1)
            {
                int cal = 0;
                pos.push(std::pair<int, int>{i, j});
                do
                {
                    cal++;
                    int x = pos.front().first;
                    int y = pos.front().second;
                    charMat[x][y] = 0;
                    pos.pop();

                    if (x - 1 >= 0 && charMat[x - 1][y] == 1)
                    {
                        pos.push(std::pair<int, int>{x - 1, y});
                    }
                    if (x + 1 < charMat.size() && charMat[x + 1][y] == 1)
                    {
                        pos.push(std::pair<int, int>{x + 1, y});
                    }
                    if (y - 1 >= 0 && charMat[x][y - 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x, y - 1});
                    }
                    if (y + 1 < charMat[0].size() && charMat[x][y + 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x, y + 1});
                    }
                    if (x - 1 >= 0 && y - 1 >= 0 && charMat[x - 1][y - 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x - 1, y - 1});
                    }
                    if (x - 1 >= 0 && y + 1 < charMat[0].size() && charMat[x - 1][y + 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x - 1, y + 1});
                    }
                    if (x + 1 < charMat.size() && y - 1 >= 0 && charMat[x + 1][y - 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x + 1, y - 1});
                    }
                    if (x + 1 < charMat.size() && y + 1 < charMat[0].size() && charMat[x + 1][y + 1] == 1)
                    {
                        pos.push(std::pair<int, int>{x + 1, y + 1});
                    }

                } while (!pos.empty());
                if (cal > 1)
                {
                    num++;
                }
            }
        }
    }
    return num;
}