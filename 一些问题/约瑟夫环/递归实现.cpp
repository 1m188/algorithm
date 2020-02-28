#include "list"
#include "algorithm"

std::list<int> Josephus(const int pn, const int ln, const int dn, std::list<int> &people, std::list<int>::iterator &it, bool isfirst) //pn总人数，ln需要活下来的人数，dn出局号码，people为此时游戏中的人并存储了他们的初始号码，it为一个指向期中的迭代器，isfirst表示此次递归是否为第一次递归
{
    if (pn <= 0 || ln <= 0 || dn <= 0)
    {
        return static_cast<std::list<int>>(0);
    }
    else if (isfirst)
    {
        people.clear();
        for (int i = 0; i < pn; i++)
        {
            people.push_back(i + 1);
        }
        it = people.begin();
        return Josephus(pn, ln, dn, people, it, false);
    }
    else
    {
        if (pn == ln)
        {
            return people;
        }
        else
        {
            for (int i = 0; i < dn; i++)
            {
                if (i == dn - 1)
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
            return Josephus(pn - 1, ln, dn, people, it, false);
        }
    }
}