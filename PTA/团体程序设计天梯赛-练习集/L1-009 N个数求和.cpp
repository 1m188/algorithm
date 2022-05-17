/**
 * @file L1-009 N个数求和.cpp
 * @date 2022-05-17
 */

/*
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数分子/分母的形式给出的，
你输出的和也必须是有理数的形式。

输入格式：
输入第一行给出一个正整数N（≤100）。随后一行按格式a1/b1 a2/b2 ...给出N个有理数。
题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：
输出上述数字和的最简形式 —— 即将结果写成整数部分 分数部分，其中分数部分写成分子/分母，
要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3

输出样例1：
3 1/3

输入样例2：
2
4/3 2/3

输出样例2：
2

输入样例3：
3
1/3 -1/6 1/8

输出样例3：
7/24

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 化简分数用gcd，注意格式输出，尤其是结果为0的时候 */

#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

long long fz = 0, // 当前分数分子
    fm = 1,       // 当前分数分母
    itg = 0;      // 当前分数整数部分（假分数）

/**
 * @brief 辗转相除法求最大公约数（妙啊，简洁而优雅，看的网上人家写的）
 * @param a 两数之一
 * @param b 两数之二
 * @return long long 结果
 */
long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

/**
 * @brief 将两个分数加起来，并且化简
 * @param pfz 待被加的分数的分子
 * @param pfm 待被加的分数的分母
 */
void add(long long pfz, long long pfm) {

    fz = fz * pfm + fm * pfz;
    fm *= pfm;

    long long g = gcd(abs(fz), fm);
    fm /= g, fz /= g;

    itg += fz / fm;
    fz = fz % fm;
}

/**
 * @brief 输入并计算
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    while (n--) {

        string s;
        cin >> s;
        for (char &c : s)
            if (c == '/') { // 这里要分开分子和分母居然还要通过流分割/，如果cin能有scanf那样简单的输入方式就好了
                c = ' ';
                break;
            }

        stringstream ss(s);
        long long xfz = 0, xfm = 0;
        ss >> xfz >> xfm;

        add(xfz, xfm);
    }

    // 按要求输出，注意为零的时候
    if (itg) {
        cout << itg;
        if (fz)
            cout << ' ' << fz << '/' << fm;
    } else if (fz)
        cout << fz << '/' << fm;
    else
        cout << 0; // 注意！！！！！！结果为零的时候也要输出！！！！！
}

int main() {
    input();
    return 0;
}