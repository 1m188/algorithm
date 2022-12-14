/*
令 P
i
​
  表示第 i 个素数。现任给两个正整数 M≤N≤10
4
 ，请输出 P
M
​
  到 P
N
​
  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P
M
​
  到 P
N
​
  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool judge(long long x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (long long i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

void out(vector<long long> vec) {
    for (int i = 0; i < vec.size(); i++) {
        auto v = vec[i];
        if ((i + 1) % 10 != 0) {
            if (i != vec.size() - 1)
                cout << v << ' ';
            else
                cout << v << '\n';
        } else
            cout << v << '\n';
    }
}

int main() {

    int m = 0, n = 0;
    cin >> m >> n;

    long long x = 2;
    int cnt = 1;
    vector<long long> vec;

    while (true) {
        if (judge(x)) {
            if (cnt >= m) vec.push_back(x);
            cnt++;
            if (cnt > n) break;
        }
        x++;
    }

    out(vec);

    return 0;
}