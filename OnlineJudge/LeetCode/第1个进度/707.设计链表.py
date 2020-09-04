#
# @lc app=leetcode.cn id=707 lang=python3
#
# [707] 设计链表
#
# https://leetcode-cn.com/problems/design-linked-list/description/
#
# algorithms
# Medium (28.11%)
# Likes:    165
# Dislikes: 0
# Total Accepted:    27.3K
# Total Submissions: 95.9K
# Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex",
# "get","deleteAtIndex","get"]\r\n' +'[[],[1],[3],[1,2],[1],[1],[1]]\r'
#
# 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
# 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
#
# 在链表类中实现这些功能：
#
#
# get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
# addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
# addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
# addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
# 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
# deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
#
#
#
#
# 示例：
#
# MyLinkedList linkedList = new MyLinkedList();
# linkedList.addAtHead(1);
# linkedList.addAtTail(3);
# linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
# linkedList.get(1);            //返回2
# linkedList.deleteAtIndex(1);  //现在链表是1-> 3
# linkedList.get(1);            //返回3
#
#
#
#
# 提示：
#
#
# 所有val值都在 [1, 1000] 之内。
# 操作次数将在  [1, 1000] 之内。
# 请不要使用内置的 LinkedList 库。
#
#
#


# @lc code=start
class MyLinkedList:
    class Node:
        def __init__(self, val=None, next=None, prev=None):
            self.val = val
            self.next = next
            self.prev = prev

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.tail = None
        self.length = 0

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index \
            is invalid, return -1.
        """
        if index >= self.length:
            return -1
        cur = self.head
        for _ in range(1, index + 1):
            cur = cur.next
        return cur.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. \
            After the insertion, the new node will be the first node of the \
            linked list.
        """
        node = self.Node(val)
        node.next = self.head
        if node.next:
            node.next.prev = node
        self.head = node
        if not self.length:
            self.tail = self.head
        self.length += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        if not self.length:
            self.tail = self.Node(val)
            self.head = self.tail
        else:
            self.tail.next = self.Node(val)
            self.tail.next.prev = self.tail
            self.tail = self.tail.next
        self.length += 1

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. \
            If index equals to the length of linked list, the node will be \
            appended to the end of linked list. If index is greater than the \
            length, the node will not be inserted.
        """
        if index > self.length:
            return

        if index <= 0:
            self.addAtHead(val)
        elif index == self.length:
            self.addAtTail(val)
        else:
            cur = self.head
            for _ in range(1, index + 1):
                cur = cur.next
            node = self.Node(val)
            node.next = cur
            node.prev = cur.prev
            cur.prev.next = node
            cur.prev = node
            self.length += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index >= self.length:
            return

        cur = self.head
        for _ in range(1, index + 1):
            cur = cur.next

        if index == 0:
            self.head = self.head.next
        elif index == self.length - 1:
            self.tail = self.tail.prev

        if cur.prev:
            cur.prev.next = cur.next
        if cur.next:
            cur.next.prev = cur.prev

        self.length -= 1
        if not self.length:
            self.head = self.tail = None


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
# @lc code=end
