#include "list"
#include "algorithm"

std::list<int> Josephus(const int pn, const int ln, const int dn) //pn是总的参与环中的人数，ln是最后要活下来的人数，dn是报到第几个出局的号码
{
    if (pn <= 0 || dn <= 0 || ln <= 0)
    {
        return static_cast<std::list<int>>(0);
    }
    else
    {
        std::list<int> people(0);
        for (int i = 0; i < pn; i++)
        {
            people.push_back(i + 1);
        }
        std::list<int>::iterator it = people.begin();
        for (int i = 0; i < pn - ln; i++)
        {
            for (int j = 0; j < dn; j++)
            {
                if (j == dn - 1)
                {
                    it = people.erase(it);
                }
                else
                {
                    it++;
                }
                if (++it != people.begin())
                {
                    it--;
                }
            }
        }
        return people;
    }
}