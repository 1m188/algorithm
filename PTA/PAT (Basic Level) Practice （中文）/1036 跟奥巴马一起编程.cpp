/**
 * @file 1036 跟奥巴马一起编程.cpp
 * @date 2022-12-31
 */

/*
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014 年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

输入格式：
输入在一行中给出正方形边长 N（3≤N≤20）和组成正方形边的某种字符 C，间隔一个空格。

输出格式：
输出由给定字符 C 画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的 50%（四舍五入取整）。

输入样例：
10 a
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
代码长度限制
16 KB
时间限制
400 ms
内存限制
*/

#include <iostream>
using namespace std;

int main() {

    int n = 0;
    char c = '\0';
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cout << c;

    double col = 1.0 * n / 2;
    int coli = n / 2;
    if (col - coli >= 0.5) coli++;

    for (int i = 0; i < coli - 2; i++) {
        cout << '\n'
             << c;
        for (int j = 0; j < n - 2; j++)
            cout << ' ';
        cout << c;
    }

    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << c;

    return 0;
}