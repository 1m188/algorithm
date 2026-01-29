/**
 * @file HJ13 句子逆序.cpp
 * @date 2024-11-11
 */

/*
描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”

所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

数据范围：输入的字符串长度满足
1
≤
n
≤
1000

1≤n≤1000

注意本题有多组输入
输入描述：
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

输出描述：
得到逆序的句子

示例1
输入：
I am a boy
复制
输出：
boy a am I
复制
示例2
输入：
nowcoder
复制
输出：
nowcoder
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string &s, char elem) {
    vector<string> res;
    string tmp;
    for (const char &c : s) {
        if (c != elem) {
            tmp.push_back(c);
        } else {
            res.push_back(tmp);
            tmp.clear();
        }
    }
    res.push_back(tmp);
    return res;
}

int main() {
    string s;
    getline(cin, s);

    auto vec = split(s, ' ');

    s.clear();
    for (auto it = vec.crbegin(); it != vec.crend(); it++) {
        s.append(*it);
        s.push_back(' ');
    }
    s.pop_back();
    cout << s;

    return 0;
}
// 64 位输出请用 printf("%lld")