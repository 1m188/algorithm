/*
Description
给定一个字符串，要求将大写字母变成小写字母，再将字符串输出（要求使用指针）
PS：不要使用cin.getline(),注意行末有换行

Input
第一行输入一个t（小于100），接下来每一行输入一个字符串str（长度小于1000）

Output
输出处理后的字符串

Sample Input
2
FontSize
ADS

Sample Output
fontsize
ads
*/

#include "iostream"
#include "cctype"
#include "vector"
#include "string"
int main() //PE。晕...
{
    int t = 0;
    std::cin >> t;
    std::vector<std::string> s(t, "");
    for (int i = 0; i < t; i++)
    {
        std::cin >> s[i];
    }

    for (std::vector<std::string>::iterator it = s.begin(); it != s.end(); it++)
    {
        for (std::string::iterator c = (*it).begin(); c != (*it).end(); c++)
        {
            if (isupper(*c))
            {
                *c = tolower(*c);
            }
        }
        std::cout << *it << std::endl;
    }

    return 0;
}