/*
问题描述
　　给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
　　输出n行，每行为输入对应的八进制正整数。

　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。

样例输入
　　2
　　39
　　123ABC

样例输出
　　71
　　4435274

　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/

//先将十六进制每位转换成四位二进制数，之后在二进制数前面补零，直到位数能够被三整除，之后从左到右每三位得到一个八进制位，从左往右排好即为所求的八进制数

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

std::string hexToBin(const std::string &hex)
{
    std::string bin;
    for (int i = 0; i < hex.size(); i++)
    {
        const char &c = hex[i];
        std::string t;

        int num = 0;
        if (c >= '0' && c <= '9')
        {
            num = c - '0';
        }
        else
        {
            num = c - 'A' + 10;
        }

        while (num)
        {
            t.push_back(num % 2 + '0');
            num /= 2;
        }
        while (t.size() < 4)
        {
            t.push_back('0');
        }
        std::reverse(t.begin(), t.end());

        bin.append(t);
    }
    return bin;
}

std::string binToOct(std::string bin)
{
    while (bin.size() % 3 != 0)
    {
        bin.insert(bin.begin(), '0');
    }

    std::string oct;
    for (int i = 0; i < bin.size(); i += 3)
    {
        oct.push_back((bin[i] - '0') * 4 + (bin[i + 1] - '0') * 2 + (bin[i + 2] - '0') + '0');
    }
    for (std::string::iterator it = oct.begin(); it < oct.end();)
    {
        if (*it != '0')
        {
            break;
        }
        else
        {
            oct.erase(it);
        }
    }
    return oct;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::string> hexNum(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> hexNum[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << binToOct(hexToBin(hexNum[i])) << std::endl;
    }

    return 0;
}