/**
 * @file L1-007 念数字.cpp
 * @date 2022-05-17
 */

/*
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu

输入格式：
输入在一行中给出一个整数，如：1234。

提示：整数包括负数、零和正数。

输出格式：
在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。
如  yi er san si。

输入样例：
-600

输出样例：
fu liu ling ling

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 做映射，直接输出 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> ump = {{'0', "ling"},
                                   {'1', "yi"},
                                   {'2', "er"},
                                   {'3', "san"},
                                   {'4', "si"},
                                   {'5', "wu"},
                                   {'6', "liu"},
                                   {'7', "qi"},
                                   {'8', "ba"},
                                   {'9', "jiu"},
                                   {'-', "fu"}};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << ump[s[0]];
    for (int i = 1; i < s.size(); i++)
        cout << ' ' << ump[s[i]];
}

int main() {
    input();
    return 0;
}