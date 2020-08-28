
// 手链样式

// 小明有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙。
// 他想用它们串成一圈作为手链，送给女朋友。
// 现在小明想知道：如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？

// 请你提交该整数。不要填写任何多余的内容或说明性的文字。

#include "algorithm"
#include "iostream"
#include "string"
#include "vector"

bool cmp(const std::vector<std::string> &vec, const std::string &str)
{
    std::string s = str + str, ss = s;
    std::reverse(ss.begin(), ss.end());
    for (const std::string &e : vec)
        if (s.find(e) != std::string::npos || ss.find(e) != std::string::npos)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> vec;
    std::string lace = "rrrwwwwyyyyy";
    vec.push_back(lace);
    while (std::next_permutation(lace.begin(), lace.end()))
        if (cmp(vec, lace))
            vec.push_back(lace);

    // std::cout << 1170;
    std::cout << vec.size();

    return 0;
}