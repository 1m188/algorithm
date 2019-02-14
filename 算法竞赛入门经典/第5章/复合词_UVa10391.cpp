#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
int main() //直接模拟
{
    int n = 0;
    std::cin >> n;
    std::vector<std::string> dict(n, "");
    for (int i = 0; i < n; i++)
    {
        std::cin >> dict[i];
    }

    for (std::vector<std::string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        for (int i = 0; i < it->size() - 1; i++)
        {
            if (std::find(dict.begin(), dict.end(), it->substr(0, i + 1)) != dict.end() && std::find(dict.begin(), dict.end(), it->substr(i + 1)) != dict.end())
            {
                std::cout << *it << std::endl;
                break;
            }
        }
    }

    return 0;
}