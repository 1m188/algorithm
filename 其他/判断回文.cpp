//判断一个字符串是否正着和反着是一样的

#include "string"
#include "algorithm"

bool judgePalindrome(const std::string &str)
{
    std::string newstr(str);
    reverse(newstr.begin(), newstr.end());
    return newstr == str;
}