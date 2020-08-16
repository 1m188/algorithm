/*

判断一个字符串是否正着和反着是一样的

*/

#include "algorithm"
#include "iostream"
#include "string"

bool judgePalindrome(const std::string &str)
{
    std::string newstr(str);
    std::reverse(newstr.begin(), newstr.end());
    return newstr == str;
}

bool judge(const std::string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
        if (str[left++] != str[right--])
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    std::cout << judgePalindrome("asdsa") << '\n'
              << judgePalindrome("asd") << '\n';

    std::cout << '\n';

    std::cout << judge("asdsa") << '\n'
              << judge("asd") << '\n';

    return 0;
}