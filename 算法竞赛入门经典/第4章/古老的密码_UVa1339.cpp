#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
int main()
{
    std::string s1 = "", s2 = "";
    std::cin >> s1 >> s2;
    std::vector<int> s1Num(26, 0), s2Num(26, 0);
    for (std::string::iterator it = s1.begin(); it != s1.end(); it++)
    {
        s1Num[(*it) - 65]++;
    }
    for (std::string::iterator it = s2.begin(); it != s2.end(); it++)
    {
        s2Num[(*it) - 65]++;
    }
    std::sort(s1Num.begin(), s1Num.end());
    std::sort(s2Num.begin(), s2Num.end());
    if (s1Num == s2Num)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}