#include "vector"
#include "algorithm"

std::vector<int> Josephus(const int pn, const int ln, const int dn) // pn是总的人数，ln是最后要活下来的人数，dn是报到第几个出局的号码
{
    if (pn <= 0 || ln <= 0 || dn <= 0)
    {
        return static_cast<std::vector<int>>(0);
    }
    else
    {
        std::vector<int> people(0);
        for (int i = 0; i < pn; i++)
        {
            people.push_back(i + 1);
        }
        std::vector<int>::iterator it = people.begin();
        for (int i = 0; i < pn - ln; i++)
        {
            for (int j = 0; j < dn; j++)
            {
                if (j == dn - 1)
                {
                    if (it == people.end() - 1)
                    {
                        people.erase(it);
                        it = people.begin();
                    }
                    else
                    {
                        people.erase(it);
                    }
                }
                else
                {
                    if (it == people.end() - 1)
                    {
                        it = people.begin();
                    }
                    else
                    {
                        it++;
                    }
                }
            }
        }
        return people;
    }
}