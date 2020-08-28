/*

转换各种进制

*/

#include "cctype"
#include "cmath"
#include "iostream"
#include "string"

// 二进制转十进制
int bin2dec(const std::string &num)
{
    for (const char &c : num)
        if (c != '0' && c != '1')
            return -1;

    int res = 0;

    for (int i = 0; i < num.size(); i++)
        if (num[i] == '1')
            res += pow(2, num.size() - 1 - i);

    return res;
}

// 十六进制转十进制
int hex2dec(const std::string &num)
{
    for (const char &c : num)
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
            return -1;

    int res = 0;

    for (int i = 0; i < num.size(); i++)
        res += (isalpha(num[i]) ? (tolower(num[i]) - 'a' + 10) : (num[i] - '0')) * pow(16, num.size() - 1 - i);

    return res;
}

int main(int argc, char *argv[])
{
    std::cout << bin2dec("1010") << '\n'
              << hex2dec("FFFf") << '\n';

    return 0;
}