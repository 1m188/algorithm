#include "iostream"
#include "map"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
int main() //算法思想是，枚举所有的列数，然后扫描行，把相应的行列内容放到set里，如果有重复的话，说明有相同的
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dataBase(n, std::vector<int>(m, -1));
    std::map<std::string, int> mp{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::string temp = "";
            if (i == 0 && j == 0) //这里由于下面用了getline函数，所以要把上面输入时候的回车键给丢弃，“吃掉”
            {
                std::cin.get();
            }
            std::getline(std::cin, temp);
            if (mp.find(temp) == mp.end())
            {
                mp[temp] = mp.size();
            }
            dataBase[i][j] = mp[temp];
        }
    }

    std::set<std::pair<int, int>> judge{};
    for (int c1 = 0; c1 < m - 1; c1++)
    {
        for (int c2 = c1 + 1; c2 < m; c2++)
        {
            for (int r = 0; r < n; r++)
            {
                if (std::find(judge.begin(), judge.end(), std::pair<int, int>{dataBase[r][c1], dataBase[r][c2]}) == judge.end())
                {
                    judge.insert(std::pair<int, int>{dataBase[r][c1], dataBase[r][c2]});
                }
                else
                {
                    std::cout << "Yes" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << std::endl;

    return 0;
}