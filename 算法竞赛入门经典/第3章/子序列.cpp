#include "iostream"
#include "string"
int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::string::iterator its = s.begin();
    std::string::iterator itt = t.begin();

    while (itt != t.end())
    {
        if (*its == *itt)
        {
            its++;
            itt++;
        }
        else
        {
            itt++;
        }
    }

    if (its == s.end())
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }

    return 0;
}