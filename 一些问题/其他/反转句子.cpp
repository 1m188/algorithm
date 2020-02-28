//给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格.
//比如： （1） “hello xiao mi”-> “mi xiao hello”

#include "string"
#include "vector"

std::string reserveWords(const std::string &str)
{
    std::string tempStr = "";
    std::vector<std::string> tempVector(0);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            tempVector.push_back(tempStr);
            tempStr.clear();
        }
        else
        {
            tempStr += str[i];
        }
    }
    tempVector.push_back(tempStr);
    tempStr.clear();

    for (std::vector<std::string>::reverse_iterator rit = tempVector.rbegin(); rit != tempVector.rend(); rit++)
    {
        tempStr += *rit;
        tempStr += ' ';
    }
    tempStr.erase(tempStr.end() - 1);

    return tempStr;
}