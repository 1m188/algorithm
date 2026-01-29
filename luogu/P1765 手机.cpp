/**
 * @file P1765 手机.cpp
 * @date 2022-05-30
 */

/*
# 手机

## 题目描述

一般的手机的键盘是这样的：

![](https://cdn.luogu.com.cn/upload/image_hosting/2mokuz5x.png)

要按出英文字母就必须要按数字键多下。例如要按出 `x` 就得按 9 两下，第一下会出 `w`，而第二下会把 `w` 变成 `x`。0 键按一下会出一个空格。

你的任务是读取若干句只包含英文小写字母和空格的句子，求出要在手机上打出这个句子至少需要按多少下键盘。

## 输入格式

一行句子，只包含英文小写字母和空格，且不超过 200 个字符。

## 输出格式

一行一个整数，表示按键盘的总次数。

## 样例 #1

### 样例输入 #1

```
i have a dream
```

### 样例输出 #1

```
23
```

## 提示

NOI导刊2010普及（10）
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> ump = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 1}, {'e', 2}, {'f', 3}, {'g', 1}, {'h', 2}, {'i', 3}, {'j', 1}, {'k', 2}, {'l', 3}, {'m', 1}, {'n', 2}, {'o', 3}, {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4}, {'t', 1}, {'u', 2}, {'v', 3}, {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4}, {' ', 1}};

int main() {

    string s;
    getline(cin, s);

    int ans = 0;
    for (const char &c : s)
        ans += ump[c];

    cout << ans;

    return 0;
}