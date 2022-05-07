/*
Description
对于给定的一个字符串，统计其中数字字符出现的次数。

Input
输入数据有多行，第一行是一个整数n，表示测试实例的个数，后面跟着n行，每行包括一个由字母和数字组成的字符串。

Output
对于每个测试实例，输出该串中数值的个数，每个输出占一行。

Sample Input
2
asdfasdf123123asdfasdf
asdf111111111asdfasdfasdf

Sample Output
6
9
*/

#include "iostream"
#include "string"
#include "vector"
#include "cctype"
int main() //AC
{
    int n = 0;
    std::cin >> n;
    std::vector<std::string> test(n, "");
    for (int i = 0; i < n; i++)
    {
        std::cin >> test[i];
    }

    for (std::vector<std::string>::iterator it = test.begin(); it != test.end(); it++)
    {
        int num = 0;
        for (std::string::iterator c = (*it).begin(); c != (*it).end(); c++)
        {
            if (isdigit(*c))
            {
                num++;
            }
        }
        std::cout << num << std::endl;
    }

    return 0;
}