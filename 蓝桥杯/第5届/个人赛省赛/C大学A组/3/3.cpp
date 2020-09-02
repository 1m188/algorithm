
// 如果x的x次幂结果为10（参见【图1.png】），你能计算出x的近似值吗？

// 显然，这个值是介于2和3之间的一个数字。

// 请把x的值计算到小数后6位（四舍五入），并填写这个小数值。

// 注意：只填写一个小数，不要写任何多余的符号或说明。

#include "cmath"
#include "cstdio"

float gx(float x = 2, float y = 3, int d = 1)
{
    if (d >= 7)
        return (x + y) / 2;

    float xy = (x + y) / 2;
    float r = powf(xy, xy);
    return r > 10 ? gx(x, xy, d + 1) : gx(xy, y, d + 1);
}

int main(int argc, char *argv[])
{
    printf("%.6f", gx() + 0.0000005);

    return 0;
}