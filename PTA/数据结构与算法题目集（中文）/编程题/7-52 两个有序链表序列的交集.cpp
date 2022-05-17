/**
 * @file 7-52 两个有序链表序列的交集.cpp
 * @date 2022-05-17
 */

/*
已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。

输入格式:
输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。
数字用空格间隔。

输出格式:
在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

输入样例:
1 2 5 -1
2 4 5 8 10 -1

输出样例:
2 5

代码长度限制
16 KB

时间限制
1000 ms

内存限制
64 MB
*/

/* 顺序序列求交集 */

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

Node *s1 = new Node(), *s2 = new Node(), *s3 = new Node();

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *cur = s1;
    int x = 0;

    while (cin >> x && x != -1) {
        cur->next = new Node();
        cur->next->val = x;
        cur = cur->next;
    }

    cur = s2;

    while (cin >> x && x != -1) {
        cur->next = new Node();
        cur->next->val = x;
        cur = cur->next;
    }
}

void intersection() {
    Node *c = s3;

    Node *c1 = s1->next, *c2 = s2->next;

    while (c1 && c2) {
        if (c1->val == c2->val) {
            c->next = c1;
            c = c->next;
            c1 = c1->next, c2 = c2->next;
            c->next = nullptr;
        } else if (c1->val < c2->val)
            c1 = c1->next;
        else
            c2 = c2->next;
    }

    if (!s3->next)
        cout << "NULL";
    else {
        cout << s3->next->val;
        c = s3->next->next;
        while (c) {
            cout << ' ' << c->val;
            c = c->next;
        }
    }
}

int main() {
    input();
    intersection();
    return 0;
}