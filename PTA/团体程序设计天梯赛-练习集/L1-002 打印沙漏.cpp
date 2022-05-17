/**
 * @file L1-002 打印沙漏.cpp
 * @date 2022-05-17
 */

/*
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；
符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *

输出样例:
*****
 ***
  *
 ***
*****
2

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意别输出太多的空格，对于格式化沙漏而言，只需要输出每行最开始的空格
和每行的符号即可，后面的空格会由从左到右的输出格式自动补齐 */

#include <iostream>
using namespace std;

int N;
char sign;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> sign;
}

void print() {
    if (N <= 0)
        return;
    else if (N < 7) {
        cout << sign << '\n'
             << N - 1;
        return;
    }

    int num = 1, snum = 3;
    while (num + snum * 2 <= N) {
        num += snum * 2;
        snum += 2;
    }

    snum -= 2;

    int sp = 0;

    for (int i = snum; i >= 1; i -= 2) {
        for (int j = 0; j < sp; j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << sign;
        sp++;
        cout << '\n';
    }

    sp -= 2;

    for (int i = 3; i <= snum; i += 2) {
        for (int j = 0; j < sp; j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << sign;
        sp--;
        cout << '\n';
    }

    cout << N - num;
}

int main() {
    input();
    print();
    return 0;
}