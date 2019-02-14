#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
int main() //只需用一个记录数组保存所有的曾经的结果，然后每有一个新的n元组产生则查找，以及比对这个n元组和0元组，有任何一方成立则输出相应结果
{
    int n = 0;
    std::cin >> n;
    std::vector<int> nTuple(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nTuple[i];
    }

    std::vector<std::vector<int>> record{};
    record.push_back(nTuple);
    for (int i = 0; i < 1000; i++)
    {
        std::vector<int> temp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                temp[i] = abs(nTuple[i] - nTuple[i + 1]);
            }
            else
            {
                temp[i] = abs(nTuple[i] - nTuple[0]);
            }
        }
        nTuple = temp;
        if (nTuple == std::vector<int>(n, 0))
        {
            std::cout << "become zero\n";
            break;
        }
        else if (std::find(record.begin(), record.end(), nTuple) != record.end())
        {
            std::cout << "become cycle\n";
            break;
        }
        else
        {
            record.push_back(nTuple);
        }
    }

    return 0;
}