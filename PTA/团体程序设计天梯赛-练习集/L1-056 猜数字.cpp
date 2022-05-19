/**
 * @file L1-056 猜数字.cpp
 * @date 2022-05-19
 */

/*
一群人坐在一起，每人猜一个 100 以内的数，谁的数字最接近大家平均数的一半就赢。本题就要求你找出其中的赢家。

输入格式：
输入在第一行给出一个正整数N（≤10 
4
 ）。随后 N 行，每行给出一个玩家的名字（由不超过8个英文字母组成的字符串）和其猜的正整数（≤ 100）。

输出格式：
在一行中顺序输出：大家平均数的一半（只输出整数部分）、赢家的名字，其间以空格分隔。题目保证赢家是唯一的。

输入样例：
7
Bob 35
Amy 28
James 98
Alice 11
Jack 45
Smith 33
Chris 62
输出样例：
22 Amy
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 不难，计算 */

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> name; // 参与者的名字
vector<int> gnum;    // 猜的数字

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);
    getchar();

    while (n--) {
        string s;
        for (char c; scanf("%c", &c) && c != ' ';)
            s.push_back(c);

        name.push_back(s);

        int num = 0;
        scanf("%d", &num);

        gnum.push_back(num);

        getchar();
    }
}

/**
 * @brief 计算并输出
 */
void calc() {
    double avg = 0;
    for (const int i : gnum)
        avg += i;
    avg /= gnum.size() * 2;

    int idx = 0;
    for (int i = 0; i < gnum.size(); i++) {
        if (abs(gnum[i] - avg) < abs(gnum[idx] - avg))
            idx = i;
    }

    printf("%d %s", int(avg), name[idx].c_str());
}

int main() {
    input();
    calc();
    return 0;
}