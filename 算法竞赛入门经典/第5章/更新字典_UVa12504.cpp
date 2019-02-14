#include "iostream"
#include "map"
#include "string"
#include "vector"
int main() //直接模拟，注意std::map是加入元素自动排序的
{
    std::map<std::string, std::string> oldDict{}, newDict{};
    std::string input = "";

    for (int i = 0; i < 2; i++)
    {
        std::getline(std::cin, input);
        input.erase(input.begin());
        input.erase(input.end());
        input += ',';
        while (!input.empty())
        {
            std::string key = input.substr(0, input.find(':'));
            std::string value = input.substr(input.find(':') + 1, input.find(',') - input.find(':') - 1);
            if (i == 0)
            {
                oldDict[key] = value;
            }
            else
            {
                newDict[key] = value;
            }
            input.erase(input.begin(), input.begin() + input.find(',') + 1);
        }
    }

    std::map<std::string, std::string>::iterator oldIt = oldDict.begin(), newIt = newDict.begin();
    std::vector<std::vector<std::string>> changes(3, std::vector<std::string>{});
    while (oldIt != oldDict.end() && newIt != newDict.end()) //对两个字典从头到尾遍历判断
    {
        if (oldIt->first == newIt->first)
        {
            if (oldIt->second != newIt->second)
            {
                changes[2].push_back(newIt->first);
            }
            oldIt++, newIt++;
        }
        else
        {
            if (oldIt->first < newIt->first)
            {
                changes[1].push_back(oldIt->first);
                oldIt++;
            }
            else
            {
                changes[0].push_back(newIt->first);
                newIt++;
            }
        }
    }
    while (oldIt != oldDict.end())
    {
        changes[1].push_back(oldIt->first);
        oldIt++;
    }
    while (newIt != newDict.end())
    {
        changes[0].push_back(newIt->first);
        newIt++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            std::cout << '+';
        }
        else if (i == 1)
        {
            std::cout << '-';
        }
        else if (i == 2)
        {
            std::cout << '*';
        }
        for (std::vector<std::string>::iterator it = changes[i].begin(); it != changes[i].end(); it++)
        {
            std::cout << *it;
            if (it != changes[i].end() - 1)
            {
                std::cout << ',';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}