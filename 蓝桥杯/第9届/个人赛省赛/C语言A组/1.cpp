
// 标题：分数

// 1/1 + 1/2 + 1/4 + 1/8 + 1/16 + ....
// 每项是前一项的一半，如果一共有20项,
// 求这个和是多少，结果用分数表示出来。
// 类似：
// 3/2
// 当然，这只是加了前2项而已。分子分母要求互质。

// 注意：
// 需要提交的是已经约分过的分数，中间任何位置不能含有空格。
// 请不要填写任何多余的文字或符号。

#include "cmath"
#include "iostream"

// 辗转相除法
long long gcd(long long a, long long b)
{
    if (a == 0 || b == 0)
        return a == 0 ? b : a;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}

int main()
{
    long long fenzi = pow(2, 20) - 1, fenmu = pow(2, 19);

    long long g = gcd(fenzi, fenmu);

    std::cout << fenzi / g << '/' << fenmu / g;

    return 0;
}
