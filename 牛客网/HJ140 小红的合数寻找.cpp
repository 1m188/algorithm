/**
 * @file HJ140 小红的合数寻找.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-08-18
 *
 * @copyright Copyright (c) 2025
 *
 */

/*
描述
小红拿到了一个正整数
x
x，她希望你在
[
x
,
2
×
x
]
[x,2×x] 区间内找到一个合数，你能帮帮她吗？

一个数为合数，当且仅当这个数是大于
1
1 的整数，并且不是质数。
输入描述：
在一行上输入一个正整数
x
(
1
≦
x
≦
100
)
x(1≦x≦100)。
输出描述：
如果范围内不存在符合条件的合数，则输出
−
1
−1。否则，输出一个正整数代表答案。
如果存在多个解决方案，您可以输出任意一个，系统会自动判定是否正确。注意，自测运行功能可能因此返回错误结果，请自行检查答案正确性。
示例1
输入：
1
复制
输出：
-1
复制
说明：
在这个样例中，我们需要在
[
1
,
2
]
[1,2] 区间内找到一个合数。根据定义，
1
1 不是合数，
2
2 是质数，所以范围内不存在合数。
示例2
输入：
5
复制
输出：
8
复制
说明：
在这个样例中，我们需要在
[
5
,
10
]
[5,10] 区间内找到一个合数。根据定义，
6
,
8
,
10
6,8,10 均是合数，所以输出任意一个均为正确答案。
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return true;
    if (n == 2) return true;
    if ((n & 0x1) == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int x;
    cin >> x;
    for (int i = x; i <= 2 * x; i++) {
        if (!isPrime(i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;

    return 0;
}