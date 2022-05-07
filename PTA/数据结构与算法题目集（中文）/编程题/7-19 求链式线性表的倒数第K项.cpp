/*
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。

输入格式:
输入首先给出一个正整数K，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:
输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。

输入样例:
4 1 2 3 4 5 6 7 8 9 0 -1

输出样例:
7

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 构造一个链表，然后用双指针，让第一个指针先走k步，之后第二个指针跟着走，
两个指针距离为k，直到第一个指针走到最后的时候，第二个指针的位置就是倒数
第k个 */

/* 这里构造链表的动作或许也可以用stl的list？ */

#include <iostream>
using namespace std;

struct Node {
    int val = 0;
    Node *next = nullptr;
};

void release(Node *head) {
    while (head) {
        Node *cur = head;
        head = head->next;
        delete cur;
    }
}

int main() {

    int k = 0;
    cin >> k;

    Node *head = new Node();
    Node *cur = head;

    while (true) {
        int x = 0;
        cin >> x;

        // 这里需要非常注意！！！题目中说的是“以一个负整数表示结尾”
        // 而不要看例子里说的是-1！！！
        if (x < 0)
            break;

        cur->next = new Node();
        cur->next->val = x;
        cur = cur->next;
    }

    cur = head;
    while (k--) {
        if (cur->next)
            cur = cur->next;
        else {
            cout << "NULL";
            release(head);
            return 0;
        }
    }

    Node *c = head;
    while (cur) {
        c = c->next;
        cur = cur->next;
    }

    cout << c->val;

    release(head);

    return 0;
}