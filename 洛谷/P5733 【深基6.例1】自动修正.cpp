/**
 * @file P5733 【深基6.例1】自动修正.cpp
 * @date 2022-05-30
 */

/*
# 【深基6.例1】自动修正

## 题目描述

大家都知道一些办公软件有自动将字母转换为大写的功能。输入一个长度不超过 100 且不包括空格的字符串。要求将该字符串中的所有小写字母变成大写字母并输出。

## 输入格式

## 输出格式

## 样例 #1

### 样例输入 #1

```
Luogu4!
```

### 样例输出 #1

```
LUOGU4!
```
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cin >> s;

    for (char &c : s) {
        if (islower(c)) {
            c = toupper(c);
        }
    }

    cout << s;

    return 0;
}