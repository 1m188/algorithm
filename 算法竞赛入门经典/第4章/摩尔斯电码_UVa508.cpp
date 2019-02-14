#include "iostream"
#include "string"
#include "map"
#include "vector"

std::vector<std::string> AccurateAddress(std::string mismatch, std::map<std::string, std::string> &word); //精确匹配
std::vector<std::string> FuzzyAddress(std::string mismatch, std::map<std::string, std::string> &word);    //模糊匹配
std::vector<std::string> AddDelChar(std::string mismatch, int n);                                         //模糊匹配中增减字符
std::vector<std::string> AddChar(std::string mismatch, int n);                                            //递归加字符

int main() //代码庞杂，恕不测试，况且书上也没有提供example
{          //关键在于反过来想，既然从编码无法简单的得到单词，那么从单词反过来判断是否会更加容易？之后把词典翻译成编码保存在字典里是关键，另外一个就是在模糊匹配的增减字符那里，可以用递归增加，毕竟每次可以有.和-两种字符增加
    std::vector<std::string> a = AddChar("-", 3);
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }

    std::map<char, std::string> morse{}; //摩尔斯电码
    std::string temp = "";
    for (int i = 0; i < 26; i++) //处理输入的字母编码
    {
        std::cin >> temp;
        morse['a' + i] = temp;
    }
    std::map<std::string, std::string> word{};  //词典
    while (std::cin >> temp && !std::cin.eof()) //输入词典,并且转化为摩尔斯电码形式，储存在字典中
    {
        std::string t = "";
        for (std::string::iterator it = temp.begin(); it != temp.end(); it++)
        {
            t += morse[*it];
        }
        word[t] = temp;
    }
    std::vector<std::string> mismatches{};      //编码
    while (std::cin >> temp && !std::cin.eof()) //输入若干编码
    {
        mismatches.push_back(temp);
    }

    for (std::vector<std::string>::iterator it = mismatches.begin(); it != mismatches.end(); it++)
    {
        std::vector<std::string> addressWords = AccurateAddress(*it, word); //精确匹配
        if (!addressWords.empty())
        {
            std::cout << addressWords[0] << '!' << std::endl; //如果返回来的数组非空，说明有匹配结果
        }
        else //否则精确没戏，上模糊
        {
            addressWords = FuzzyAddress(*it, word);
            std::cout << addressWords[0] << '?' << std::endl;
        }
    }

    return 0;
}

std::vector<std::string> AccurateAddress(std::string mismatch, std::map<std::string, std::string> &word)
{
    std::vector<std::string> accurateWords{};
    for (std::map<std::string, std::string>::iterator it = word.begin(); it != word.end(); it++)
    {
        if (mismatch == it->first)
        {
            accurateWords.push_back(it->second);
        }
    }
    return accurateWords;
}

std::vector<std::string> FuzzyAddress(std::string mismatch, std::map<std::string, std::string> &word)
{
    std::vector<std::string> fuzzyWords{};
    for (int i = 1;; i++)
    {
        std::vector<std::string> temp = AddDelChar(mismatch, i);
        for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++)
        {
            for (std::map<std::string, std::string>::iterator i = word.begin(); i != word.end(); i++)
            {
                if (*it == i->first)
                {
                    fuzzyWords.push_back(i->second);
                }
            }
        }
        if (!fuzzyWords.empty())
        {
            break;
        }
    }
    return fuzzyWords;
}

std::vector<std::string> AddDelChar(std::string mismatch, int n)
{
    std::vector<std::string> result{};

    std::string temp(mismatch);
    for (int i = 0; i < n; i++)
    {
        temp.erase(temp.end() - 1);
    }
    result.push_back(temp);

    std::vector<std::string> tmp = AddChar(mismatch, n);
    for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        result.push_back(*it);
    }

    return result;
}

std::vector<std::string> AddChar(std::string mismatch, int n)
{
    std::vector<std::string> result{};

    if (n == 0)
    {
        result.push_back(mismatch);
        return result;
    }
    else
    {
        std::vector<std::string> temp{};
        temp = AddChar(mismatch + '-', n - 1);
        for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++)
        {
            result.push_back(*it);
        }
        temp = AddChar(mismatch + '.', n - 1);
        for (std::vector<std::string>::iterator it = temp.begin(); it != temp.end(); it++)
        {
            result.push_back(*it);
        }
    }

    return result;
}