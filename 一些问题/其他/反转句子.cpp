/*

给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格.
比如： （1） “hello xiao mi”-> “mi xiao hello”

*/

#include "iostream"
#include "string"
#include "vector"

std::string reverseWords(const std::string &str)
{
    std::string tempStr = "";
    std::vector<std::string> tempVector;

    for (const char &c : str)
        if (c == ' ')
        {
            tempVector.push_back(tempStr);
            tempStr.clear();
        }
        else
            tempStr.push_back(c);
    tempVector.push_back(tempStr);
    tempStr.clear();

    for (auto crit = tempVector.crbegin(); crit != tempVector.crend(); crit++)
    {
        tempStr.append(*crit);
        tempStr.push_back(' ');
    }
    tempStr.pop_back();

    return tempStr;
}

int main(int argc, char *argv[])
{
    std::string str = "hello xiao mi", &&res = reverseWords(str);
    std::cout << str << '\n'
              << res << '\n';

    return 0;
}