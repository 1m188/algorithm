/*
算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。
日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间。
请设计程序将中缀表达式转换为后缀表达式。

输入格式:
输入在一行中给出不含空格的中缀表达式，可包含+、-、*、\以及左右括号()，表达式不超过20个字符。

输出格式:
在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。

输入样例:
2+3*(7-4)+8/4

输出样例:
2 3 7 4 - * + 8 4 / +

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 中缀转后缀遵循几个要求：

1. 准备一个栈（中转）和后缀表达式（容器）
2. 遍历中缀表达式，遇到所有数字都加入后缀表达式
3. 遇到运算符号，则将栈里的东西都弹出来加入后缀表达式，直到栈为空或者遇到左括号或者
遇到比本运算符号 严格 优先的运算符号为止，并且将本运算符号压入栈中
4. 遇到左括号，压入栈中
5. 遇到右括号，将栈中的东西弹出来加入后缀表达式，直到遇到左括号，左括号
不要加入后缀表达式，但要弹出来
6. 遍历一遍后，如果栈非空，则全部弹出来加入后缀表达式
7. 此时后缀表达式就是所要的后缀表达式了 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> infix;
vector<string> postfix;

// 这里需要非常注意
// 因为测试数据里会有要求小数（带小数点）和带正负号的整数等各种情况
void input() {
    string x;
    getline(cin, x);

    string t;
    for (int i = 0; i < x.size(); i++) {
        char c = x[i];

        // 非运算符则都是数字的一部分，加入数字字符串
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')') {
            t.push_back(c);
        } else if (c == '+' || c == '-') { // 碰到了+和-，考虑是不是数字前的正负号
            if (i == 0 || (i > 0 && x[i - 1] == '(')) {

                // 只有-被加入，+默认省略
                if (c == '-')
                    t.push_back(c);
            } else {
                if (!t.empty()) {
                    infix.push_back(t);
                    t.clear();
                }
                infix.push_back(string(1, c));
            }
        } else { // 其他情况说明都是运算符或者括号，将当前缓存的数字字符串加入后单独加入
            if (!t.empty()) {
                infix.push_back(t);
                t.clear();
            }
            infix.push_back(string(1, c));
        }
    }

    if (!t.empty())
        infix.push_back(t);
}

void get_postfix() {
    stack<string> st;

    for (const auto &e : infix) {

        if (e == "+" || e == "-") {
            while (!(st.empty() || st.top() == "(")) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(e);
        } else if (e == "*" || e == "/") {
            while (!(st.empty() || st.top() == "(" || st.top() == "+" || st.top() == "-")) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(e);
        } else if (e == "(") {
            st.push(e);
        } else if (e == ")") {
            while (st.top() != "(") {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            postfix.push_back(e);
        }
    }

    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
}

void print() {
    cout << postfix[0];
    for (int i = 1; i < postfix.size(); i++)
        cout << ' ' << postfix[i];
}

int main() {
    input();
    get_postfix();
    print();
    return 0;
}