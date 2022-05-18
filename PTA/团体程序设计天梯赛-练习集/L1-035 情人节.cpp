/**
 * @file L1-035 情人节.cpp
 * @date 2022-05-18
 */

/*

以上是朋友圈中一奇葩贴：“2月14情人节了，我决定造福大家。
第2个赞和第14个赞的，我介绍你俩认识…………咱三吃饭…你俩请…”。
现给出此贴下点赞的朋友名单，请你找出那两位要请客的倒霉蛋。

输入格式：
输入按照点赞的先后顺序给出不知道多少个点赞的人名，每个人名占一行，为不超过10个英文字母的非空单词，
以回车结束。一个英文句点.标志输入的结束，这个符号不算在点赞名单里。

输出格式：
根据点赞情况在一行中输出结论：
若存在第2个人A和第14个人B，则输出“A and B are inviting you to dinner...”；
若只有A没有B，则输出“A is the only one for you...”；
若连A都没有，则输出“Momo... No one is for you ...”。

输入样例1：
GaoXZh
Magi
Einst
Quark
LaoLao
FatMouse
ZhaShen
fantacy
latesum
SenSen
QuanQuan
whatever
whenever
Potaty
hahaha
.

输出样例1：
Magi and Potaty are inviting you to dinner...

输入样例2：
LaoLao
FatMouse
whoever
.

输出样例2：
FatMouse is the only one for you...

输入样例3：
LaoLao
.

输出样例3：
Momo... No one is for you ...

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <iostream>
#include <string>
using namespace std;

string A, B;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 14;

    string s;
    while (cin >> s && s != ".") {
        num--;
        if (num == 12)
            A = s;
        else if (num == 0) {
            B = s;
            break;
        }
    }
}

void print() {
    if (!A.empty() && !B.empty())
        cout << A << " and " << B << " are inviting you to dinner...";
    else if (!A.empty() && B.empty())
        cout << A << " is the only one for you...";
    else
        cout << "Momo... No one is for you ...";
}

int main() {
    input();
    print();
    return 0;
}