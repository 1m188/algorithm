/**
 * @file 7-39 魔法优惠券.cpp
 * @date 2022-05-14
 */

/*
在火星上有个魔法商店，提供魔法优惠券。每个优惠劵上印有一个整数面值K，
表示若你在购买某商品时使用这张优惠劵，可以得到K倍该商品价值的回报！
该商店还免费赠送一些有价值的商品，但是如果你在领取免费赠品的时候使用面值为正的优惠劵，
则必须倒贴给商店K倍该商品价值的金额…… 但是不要紧，还有面值为负的优惠劵可以用！（真是神奇的火星）

例如，给定一组优惠劵，面值分别为1、2、4、-1；对应一组商品，价值为火星币M7、6、−2、−3，
其中负的价值表示该商品是免费赠品。我们可以将优惠劵3用在商品1上，得到M28的回报；
优惠劵2用在商品2上，得到M12的回报；优惠劵4用在商品4上，得到M3的回报。
但是如果一不小心把优惠劵3用在商品4上，你必须倒贴给商店M12。
同样，当你一不小心把优惠劵4用在商品1上，你必须倒贴给商店M7。

规定每张优惠券和每件商品都只能最多被使用一次，求你可以得到的最大回报。

输入格式:
输入有两行。第一行首先给出优惠劵的个数N，随后给出N个优惠劵的整数面值。
第二行首先给出商品的个数M，随后给出M个商品的整数价值。N和M在[1, 10^6]之间，
所有的数据大小不超过2^30，数字间以空格分隔。

输出格式:
输出可以得到的最大回报。

输入样例:
4 1 2 4 -1
4 7 6 -2 -3

输出样例:
43

代码长度限制
16 KB

时间限制
2000 ms

内存限制
64 MB
*/

/* 思路：事实上这个问题问的是，给你两个序列，分别从中任选一个数相乘，每个数最多只能
选一次，问所有乘积的和的最大值是多少？

将两边分别排序，考虑要想求得最大值就要不断地让乘积为正数，而正数*正数=正数，
负数*负数=正数，所以从两端分别遍历，找到所有同为正数和负数的部分，相乘之后
相加，即为最大结果 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> you, // 优惠券
    shang;       // 商品

/**
 * @brief 输入初始化
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;

    cin >> n;
    you.resize(n);
    for (int i = 0; i < n; i++)
        cin >> you[i];

    cin >> n;
    shang.resize(n);
    for (int i = 0; i < n; i++)
        cin >> shang[i];
}

/**
 * @brief 排序并遍历计算
 * @return int 返回最终结果
 */
int calc() {
    int ans = 0;

    sort(you.begin(), you.end());
    sort(shang.begin(), shang.end());

    /* 这里要注意，之前选用的是popback和erase(begin())的方法，超时了，
    看来对vector的元素位置的操作还是挺耗时的，后来只是用索引遍历，只用了
    100+ms */
    for (int i = 0, j = 0; i < you.size() && j < shang.size() && you[i] < 0 && shang[j] < 0; i++, j++)
        ans += you[i] * shang[j];
    for (int i = you.size() - 1, j = shang.size() - 1; i >= 0 && j >= 0 && you[i] > 0 && shang[j] > 0; i--, j--)
        ans += you[i] * shang[j];

    return ans;
}

int main() {
    input();
    cout << calc();
    return 0;
}