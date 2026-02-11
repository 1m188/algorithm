"""
基于 Python 的线性表实现
"""

from abc import ABC, abstractmethod
from typing import Any


class Linear(ABC):
    """
    线性表的抽象类
    """

    @abstractmethod
    def push(self, data: Any) -> None:
        """
        从线性表尾部添加元素

        :param self: 线性表
        :param data: 要添加的元素
        :type data: Any
        """

    @abstractmethod
    def pop(self) -> Any:
        """
        从线性表尾部删除元素, 并返回该元素, 若线性表为空则抛出异常

        :param self: 线性表
        :return: 删除的元素
        :rtype: Any
        """

    @abstractmethod
    def insert(self, index: int, data: Any) -> None:
        """
        在指定位置插入元素, 若位置超出范围则抛出异常

        :param self: 线性表
        :param index: 要插入的位置
        :type index: int
        :param data: 要插入的元素
        :type data: Any
        """

    @abstractmethod
    def remove(self, index: int) -> Any:
        """
        删除指定位置的元素, 并返回该元素, 若位置超出范围则抛出异常

        :param self: 线性表
        :param index: 要删除的位置
        :type index: int
        :return: 删除的元素
        :rtype: Any
        """

    @abstractmethod
    def indexOf(self, data: Any) -> int:
        """
        查找元素在线性表中的位置, 若未找到则返回-1

        :param self: 线性表
        :param data: 要查找的元素
        :type data: Any
        :return: 元素的位置, 若未找到则返回-1
        :rtype: int
        """

    @abstractmethod
    def __getitem__(self, index: int) -> Any:
        """
        获取线性表中指定位置的元素, 若索引越界则抛出异常

        :param self: 线性表
        :param index: 索引
        :type index: int
        :return: 元素
        :rtype: Any
        """

    @abstractmethod
    def __setitem__(self, index: int, data: Any) -> None:
        """
        设置线性表中指定位置的元素, 若索引越界则抛出异常

        :param self: 线性表
        :param index: 索引
        :type index: int
        :param data: 要设置的元素
        :type data: Any
        """

    @property
    @abstractmethod
    def length(self) -> int:
        """
        获取线性表的长度

        :param self: 线性表
        :return: 线性表的长度
        :rtype: int
        """


class Node:
    """
    链表节点
    """

    def __init__(self, val: Any) -> None:
        self.val: Any = val
        self.next: Node | None = None


class LinearList(Linear):
    """
    基于链表的线性表实现
    """

    def __init__(self) -> None:
        self._head: Node | None = None
        self._tail: Node | None = None
        self._length: int = 0

    def push(self, data):
        node = Node(data)
        if self._head is None:
            self._head = node
            self._tail = node
        else:
            self._tail.next = node
            self._tail = node
        self._length += 1

    def pop(self):
        if self._head is None:
            raise Exception("pop from empty list")
        data = self._tail.val
        if self._head == self._tail:
            self._head = None
            self._tail = None
        else:
            node = self._head
            while node.next != self._tail:
                node = node.next
            node.next = None
            self._tail = node
        self._length -= 1
        return data

    def insert(self, index, data):
        if index < 0 or index > self._length:
            raise Exception("insert out of range")
        node = Node(data)
        if self._length == 0:
            self._head = node
            self._tail = node
        elif index == 0:
            node.next = self._head
            self._head = node
        else:
            cur = self._head
            for _ in range(index - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node
        self._length += 1

    def remove(self, index):
        if index < 0 or index >= self._length:
            raise Exception("remove out of range")
        if self._length == 1:
            data = self._head.val
            self._head = None
            self._tail = None
        elif index == 0:
            data = self._head.val
            self._head = self._head.next
        else:
            cur = self._head
            for _ in range(index - 1):
                cur = cur.next
            data = cur.next.val
            cur.next = cur.next.next
        self._length -= 1
        return data

    def indexOf(self, data):
        cur = self._head
        for i in range(self._length):
            if cur.val == data:
                return i
            cur = cur.next
        return -1

    def __getitem__(self, index):
        if index < 0 or index >= self._length:
            raise Exception("index out of range")
        cur = self._head
        for _ in range(index):
            cur = cur.next
        return cur.val

    def __setitem__(self, index, data):
        if index < 0 or index >= self._length:
            raise Exception("index out of range")
        cur = self._head
        for _ in range(index):
            cur = cur.next
        cur.val = data

    @property
    def length(self):
        return self._length


class LinearArray(Linear):
    """
    基于数组的线性表实现
    """

    def __init__(self) -> None:
        self.arr = []

    def push(self, data):
        self.arr.append(data)

    def pop(self):
        if not self.arr:
            raise Exception("empty list")
        return self.arr.pop()

    def insert(self, index, data):
        if index < 0 or index > len(self.arr):
            raise Exception("index out of range")
        if index == len(self.arr):
            self.arr.append(data)
        else:
            self.arr.insert(index, data)

    def remove(self, index):
        if index < 0 or index >= len(self.arr):
            raise Exception("index out of range")
        return self.arr.pop(index)

    def indexOf(self, data):
        try:
            return self.arr.index(data)
        except ValueError:
            return -1

    def __getitem__(self, index):
        if index < 0 or index >= len(self.arr):
            raise Exception("index out of range")
        return self.arr[index]

    def __setitem__(self, index, data):
        if index < 0 or index >= len(self.arr):
            raise Exception("index out of range")
        self.arr[index] = data

    @property
    def length(self):
        return len(self.arr)


def test(linear: Linear):
    assert linear.length == 0

    for i in range(10):
        linear.push(i)
        assert linear.length == i + 1

    assert linear.pop() == 9
    assert linear.length == 9
    assert linear.indexOf(5) == 5
    assert linear.indexOf(10) == -1

    for i in range(9):
        assert linear[i] == i

    linear[0] = 10
    assert linear[0] == 10
    assert linear.indexOf(10) == 0

    linear.insert(0, 11)
    assert linear[0] == 11
    assert linear.indexOf(11) == 0
    assert linear.length == 10

    assert linear.remove(0) == 11
    assert linear[0] == 10


if __name__ == "__main__":
    test(LinearList())
    test(LinearArray())
    print("All tests passed!")
