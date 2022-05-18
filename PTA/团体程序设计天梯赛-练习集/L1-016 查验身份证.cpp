/**
 * @file L1-016 查验身份证.cpp
 * @date 2022-05-18
 */

/*
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；
然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：
输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。
这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。
如果所有号码都正常，则输出All passed。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X

输出样例1：
12010X198901011234
110108196711301866
37070419881216001X

输入样例2：
2
320124198808240056
110108196711301862

输出样例2：
All passed

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 按部就班的算就是了，注意检查前17位是否都为数字 */

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<char> z2m = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
const vector<int> weight = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

vector<string> idnum;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    idnum.resize(n);
    for (int i = 0; i < n; i++)
        cin >> idnum[i];
}

void calc() {
    vector<string> ans;

    for (const string &s : idnum) {

        bool f = true;

        int sum = 0;
        for (int i = 0; i < 17; i++) {
            if (isdigit(s[i]))
                sum += (s[i] - '0') * weight[i];
            else {
                ans.push_back(s);
                f = false;
                break;
            }
        }

        if (!f)
            continue;

        int z = sum % 11;
        if (s[17] != z2m[z])
            ans.push_back(s);
    }

    if (ans.empty())
        cout << "All passed";
    else
        for (const string &s : ans)
            cout << s << '\n';
}

int main() {
    input();
    calc();
    return 0;
}