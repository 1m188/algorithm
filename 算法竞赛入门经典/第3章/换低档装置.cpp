#include "iostream"
#include "vector"
#include "algorithm"

int main()
{
    int n1 = 0, n2 = 0;
    std::cin >> n1 >> n2;
    std::vector<int> N1{}, N2{};
    for (int i = 0; i < n1; i++)
    {
        int h = 0;
        std::cin >> h;
        while (h != 1 && h != 2)
        {
            std::cin >> h;
        }
        N1.push_back(h);
    }
    for (int i = 0; i < n2; i++)
    {
        int h = 0;
        std::cin >> h;
        while (h != 1 && h != 2)
        {
            std::cin >> h;
        }
        N2.push_back(h);
    }

    int nMin = n1 < n2 ? n1 : n2;
    int nMax = n1 > n2 ? n1 : n2;
    int lengthMin = nMax;
    for (int num = 0; num < 4; num++)
    {
        for (int i = 0; i < nMin; i++)
        {
            if (N1[i] + N2[i] > 3)
            {
                N2.insert(N2.begin(), 0);
                n2++;
                nMin = n1 < n2 ? n1 : n2;
                i = -1;
            }
        }
        nMax = n1 > n2 ? n1 : n2;
        if (num == 0)
        {
            lengthMin = nMax;
        }
        else
        {
            lengthMin = lengthMin < nMax ? lengthMin : nMax;
        }
        for (std::vector<int>::iterator it = N2.begin(); it != N2.end();)
        {
            if (*it == 0)
            {
                N2.erase(it);
            }
            else
            {
                it++;
            }
        }
        n2 = N2.size();
        nMin = n1 < n2 ? n1 : n2;

        if (num == 0)
        {
            reverse(N2.begin(), N2.end());
            reverse(N1.begin(), N1.end());
        }
        else if (num == 1)
        {
            reverse(N1.begin(), N1.end());
        }
        else if (num == 2)
        {
            reverse(N2.begin(), N2.end());
            reverse(N1.begin(), N1.end());
        }
    }

    std::cout << lengthMin << std::endl;

    return 0;
}