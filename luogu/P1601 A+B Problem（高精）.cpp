/**
 * @file P1601 A+B Problem（高精）.cpp
 * @date 2022-05-30
 */

/*
# A+B Problem（高精）

## 题目描述

高精度加法，相当于a+b problem，**不用考虑负数**.

## 输入格式

分两行输入。$a,b \leq 10^{500}$

## 输出格式

输出只有一行，代表$a+b$的值

## 样例 #1

### 样例输入 #1

```
1
1
```

### 样例输出 #1

```
2
```

## 样例 #2

### 样例输入 #2

```
1001
9099
```

### 样例输出 #2

```
10100
```
*/

/* 手工模拟加法和进位，注意细节 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    string ans;

    int x = 0;
    int ai = a.size() - 1, bi = b.size() - 1;
    while (ai >= 0 && bi >= 0) {
        int n = a[ai] - '0' + b[bi] - '0' + x;
        ans.push_back(n % 10 + '0');
        x = n / 10;
        ai--, bi--;
    }

    while (ai >= 0) {
        int n = a[ai] - '0' + x;
        ans.push_back(n % 10 + '0');
        x = n / 10;
        ai--;
    }
    while (bi >= 0) {
        int n = b[bi] - '0' + x;
        ans.push_back(n % 10 + '0');
        x = n / 10;
        bi--;
    }

    if (x) ans.push_back(x + '0');

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}