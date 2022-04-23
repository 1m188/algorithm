
// 方程整数解

// 方程: a^2 + b^2 + c^2 = 1000

// 这个方程有整数解吗？有：a,b,c=6,8,30 就是一组解。
// 你能算出另一组合适的解吗？

// 请填写该解中最小的数字。

// 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

#include "cmath"
#include "iostream"

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int main(int argc, char *argv[])
{
    int a = 0, b = 0, c = 0;
    for (a = 0; a <= sqrt(1000); a++) // 正负数皆可，但本题并不是算最小的解，而是另一组合适解中的最小一个
        for (b = 0; b <= 1000 - a * a; b++)
            for (c = 0; c <= 1000 - a * a - b * b; c++)
                if (a * a + b * b + c * c == 1000)
                    goto outside;
outside:
    std::cout << min(a, b, c); // 这里算出来的解为  0，10，30  最小为0

    return 0;
}