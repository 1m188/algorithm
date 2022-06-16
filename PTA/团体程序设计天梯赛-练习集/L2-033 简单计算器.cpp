/**
 * @file L2-033 简单计算器.cpp
 * @date 2022-06-16
 */

/*
cal.jpg
本题要求你为初学数据结构的小伙伴设计一款简单的利用堆栈执行的计算器。如上图所示，计算器由两个堆栈组成，一个堆栈 S 
1
​
  存放数字，另一个堆栈 S 
2
​
  存放运算符。计算器的最下方有一个等号键，每次按下这个键，计算器就执行以下操作：

从 S 
1
​
  中弹出两个数字，顺序为 n 
1
​
  和 n 
2
​
 ；
从 S 
2
​
  中弹出一个运算符 op；
执行计算 n 
2
​
  op n 
1
​
 ；
将得到的结果压回 S 
1
​
 。
直到两个堆栈都为空时，计算结束，最后的结果将显示在屏幕上。

输入格式：
输入首先在第一行给出正整数 N（1<N≤10 
3
 ），为 S 
1
​
  中数字的个数。

第二行给出 N 个绝对值不超过 100 的整数；第三行给出 N−1 个运算符 —— 这里仅考虑 +、-、*、/ 这四种运算。一行中的数字和符号都以空格分隔。

输出格式：
将输入的数字和运算符按给定顺序分别压入堆栈 S 
1
​
  和 S 
2
​
 ，将执行计算的最后结果输出。注意所有的计算都只取结果的整数部分。题目保证计算的中间和最后结果的绝对值都不超过 10 
9
 。

如果执行除法时出现分母为零的非法操作，则在一行中输出：ERROR: X/0，其中 X 是当时的分子。然后结束程序。

输入样例 1：
5
40 5 8 3 2
/ * - +
输出样例 1：
2
输入样例 2：
5
2 5 8 4 4
* / - +
输出样例 2：
ERROR: 5/0
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 按部就班的操作就是了 */

#include <cstdio>
#include <stack>
using namespace std;

int n = 0;
stack<int> s1;
stack<char> s2;

void calc() {
    while (!s1.empty() && !s2.empty()) {
        int n1 = s1.top();
        s1.pop();
        int n2 = s1.top();
        s1.pop();
        char op = s2.top();
        s2.pop();

        int ans = 0;

        switch (op) {
        case '+':
            ans = n2 + n1;
            break;
        case '-':
            ans = n2 - n1;
            break;
        case '*':
            ans = n2 * n1;
            break;
        case '/':
            if (n1 == 0) {
                printf("ERROR: %d/0", n2);
                return;
            }
            ans = n2 / n1;
            break;
        }

        s1.push(ans);
    }

    printf("%d", s1.top());
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        s1.push(a);
    }
    for (int i = 0; i < n - 1; i++) {
        char c = '\0';
        scanf(" %c", &c);
        s2.push(c);
    }

    calc();

    return 0;
}