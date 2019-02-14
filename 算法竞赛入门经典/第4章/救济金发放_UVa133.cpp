#include "iostream"
#include "list"
int main()
{
    int n = 0, k = 0, m = 0;
    std::cin >> n >> k >> m;
    std::list<int> p{};
    for (int i = 0; i < n; i++)
    {
        p.push_back(i + 1);
    }

    std::list<int>::iterator itk = p.begin();
    std::list<int>::iterator itm = p.end();
    itm--;
    while (p.size())
    {
        if (itk == p.end())
        {
            itk++;
        }
        for (int i = 1; i < k; i++)
        {
            itk++;
            if (itk == p.end())
            {
                itk++;
            }
        }
        if (itm == p.end())
        {
            itm--;
        }
        for (int i = 1; i < m; i++)
        {
            itm--;
            if (itm == p.end())
            {
                itm--;
            }
        }
        if (*itk == *itm)
        {
            std::cout << *itk;
            itm--;
            itk = p.erase(itk);
            if (p.size())
            {
                std::cout << "  ,";
            }
        }
        else
        {
            std::cout << *itk << ' ' << *itm << ',';
            itk = p.erase(itk);
            if (itk == itm)
            {
                itk++;
            }
            itm = p.erase(itm);
            itm--;
        }
    }
    std::cout << std::endl;

    return 0;
}