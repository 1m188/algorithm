/*

约瑟夫环问题

*/

#include "iostream"
#include "list"
#include "vector"

/*********************************************************************************************************/

// 数组实现
// vec是人的编号数组，ln是最后要活下来的人数，dn是报到第几个出局的号码
void Joseph(std::vector<int> &vec, const int &ln, const int &dn)
{
    if (vec.empty() || ln <= 0 || dn <= 0)
        return;

    auto it = vec.begin();
    while (vec.size() > ln)
    {
        for (int i = 1; i < dn; i++)
            if (++it == vec.end())
                it = vec.begin();
        if ((it = vec.erase(it)) == vec.end())
            it = vec.begin();
    }
}

// 链表实现
void Joseph(std::list<int> &li, const int &ln, const int &dn)
{
    if (li.empty() || ln <= 0 || dn <= 0)
        return;

    auto it = li.begin();
    while (li.size() > ln)
    {
        for (int i = 1; i < dn; i++)
            if (++it == li.end())
                it++;
        if ((it = li.erase(it)) == li.end())
            it++;
    }
}

/*********************************************************************************************************/

int main(int argc, char *argv[])
{
    const int ln = 10, dn = 3, pn = 20;
    printf("Joseph: %d people - %d dead number - remain %d\n\n", pn, dn, ln);

    std::cout << "vector\n";
    std::vector<int> vec;
    for (int i = 1; i <= pn; i++)
        vec.push_back(i);
    Joseph(vec, ln, dn);

    for (const auto &e : vec)
        std::cout << e << ' ';
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "list\n";
    std::list<int> li;
    for (int i = 1; i <= pn; i++)
        li.push_back(i);
    Joseph(li, ln, dn);

    for (const auto &e : li)
        std::cout << e << ' ';
    std::cout << std::endl;

    return 0;
}