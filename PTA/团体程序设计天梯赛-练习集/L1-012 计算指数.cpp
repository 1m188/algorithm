/**
 * @file L1-012 计算指数.cpp
 * @date 2022-05-18
 */

/*
真的没骗你，这道才是简单题 —— 对任意给定的不超过 10 的正整数 n，要求你输出 2^n。不难吧？

输入格式：
输入在一行中给出一个不超过 10 的正整数 n。

输出格式：
在一行中按照格式 2^n = 计算结果 输出 2^n 的值。

输入样例：
5

输出样例：
2^5 = 32

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    cout << "2^" << n << " = " << pow(2, n);

    return 0;
}