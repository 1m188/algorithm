/**
 * @file L1-029 是不是太胖了.cpp
 * @date 2022-05-18
 */

/*
据说一个人的标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。
已知市斤的数值是公斤数值的两倍。现给定某人身高，请你计算其标准体重应该是多少？
（顺便也悄悄给自己算一下吧……）

输入格式：
输入第一行给出一个正整数H（100 < H ≤ 300），为某人身高。

输出格式：
在一行中输出对应的标准体重，单位为市斤，保留小数点后1位。

输入样例：
169

输出样例：
124.2

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iomanip>
#include <iostream>
using namespace std;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double h = 0;
    cin >> h;

    h = (h - 100) * 0.9 * 2;

    cout << setiosflags(ios::fixed) << setprecision(1) << h;
}

int main() {
    input();
    return 0;
}