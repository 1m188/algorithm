
// 奇妙的数字

// 小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
// 你能猜出这个数字是多少吗？

// 请填写该数字，不要填写任何多余的内容。

#include "iostream"
#include "vector"

bool number(uint32_t num)
{
    std::vector<bool> flags(10, false);
    while (num)
    {
        int t = num % 10;
        if (flags[t])
            return false;
        flags[t] = true;
        num /= 10;
    }

    for (const bool e : flags)
        if (!e)
            return false;

    return true;
}

int main(int argc, char *argv[])
{
    uint32_t n = 1;
    while (!(number(n * n) && number(n * n * n)))
        n++;

    std::cout << n;

    return 0;
}