#include "iostream"
#include "set"
#include "string"
#include "cctype"
#include "sstream"
int main()
{
    std::set<std::string> dict{};
    std::string temp = "";
    while (std::cin >> temp && !std::cin.eof())
    {
        for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
        {
            if (isalpha(*it))
            {
                *it = tolower(*it);
            }
            else
            {
                *it = ' '; //非字母的字符全部置空
            }
        }
        std::stringstream ss(temp); //用来取消首尾空格的
        ss >> temp;
        dict.insert(temp); //set自动去掉所有的重复元素并且按照从小到大的顺序排列好
    }

    for (std::set<std::string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}