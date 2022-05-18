/**
 * @file L1-022 奇偶分家.cpp
 * @date 2022-05-18
 */

/*
给定N个正整数，请统计奇数和偶数各有多少个？

输入格式：
输入第一行给出一个正整N（≤1000）；第2行给出N个非负整数，以空格分隔。

输出格式：
在一行中先后输出奇数的个数、偶数的个数。中间以1个空格分隔。

输入样例：
9
88 74 101 26 15 0 34 22 77

输出样例：
3 6

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iostream>
using namespace std;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;
        if (a % 2)
            x++;
    }

    cout << x << ' ' << n - x;
}

int main() {
    input();
    return 0;
}