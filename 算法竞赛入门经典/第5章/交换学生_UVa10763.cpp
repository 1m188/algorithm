#include "iostream"
#include "vector"
#include "algorithm"
int main() //直接模拟
{
    int n = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> student(n, std::pair<int, int>{});
    for (int i = 0; i < n; i++)
    {
        int A = 0, B = 0;
        std::cin >> A >> B;
        student.push_back(std::pair<int, int>{A, B});
    }

    for (std::vector<std::pair<int, int>>::iterator it = student.begin(); it != student.end();)
    {
        std::vector<std::pair<int, int>>::iterator t = std::find(student.begin(), student.end(), std::pair<int, int>{it->second, it->first});
        if (t == student.end())
        {
            std::cout << "No\n";
            return 0;
        }
        else
        {
            student.erase(t);
            student.erase(it);
        }
    }
    std::cout << "Yes\n";

    return 0;
}