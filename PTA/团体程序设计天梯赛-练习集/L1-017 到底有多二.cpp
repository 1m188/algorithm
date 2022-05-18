/**
 * @file L1-017 到底有多二.cpp
 * @date 2022-05-18
 */

/*
一个整数“犯二的程度”定义为该数字中包含2的个数与其位数的比值。
如果这个数是负数，则程度增加0.5倍；如果还是个偶数，则再增加1倍。
例如数字-13142223336是个11位数，其中有3个2，并且是负数，也是偶数，
则它的犯二程度计算为：3/11×1.5×2×100%，约为81.82%。本题就请你计算一个给定整数到底有多二。

输入格式：
输入第一行给出一个不超过50位的整数N。

输出格式：
在一行中输出N犯二的程度，保留小数点后两位。

输入样例：
-13142223336

输出样例：
81.82%

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 简单题，注意负数和偶数的判定及相应的情况计算 */

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string num;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num;
}

void calc() {
    double is_fu = num[0] == '-' ? 1.5 : 1;
    double is_ou = (num.back() - '0') % 2 ? 1 : 2;

    if (num[0] == '-')
        num.erase(num.begin());

    int n = 0;
    for (const char &c : num)
        n += c == '2';

    double ans = double(n) / num.size() * is_fu * is_ou;

    cout << setiosflags(ios::fixed) << setprecision(2)
         << ans * 100 << '%';
}

int main() {
    input();
    calc();
    return 0;
}