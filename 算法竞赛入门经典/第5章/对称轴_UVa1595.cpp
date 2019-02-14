#include "iostream"
#include "vector"
#include "algorithm"
int main() //直接模拟
{
    int n = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> points{};
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        points.push_back(std::pair<int, int>{x, y});
    }
    std::sort(points.begin(), points.end(), [&](std::pair<int, int> a, std::pair<int, int> b) -> bool { return a.first > b.first; });

    int pointsx = (points[0].first + points.back().first) / 2;

    for (std::vector<std::pair<int, int>>::iterator it = points.begin(); it != points.end(); it++)
    {
        std::pair<int, int> temp{};
        temp.first = 2 * pointsx - it->first;
        temp.second = it->second;
        if (std::find(points.begin(), points.end(), temp) == points.end())
        {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";

    return 0;
}