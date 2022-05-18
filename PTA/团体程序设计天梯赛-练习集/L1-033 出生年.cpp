/**
 * @file L1-033 出生年.cpp
 * @date 2022-05-18
 */

/*

以上是新浪微博中一奇葩贴：“我出生于1988年，直到25岁才遇到4个数字都不相同的年份。”
也就是说，直到2013年才达到“4个数字都不相同”的要求。
本题请你根据要求，自动填充“我出生于y年，直到x岁才遇到n个数字都不相同的年份”这句话。

输入格式：
输入在一行中给出出生年份y和目标年份中不同数字的个数n，其中y在[1, 3000]之间，n可以是2、或3、或4。
注意不足4位的年份要在前面补零，例如公元1年被认为是0001年，有2个不同的数字0和1。

输出格式：
根据输入，输出x和能达到要求的年份。数字间以1个空格分隔，行首尾不得有多余空格。
年份要按4位输出。
注意：所谓“n个数字都不相同”是指不同的数字正好是n个。
如“2013”被视为满足“4位数字都不同”的条件，但不被视为满足2位或3位数字不同的条件。

输入样例1：
1988 4

输出样例1：
25 2013

输入样例2：
1 2

输出样例2：
0 0001

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 对每一年进行判定，注意，年份一律按照4位来算 */

#include <iomanip>
#include <iostream>
using namespace std;

int y = 0, // 出生年份
    n = 0; // 几个不同的数字

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> y >> n;
}

/**
 * @brief 给出目标年份有几个数字不同
 * @param year 目标年份
 * @return int 几个数字不同
 */
int judge(int year) {

    bool flags[10]{false}; // 用数组做集合，索引是数字，内容是该数字在年份中是否出现

    for (int i = 0; i < 4; i++) { // 对4个位挨个判断
        flags[year % 10] = true;
        year /= 10;
    }

    int ans = 0;
    for (const bool &f : flags) // 对每个出现的数字进行计数
        if (f)
            ans++;

    return ans;
}

/**
 * @brief 计算并输出
 */
void calc() {
    int age = 0;
    while (judge(y) != n)
        y++, age++;

    cout << age << ' '
         << setw(4) << setfill('0')
         << y;
}

int main() {
    input();
    calc();
    return 0;
}