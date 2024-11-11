/**
 * @file HJ12 字符串反转.cpp
 * @date 2024-11-11
 */

/*
描述
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述：
输入一行，为一个只包含小写字母的字符串。

输出描述：
输出该字符串反转后的字符串。

示例1
输入：
abcd
复制
输出：
dcba
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    cout << str;

    return 0;
}
// 64 位输出请用 printf("%lld")