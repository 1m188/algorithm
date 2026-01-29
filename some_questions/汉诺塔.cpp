/*

有三根柱子，x，y，z，第一根柱子上有n个盘子，从上到下依次增大，要求将第一根柱子上的盘子移动到第三根柱子上，整个
过程都必须满足一根柱子上的盘子从上到下依次增大

*/

#include "iostream"

void Han(int x, int y, int z, int n, long long &num)
{
    if (n == 1)
        num++;
    else
    {
        Han(x, z, y, n - 1, num);
        num++;
        Han(y, x, z, n - 1, num);
    }
}

int main(int argc, char *argv[])
{
    long long num = 0;
    Han(0, 0, 0, 10, num); // 10个盘子
    std::cout << num << '\n';

    return 0;
}