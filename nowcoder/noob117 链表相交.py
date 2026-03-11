"""
描述
给定两个无环单链表
A
,
B
A,B，它们可能在某一节点开始共享后缀，若存在第一个共享节点，则称为交点。
请实现函数 getIntersectionNode，用于计算两个无环单链表交点节点，如果交点不存在则直接返回空。
输入描述：
函数参数由两个参数构成：
∙

∙链表
h
e
a
d
A
headA：表示链表
A
A 的链表头，长度为
m
(
1
≦
m
≦
3
×
1
0
4
)
m(1≦m≦3×10
4
 )；
∙

∙链表
h
e
a
d
B
headB：表示链表
B
B 的链表头，长度为
n
(
1
≦
n
≦
3
×
1
0
4
)
n(1≦n≦3×10
4
 )；
输出描述：
函数的返回值：
返回两个无环单链表交点节点，如果交点不存在则直接返回空。
示例1
输入：
5 6 3
3 6
1 1 4
5 1 4
复制
输出：
5
复制
说明：





相交节点的值为 5 。
从各自的表头开始算起，链表 A 为 [3,6,5,1,4]，链表 B 为 [1,1,4,5,1,4]。

"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    # 在这里补充代码

    pA, pB = headA, headB
    while pA != pB:
        pA = pA.next if pA else headB
        pB = pB.next if pB else headA
    return pA


# 你不需要关心主函数内容！
def main():
    # 读入数据
    lenA, lenB, commonLen = map(int, input().split())

    # 读入链表A的独立部分
    valuesA = list(map(int, input().split()))
    # 读入链表B的独立部分
    valuesB = list(map(int, input().split()))
    # 读入公共部分
    valuesCommon = list(map(int, input().split()))
    nodesCommon = []
    if commonLen == 0:
        nodesCommon = []
    else:
        nodesCommon = [ListNode(x) for x in valuesCommon]

    # 构建链表
    nodesA = [ListNode(x) for x in valuesA]
    nodesB = [ListNode(x) for x in valuesB]

    # 连接链表A的独立部分
    for i in range(len(nodesA) - 1):
        nodesA[i].next = nodesA[i + 1]

    # 连接链表B的独立部分
    for i in range(len(nodesB) - 1):
        nodesB[i].next = nodesB[i + 1]

    # 连接公共部分
    for i in range(len(nodesCommon) - 1):
        nodesCommon[i].next = nodesCommon[i + 1]

    # 设置头节点并连接公共部分
    headA = None
    headB = None

    if len(nodesA) > 0:
        headA = nodesA[0]
        if len(nodesCommon) > 0:
            nodesA[-1].next = nodesCommon[0]
    elif len(nodesCommon) > 0:
        headA = nodesCommon[0]

    if len(nodesB) > 0:
        headB = nodesB[0]
        if len(nodesCommon) > 0:
            nodesB[-1].next = nodesCommon[0]
    elif len(nodesCommon) > 0:
        headB = nodesCommon[0]

    # 调用函数获取结果
    result = getIntersectionNode(headA, headB)

    # 输出结果
    if result is None:
        print("null")
    else:
        print(result.val)


if __name__ == "__main__":
    main()
