/**
 * @file L1-003 个位数统计.cpp
 * @date 2022-05-17
 */

/*
给定一个 k 位整数 N=d 
k−1
​
 10 
k−1
 +⋯+d 
1
​
 10 
1
 +d 
0
​
  (0≤d 
i
​
 ≤9, i=0,⋯,k−1, d 
k−1
​
 >0)，请编写程序统计每种不同的个位数字出现的次数。
 例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。
要求按 D 的升序输出。

输入样例：
100311

输出样例：
0:2
1:3
3:1

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 简单题 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> vec(10);

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (const char &c : s)
        vec[c - '0']++;

    for (int i = 0; i < 10; i++)
        if (vec[i])
            cout << i << ':' << vec[i] << '\n';
}

int main() {
    input();
    return 0;
}