/**
 * @file 7-53 两个有序序列的中位数.cpp
 * @date 2022-05-17
 */

/*
已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列A 
0
​
 ,A 
1
​
 ,⋯,A 
N−1
​
A0,A1......An-1

 的中位数指A 
(N−1)/2
​
A_(N-1)/2

 的值,即第⌊(N+1)/2⌋个数
 
 
 （A 
0

A0

 为第1个数）。

输入格式:
输入分三行。第一行给出序列的公共长度N（0<N≤100000），随后每行输入一个序列的信息，
即N个非降序排列的整数。数字用空格间隔。

输出格式:
在一行中输出两个输入序列的并集序列的中位数。

输入样例1:
5
1 3 5 7 9
2 3 4 5 6

输出样例1:
4

输入样例2:
6
-100 -10 1 1 1 1
-50 0 2 3 4 5

输出样例2:
1

代码长度限制
16 KB

时间限制
200 ms

内存限制
64 MB
*/

/* 单调队列

对于中位数，题目里已经给出来是第 int(n1+n2+1)/2  个数了，关键的地方在于，
当两个指针指向的数相同的时候，该放弃哪个数？
答案是，都不放弃，因为不知道接下来两个数谁大，所以使用单调队列，
保存所有相同的数，但遇到更大的数的时候则放弃所有更小的数 */

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> s1, s2;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    s1.resize(n), s2.resize(n);

    for (int i = 0; i < n; i++)
        cin >> s1[i];
    for (int i = 0; i < n; i++)
        cin >> s2[i];
}

void midnum() {
    int cnt = (s1.size() + s2.size() + 1) / 2;

    deque<int> dque;

    int i1 = 0, i2 = 0;

    while (cnt-- > 0) {
        if (s1[i1] < s2[i2]) {
            while (!dque.empty() && dque.back() < s1[i1])
                dque.pop_back();
            dque.push_back(s1[i1]);
            i1++;
        } else {
            while (!dque.empty() && dque.back() < s2[i2])
                dque.pop_back();
            dque.push_back(s2[i2]);
            i2++;
        }
    }

    cout << dque.front();
}

int main() {
    input();
    midnum();
    return 0;
}