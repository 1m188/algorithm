/**
 * @file P4387 【深基15.习9】验证栈序列.cpp
 * @date 2022-07-15
 */

/*
# 【深基15.习9】验证栈序列

## 题目描述

给出两个序列 pushed 和 poped 两个序列，其取值从 1 到 $n(n\le100000)$。已知入栈序列是 pushed，如果出栈序列有可能是 poped，则输出 `Yes`，否则输出 `No`。为了防止骗分，每个测试点有多组数据。

## 输入格式

第一行一个整数 $q$，询问次数。

接下来 $q$ 个询问，对于每个询问：

第一行一个整数 $n$ 表示序列长度；

第二行 $n$ 个整数表示入栈序列；

第三行 $n$ 个整数表示出栈序列；

## 输出格式

对于每个询问输出答案。

## 样例 #1

### 样例输入 #1

```
2
5
1 2 3 4 5
5 4 3 2 1
4
1 2 3 4
2 4 1 3
```

### 样例输出 #1

```
Yes
No
```
*/

/* 模拟即可 */

#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector<int> pushed, poped;
int q = 0, n = 0;

bool judge() {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() == poped[i]) {
            st.pop();
            continue;
        }

        while (!pushed.empty() && pushed[0] != poped[i]) {
            st.push(pushed[0]);
            pushed.erase(pushed.begin());
        }
        if (!pushed.empty()) {
            pushed.erase(pushed.begin());
        } else {
            return false;
        }
    }
    return true;
}

int main() {

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &n);

        pushed.resize(n), poped.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &pushed[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &poped[i]);

        if (judge())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}