/**
 * @file HJ55 挑7.cpp
 * @date 2024-11-15
 */

/*
描述
输出 1到n之间 的与 7 有关数字的个数。
一个数与7有关是指这个数是 7 的倍数，或者是包含 7 的数字（如 17 ，27 ，37 ... 70 ，71 ，72 ，73...）

数据范围：
1
≤
n
≤
30000

1≤n≤30000
输入描述：
一个正整数 n 。( n 不大于 30000 )

输出描述：
一个整数，表示1到n之间的与7有关的数字个数。

示例1
输入：
20
复制
输出：
3
复制
说明：
输入20，1到20之间有关的数字包括7,14,17共3个。
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0)
            res++;
        else {
            bool f = false;
            int x = i;
            while (x) {
                if (x % 10 == 7) {
                    f = true;
                    break;
                }
                x /= 10;
            }
            if (f) res++;
        }
    }

    cout << res;

    return 0;
}
