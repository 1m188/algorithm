'''
描述
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。

链表结点定义如下：
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};
正常返回倒数第k个结点指针，异常返回空指针.
要求：
(1)正序构建链表;
(2)构建后要忘记链表长度。
数据范围：链表长度满足 1 \le n \le 1000 \1≤n≤1000  ， k \le n \k≤n  ，链表中数据满足 0 \le val \le 10000 \0≤val≤10000 

本题有多组样例输入。


输入描述：
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述：
输出一个整数

示例1
输入：
8
1 2 3 4 5 6 7 8
4
复制
输出：
5

'''


class ListNode:

    def __init__(self, key: int = 0, pNext: 'ListNode' = None) -> None:
        self.m_nKey: int = key
        self.m_pNext: ListNode = pNext


def build_linklist() -> ListNode:
    n = int(input())
    vals = list(map(int, input().split()))
    head = ListNode()
    cur = head
    for i in vals:
        cur.m_pNext = ListNode(i)
        cur = cur.m_pNext
    return head


while True:
    try:
        head = build_linklist()
        k = int(input())
    except EOFError:
        break

    cur = head
    for _ in range(k):
        cur = cur.m_pNext

    curr = head
    while cur:
        curr = curr.m_pNext
        cur = cur.m_pNext

    print(curr.m_nKey)
