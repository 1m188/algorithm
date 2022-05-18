/**
 * @file L1-028 判断素数.cpp
 * @date 2022-05-18
 */

/*
本题的目标很简单，就是判断一个给定的正整数是否素数。

输入格式：
输入在第一行给出一个正整数N（≤ 10），随后N行，每行给出一个小于2^31的需要判断的正整数。

输出格式：
对每个需要判断的正整数，如果它是素数，则在一行中输出Yes，否则输出No。

输入样例：
2
11
111

输出样例：
Yes
No

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 判断质数的老方法了，一直枚举到sqrt(n)，注意这里1不是素数 */

#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief 判断一个数是否是质数
 * @param n 待判断的数
 * @return true 是
 * @return false 否
 */
bool judge(int n) {
    if (n <= 1) // 注意！1不是质数
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    while (n--) {
        int a = 0;
        cin >> a;
        if (judge(a))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    input();
    return 0;
}