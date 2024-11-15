/**
 * @file HJ106 字符逆序.cpp
 * @date 2024-11-15
 */

/*
描述
将一个字符串str的内容颠倒过来，并输出。

数据范围：
1
≤
l
e
n
(
s
t
r
)
≤
10000

1≤len(str)≤10000
输入描述：
输入一个字符串，可以有空格

输出描述：
输出逆序的字符串

示例1
输入：
I am a student
复制
输出：
tneduts a ma I
复制
示例2
输入：
nowcoder
复制
输出：
redocwon
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << str;

    return 0;
}
