/**
 * @file L1-013 计算阶乘和.cpp
 * @date 2022-05-18
 */

/*
对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。

输入格式：
输入在一行中给出一个不超过10的正整数N。

输出格式：
在一行中输出S的值。

输入样例：
3

输出样例：
9

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    int sum = 0, t = 1;
    for (int i = 1; i <= n; i++) { // 这里使用t这个变量来存储中间过程，后续的阶乘会在这个的基础上进行一步计算得到
        t *= i;
        sum += t;
    }

    cout << sum;

    return 0;
}