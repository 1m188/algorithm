#include "iostream"
#include "vector"
#include "algorithm"
int main()
{
    int n = 0, q = 0, kcase = 1;
    while (std::cin >> n >> q && !std::cin.eof() && n)
    {
        std::vector<int> marble(n, 0);
        for (int i = 0; i < n; i++)
        {
            std::cin >> marble[i];
        }
        std::sort(marble.begin(), marble.end());
        std::vector<int> question(q, 0);
        for (int i = 0; i < q; i++)
        {
            std::cin >> question[i];
        }
        std::cout << "CASE# " << kcase << " :" << std::endl;
        for (std::vector<int>::iterator it = question.begin(); it != question.end(); it++)
        {
            std::vector<int>::iterator f = std::find(marble.begin(), marble.end(), *it);
            if (f == marble.end())
            {
                std::cout << *it << " not found" << std::endl;
            }
            else
            {
                std::cout << *it << " found at " << std::distance(marble.begin(), f) + 1 << std::endl;
            }
        }
    }

    return 0;
}