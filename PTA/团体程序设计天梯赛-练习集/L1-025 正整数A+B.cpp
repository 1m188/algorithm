/**
 * @file L1-025 正整数A+B.cpp
 * @date 2022-05-18
 */

/*
题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。
稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，
有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，
显然此时和也是?。

输入样例1：
123 456

输出样例1：
123 + 456 = 579

输入样例2：
22. 18

输出样例2：
? + 18 = ?

输入样例3：
-100 blabla bla...33

输出样例3：
? + ? = ?

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意细节 */

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string num1, num2;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num1;
    cin.get();
    getline(cin, num2);
}

int judge(const string &s) {
    if (!(s.size() >= 1 && s.size() <= 4))
        return 0;

    int ans = 0;
    for (const char &c : s)
        if (!isdigit(c))
            return 0;
        else
            ans = ans * 10 + c - '0';

    return ans >= 1 && ans <= 1000 ? ans : 0;
}

void calc() {
    int n1 = judge(num1), n2 = judge(num2);

    if (n1)
        cout << n1;
    else
        cout << '?';

    cout << " + ";

    if (n2)
        cout << n2;
    else
        cout << '?';

    cout << " = ";

    if (n1 && n2)
        cout << n1 + n2;
    else
        cout << '?';
}

int main() {
    input();
    calc();
    return 0;
}