/**
 * @file L1-015 跟奥巴马一起画方块.cpp
 * @date 2022-05-18
 */

/*
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。
2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。
现在你也跟他一起画吧！

输入格式：
输入在一行中给出正方形边长N（3≤N≤21）和组成正方形边的某种字符C，间隔一个空格。

输出格式：
输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，
我们输出的行数实际上是列数的50%（四舍五入取整）。

输入样例：
10 a

输出样例：
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意输出格式，尤其是列数是行数/2的四舍五入，不过考虑到这里只是/2，只有.5和整数
两个情况，可以通过判断是否整除从而确定int型/2之后要不要+1 */

#include <iostream>
using namespace std;

int N = 0;  // 列数
char C = 0; // 字符

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
}

/**
 * @brief 输出
 */
void print() {
    int coln = N, rown = coln % 2 ? coln / 2 + 1 : coln / 2;

    for (int i = 0; i < rown; i++) {
        for (int j = 0; j < coln; j++)
            cout << C;
        cout << '\n';
    }
}

int main() {
    input();
    print();
    return 0;
}