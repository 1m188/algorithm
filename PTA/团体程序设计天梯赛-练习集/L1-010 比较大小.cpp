/**
 * @file L1-010 比较大小.cpp
 * @date 2022-05-18
 */

/*
本题要求将输入的任意3个整数从小到大输出。

输入格式:
输入在一行中给出3个整数，其间以空格分隔。

输出格式:
在一行中将3个整数从小到大输出，其间以“->”相连。

输入样例:
4 2 8

输出样例:
2->4->8

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec(3);
    for (int i = 0; i < 3; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    cout << vec[0];
    for (int i = 1; i < 3; i++)
        cout << "->" << vec[i];
}

int main() {
    input();
    return 0;
}