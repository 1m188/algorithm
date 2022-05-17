/**
 * @file L1-004 计算摄氏温度.cpp
 * @date 2022-05-17
 */

/*
给定一个华氏温度F，本题要求编写程序，计算对应的摄氏温度C。
计算公式：C=5×(F−32)/9。题目保证输入与输出均在整型范围内。

输入格式:
输入在一行中给出一个华氏温度。

输出格式:
在一行中按照格式“Celsius = C”输出对应的摄氏温度C的整数值。

输入样例:
150
输出样例:
Celsius = 65
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

    int F = 0;
    cin >> F;

    int C = 5 * double(F - 32) / 9; // 注意计算过程中可能有小数，因为最后乘以5是有可能从小数取整的

    cout << "Celsius = " << C;

    return 0;
}