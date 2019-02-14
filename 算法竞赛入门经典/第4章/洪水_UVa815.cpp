#include "iostream"
#include "vector"
#include "algorithm"
int main() //emmmmmmm，题目不是很好理解，理解了之后还是很轻松的，关键在于如何判定洪水向下淹没下一个格子，之后还要在海平面平齐的时候判定等等
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<int> altitude(n * m, 0);
    for (int i = 0; i < n * m; i++)
    {
        std::cin >> altitude[i];
    }
    std::sort(altitude.begin(), altitude.end());
    int rainV = 0;
    std::cin >> rainV;
    rainV /= 100;

    for (int k = 1; k <= n * m; k++)
    {
        rainV += altitude[k - 1];
        if (rainV / k < altitude[k])
        {
            std::cout << k << std::endl;
            return 0;
        }
    }
    std::cout << n * m << std::endl;

    return 0;
}

//另附网上的思路
// 可以把n*m块地的海拔高度a[i]，按从小到大排成一列。
// 然后对输入的洪水体积，先除以100，这样一来，题目中的所有数据就统一了数量单位。
// 如样例的洪水体积为10000，转化为高度就是sum=100。
// 接着设一个偏移量k，代表洪水从左往右淹到第k块地时停止。
// 算法为k从1开始递增遍历，洪水每路过一块地，就把地的高度加入sum，退出条件就是洪水的平均高度不大于下一块地：sum/k < a[k+1]。