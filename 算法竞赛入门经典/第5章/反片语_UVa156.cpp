#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "cctype"
#include "algorithm"
int main() //将每个单词的字母做成数组并且排好序存起来，做一个映射，之后看是否有其他的单词的字母组成和该单词相同，如果有，则有其他的单词能够通过字母排序得到这个单词，否则存进数组，之后字典序排列，输出即可
{
    std::vector<std::string> words{};
    std::string temp = "";
    while (std::cin >> temp && temp != "#")
    {
        words.push_back(temp);
    }
    std::map<std::string, std::vector<char>> judge{};
    for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
    {
        std::vector<char> t{};
        std::string s = *it;
        judge[s] = t;
        for (std::string::iterator i = it->begin(); i != it->end(); i++)
        {
            *i = tolower(*i);
            t.push_back(*i);
        }
        std::sort(t.begin(), t.end());
        judge[s] = t;
    }

    std::vector<std::string> result{};
    for (std::map<std::string, std::vector<char>>::iterator it = judge.begin(); it != judge.end(); it++)
    {
        for (std::map<std::string, std::vector<char>>::iterator i = judge.begin(); i != judge.end(); i++)
        {
            if (i != it && i->second == it->second)
            {
                goto next;
            }
        }
        result.push_back(it->first);
    next:;
    }
    std::sort(result.begin(), result.end());
    for_each(result.begin(), result.end(), [&](std::string i) { std::cout << i << std::endl; });

    return 0;
}