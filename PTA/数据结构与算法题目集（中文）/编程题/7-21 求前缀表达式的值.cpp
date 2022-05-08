/*
算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。
前缀表达式指二元运算符位于两个运算数之前，
例如2+3*(7-4)+8/4的前缀表达式是：+ + 2 * 3 - 7 4 / 8 4。
请设计程序计算前缀表达式的结果值。

输入格式:
输入在一行内给出不超过30个字符的前缀表达式，
只包含+、-、*、/以及运算数，不同对象（运算数、运算符号）之间以空格分隔。

输出格式:
输出前缀表达式的运算结果，保留小数点后1位，或错误信息ERROR。

输入样例:
+ + 2 * 3 - 7 4 / 8 4

输出样例:
13.0

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 把所有输入都看作字符串，然后用stringstream输入根据空格做分割，之后进行计算

前缀表达式的计算方法为：定义一个栈，从后往前遍历前缀表达式，遇到数字都入栈，
遇到操作符则弹出栈顶两个数，按照弹出的先后顺序放在操作符的左右两边做计算，
计算的结果压入栈中，直到遍历完前缀表达式，此时栈中应该只有一个数，即为结果。 */

/* 这道题还是AC了，但有个问题是，这里并没有考虑数字前面有正负号表示正负数的情况，
但考虑到如果数字不在第一个位置的话，加正负号为了和运算符区分开是要加括号的，
但是这个题目里面没有括号，所以不在第一个位置的数字应该不会加正负号，但关键是
第一个位置的数字是可以加正负号而不需要加括号的，这种情况并没有考虑，然而最后
提交的时候也还是过了，这里要注意一下 */

#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> vec;

void input() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> s) {
        vec.push_back(s);
    }
}

void calc() {
    stack<double> st;

    // 这里定义四则运算的方法，后面就可以少些一点代码
    unordered_map<string, function<double(double, double)>> mp;
    mp["+"] = [](double x, double y) { return x + y; };
    mp["-"] = [](double x, double y) { return x - y; };
    mp["*"] = [](double x, double y) { return x * y; };
    mp["/"] = [](double x, double y) { return x / y; };

    for (auto crit = vec.crbegin(); crit != vec.crend(); crit++) {
        const string &s = *crit;

        if (mp.find(s) != mp.end()) {
            if (st.size() < 2) {
                cout << "ERROR";
                return;
            }
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            if (s == "/" && b == 0) { // 对于除法要判定合法性
                cout << "ERROR";
                return;
            }
            double c = mp[s](a, b);
            st.push(c);
        } else {
            stringstream ss(s);
            double x = 0;
            ss >> x;
            st.push(x);
        }
    }

    if (st.size() != 1) {
        cout << "ERROR";
        return;
    }

    double ans = st.top();
    cout << setiosflags(ios::fixed) << setprecision(1) << ans;
}

int main() {
    input();
    calc();
    return 0;
}