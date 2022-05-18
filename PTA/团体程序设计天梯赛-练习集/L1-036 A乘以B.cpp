/**
 * @file L1-036 A乘以B.cpp
 * @date 2022-05-18
 */

/*
看我没骗你吧 —— 这是一道你可以在 10 秒内完成的题：
给定两个绝对值不超过 100 的整数 A 和 B，输出 A 乘以 B 的值。

输入格式：
输入在第一行给出两个整数 A 和 B（−100≤A,B≤100），数字间以空格分隔。

输出格式：
在一行中输出 A 乘以 B 的值。

输入样例：
-8 13

输出样例：
-104

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

    int a = 0, b = 0;
    cin >> a >> b;
    cout << a * b;

    return 0;
}