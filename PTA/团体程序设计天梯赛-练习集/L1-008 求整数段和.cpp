/**
 * @file L1-008 求整数段和.cpp
 * @date 2022-05-17
 */

/*
给定两个整数A和B，输出从A到B的所有整数以及这些数的和。

输入格式：
输入在一行中给出2个整数A和B，其中−100≤A≤B≤100，其间以空格分隔。

输出格式：
首先顺序输出从A到B的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。
最后在一行中按Sum = X的格式输出全部数字的和X。

输入样例：
-3 8

输出样例：
   -3   -2   -1    0    1
    2    3    4    5    6
    7    8
Sum = 30

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 格式控制 */

#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 0, b = 0;
    cin >> a >> b;
    int sum = 0;

    int cnt = 5;
    for (int i = a; i <= b; i++) {
        sum += i;
        cout << right << setw(5) << setfill(' ') << i;
        if (--cnt == 0) {
            cout << '\n';
            cnt = 5;
        }
    }

    if (cnt != 5)
        cout << '\n';

    cout << "Sum = " << sum;

    return 0;
}