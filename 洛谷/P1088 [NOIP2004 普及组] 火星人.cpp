/**
 * @file P1088 [NOIP2004 普及组] 火星人.cpp
 * @date 2022-06-10
 */

/*
# [NOIP2004 普及组] 火星人

## 题目描述

人类终于登上了火星的土地并且见到了神秘的火星人。人类和火星人都无法理解对方的语言，但是我们的科学家发明了一种用数字交流的方法。这种交流方法是这样的，首先，火星人把一个非常大的数字告诉人类科学家，科学家破解这个数字的含义后，再把一个很小的数字加到这个大数上面，把结果告诉火星人，作为人类的回答。

火星人用一种非常简单的方式来表示数字――掰手指。火星人只有一只手，但这只手上有成千上万的手指，这些手指排成一列，分别编号为 $1,2,3,\cdots$。火星人的任意两根手指都能随意交换位置，他们就是通过这方法计数的。

一个火星人用一个人类的手演示了如何用手指计数。如果把五根手指――拇指、食指、中指、无名指和小指分别编号为 $1,2,3,4$ 和 $5$，当它们按正常顺序排列时，形成了 $5$ 位数 $12345$，当你交换无名指和小指的位置时，会形成 $5$ 位数 $12354$，当你把五个手指的顺序完全颠倒时，会形成 $54321$，在所有能够形成的 $120$ 个 $5$ 位数中，$12345$ 最小，它表示 $1$；$12354$ 第二小，它表示 $2$；$54321$ 最大，它表示 $120$。下表展示了只有 $3$ 根手指时能够形成的 $6$ 个 $3$ 位数和它们代表的数字：


| 三进制数 | 代表的数字 |
|:-:|:-:|
| $123$ | $1$ |
| $132$ | $2$ |
| $213$ | $3$ |
| $231$ | $4$ |
| $312$ | $5$ |
| $321$ | $6$ |

现在你有幸成为了第一个和火星人交流的地球人。一个火星人会让你看他的手指，科学家会告诉你要加上去的很小的数。你的任务是，把火星人用手指表示的数与科学家告诉你的数相加，并根据相加的结果改变火星人手指的排列顺序。输入数据保证这个结果不会超出火星人手指能表示的范围。

## 输入格式

共三行。  
第一行一个正整数 $N$，表示火星人手指的数目（$1 \le N \le 10000$）。  
第二行是一个正整数 $M$，表示要加上去的小整数（$1  \le  M  \le  100$）。  
下一行是 $1$ 到 $N$ 这 $N$ 个整数的一个排列，用空格隔开，表示火星人手指的排列顺序。

## 输出格式

$N$ 个整数，表示改变后的火星人手指的排列顺序。每两个相邻的数中间用一个空格分开，不能有多余的空格。

## 样例 #1

### 样例输入 #1

```
5
3
1 2 3 4 5
```

### 样例输出 #1

```
1 2 4 5 3
```

## 提示

对于 $30\%$ 的数据，$N \le 15$。

对于 $60\%$ 的数据，$N \le 50$。

对于 $100\%$ 的数据，$N \le 10000$。

noip2004 普及组第 4 题
*/

/* 全排列，康托展开也能做 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;
int n = 0, m = 0;

void input() {
    scanf("%d %d", &n, &m);
    vec.resize(n);
    for (int &e : vec)
        scanf("%d", &e);
}

void next_p() {
    for (int i = 0; i < m; i++)
        next_permutation(vec.begin(), vec.end());
}

/* 错的，康托展开 re */

int jc(int x) {
    if (x <= 0) return 1;
    return x * jc(x - 1);
}

int cantor() {
    vector<bool> flags(n + 1);
    int ans = 0;
    int jiecheng = jc(n);
    int bit = n;

    for (const int &e : vec) {
        jiecheng /= bit--;
        flags[e] = true;
        int x = 0;
        for (int i = 1; i < e; i++)
            x += !flags[i];
        ans += x * jiecheng;
    }

    return ans;
}

void re_cantor(int x) {
    vec.clear();
    vector<bool> flags(n + 1);
    int jiecheng = jc(n - 1);

    for (int i = n - 1; i > 0; i--) {
        int t = x / jiecheng;
        x %= jiecheng;
        jiecheng /= i;

        int y = 0, idx = 1;
        while (y < t && idx <= n)
            y += !flags[idx++];

        while (flags[idx])
            idx++;
        vec.push_back(idx);
        flags[idx] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!flags[i]) {
            vec.push_back(i);
            break;
        }
    }
}

/* ******************************************** */

void print() {
    printf("%d", vec[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", vec[i]);
}

int main() {
    input();
    next_p();
    // re_cantor(cantor() + m);
    print();
    return 0;
}