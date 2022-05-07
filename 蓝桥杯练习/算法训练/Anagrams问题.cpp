/*
问题描述
　　Anagrams指的是具有如下特性的两个单词：在这两个单词当中，每一个英文字母（不区分大小写）所出现的次数都是相同的。例如，“Unclear”和“Nuclear”、“Rimon”和“MinOR”都是Anagrams。编写一个程序，输入两个单词，然后判断一下，这两个单词是否是Anagrams。每一个单词的长度不会超过80个字符，而且是大小写无关的。
　　输入格式：输入有两行，分别为两个单词。
　　输出格式：输出只有一个字母Y或N，分别表示Yes和No。
　　输入输出样例
样例输入
Unclear
Nuclear
样例输出
Y
*/

#include "iostream"
#include "string"
#include "vector"
#include "cctype"
#include "algorithm"

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;

    for (std::string::iterator it = str1.begin(); it < str1.end(); it++)
    {
        if (isupper(*it))
        {
            *it = tolower(*it);
        }
    }
    for (std::string::iterator it = str2.begin(); it < str2.end(); it++)
    {
        if (isupper(*it))
        {
            *it = tolower(*it);
        }
    }

    std::vector<char> is;
    for (std::string::iterator it = str1.begin(); it < str1.end(); it++)
    {
        if (std::find(is.begin(), is.end(), *it) == is.end())
        {
            if (std::count(str1.begin(), str1.end(), *it) != std::count(str2.begin(), str2.end(), *it))
            {
                std::cout << "N";
                return 0;
            }
            is.push_back(*it);
        }
    }
    std::cout << "Y";

    return 0;
}