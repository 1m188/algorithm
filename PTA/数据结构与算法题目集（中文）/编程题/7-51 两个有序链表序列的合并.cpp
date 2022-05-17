/**
 * @file 7-51 两个有序链表序列的合并.cpp
 * @date 2022-05-17
 */

/*
已知两个非降序链表序列S1与S2，设计函数构造出S1与S2合并后的新的非降序链表S3。

输入格式:
输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。
数字用空格间隔。

输出格式:
在一行中输出合并后新的非降序链表，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

输入样例:
1 3 5 -1
2 4 6 8 10 -1

输出样例:
1 2 3 4 5 6 8 10

代码长度限制
16 KB

时间限制
1500 ms

内存限制
128 MB
*/

/* 链表归并，基本功，注意指针操作 */

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

    int x = 0;

    Node *cur = s1;
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

void combine() {
    Node *c = s3;

    Node *c1 = s1->next, *c2 = s2->next;

    while (c1 && c2) {
        if (c1->val < c2->val) {
            c->next = c1;
            c = c->next;
            c1 = c1->next;
        } else {
            c->next = c2;
            c = c->next;
            c2 = c2->next;
        }
    }

    if (c1)
        c->next = c1;
    if (c2)
        c->next = c2;

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
    combine();
    return 0;
}