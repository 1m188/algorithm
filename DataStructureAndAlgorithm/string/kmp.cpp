/*

kmp

*/

#include "iostream"
#include "string"
#include "vector"

// 获得next数组
std::vector<int> get_next(const std::string &s)
{
    std::vector<int> next(s.size(), -1);
    for (int i = 1; i < next.size(); i++)
    {
        int idx = next[i - 1];
        while (idx >= 0 && s[idx] != s[i - 1])
            idx = next[idx];
        next[i] = idx + 1;
    }
    return next;
}

// kmp
int kmp(const std::string &str, const std::string &s)
{
    auto &&next = get_next(s);
    int stri = 0, si = 0;
    while (stri < str.size() && si < s.size())
        if (str[stri] == s[si] || (si = next[si]) == -1)
            stri++, si++;
    return si >= s.size() ? stri - s.size() : -1;
}

int main(int argc, char *argv[])
{
    std::string str = "googloogle", s = "google";
    std::cout << kmp(str, s) << '\n';

    str = "asdasadffigk", s = "das";
    std::cout << kmp(str, s) << '\n';

    return 0;
}