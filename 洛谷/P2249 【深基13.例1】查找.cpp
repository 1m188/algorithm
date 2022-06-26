/**
 * @file P2249 【深基13.例1】查找.cpp
 * @date 2022-06-26
 */

/*
# 【深基13.例1】查找

## 题目描述

输入 $n(n\le10^6)$ 个不超过 $10^9$ 的单调不减的（就是后面的数字不小于前面的数字）非负整数 $a_1,a_2,\dots,a_{n}$，然后进行 $m(m\le10^5)$ 次询问。对于每次询问，给出一个整数 $q(q\le10^9)$，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 -1 。

## 输入格式

第一行 2 个整数 n 和 m，表示数字个数和询问次数。

第二行 n 个整数，表示这些待查询的数字。

第三行 m 个整数，表示询问这些数字的编号，从 1 开始编号。

## 输出格式

m 个整数表示答案。

## 样例 #1

### 样例输入 #1

```
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
```

### 样例输出 #1

```
1 2 -1
```

## 提示

$10^6$ 规模的数据读入，请用 scanf。用 cin 会超时。
*/

/* 保存每个数据和其最开始出现的索引，之后二分查找，找到的不一定是第一次出现的，但是
按照其最开始出现的索引可以返回其最开始出现的位置，注意最后结果是从1开始的 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int n = 0, m = 0;

int midfind(int target) {
    int left = 0, right = n - 1, mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (vec[mid].first == target)
            break;
        else if (vec[mid].first < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (vec[mid].first != target) return -1;
    return vec[mid].second + 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        if (i == 0) {
            vec[i].second = 0;
        } else if (vec[i].first == vec[i - 1].first) {
            vec[i].second = vec[i - 1].second;
        } else {
            vec[i].second = i;
        }
    }

    while (m--) {
        int q = 0;
        cin >> q;
        cout << midfind(q) << ' ';
    }

    return 0;
}