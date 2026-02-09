"""
基于 Python 的栈实现
"""

from abc import ABC, abstractmethod
from typing import Any, NoReturn


class Stack(ABC):
    """
    栈接口
    """

    @property
    @abstractmethod
    def size(self) -> int:
        """
        栈中元素数量

        :param self: 栈
        :return: 栈中元素数量
        :rtype: int
        """

    @abstractmethod
    def push(self, item: Any) -> NoReturn:
        """
        压入栈顶元素

        :param self: 栈
        :param item: 待压入的元素
        :type item: Any
        :rtype: NoReturn
        """

    @abstractmethod
    def pop(self) -> Any:
        """
        删除栈顶元素并且返回该元素, 如果栈为空则抛出异常

        :param self: 栈
        :return: 栈顶元素
        :rtype: Any
        """

    @abstractmethod
    def peek(self) -> Any:
        """
        获取栈顶元素, 如果栈为空则抛出异常

        :param self: 栈
        :return: 栈顶元素
        :rtype: Any
        """


class Node:
    """
    链表节点
    """

    def __init__(self, val: Any):
        self.val = val
        self.next = None


class StackList(Stack):
    """
    基于链表的栈实现
    """

    def __init__(self):
        self._top = None
        self._size = 0

    @property
    def size(self) -> int:
        return self._size

    def push(self, item: Any) -> NoReturn:
        node = Node(item)
        node.next = self._top
        self._top = node
        self._size += 1

    def pop(self) -> Any:
        if self._top is None:
            raise IndexError("pop from empty stack")
        val = self._top.val
        self._top = self._top.next
        self._size -= 1
        return val

    def peek(self) -> Any:
        if self._top is None:
            raise IndexError("peek from empty stack")
        return self._top.val


class StackArray(Stack):
    """
    基于数组的栈实现
    """

    def __init__(self):
        self._data = []

    @property
    def size(self) -> int:
        return len(self._data)

    def push(self, item: Any) -> NoReturn:
        self._data.append(item)

    def pop(self) -> Any:
        if not self._data:
            raise IndexError("pop from empty stack")
        return self._data.pop()

    def peek(self) -> Any:
        if not self._data:
            raise IndexError("peek from empty stack")
        return self._data[-1]


def test(stack: Stack) -> NoReturn:
    """
    测试函数

    :param stack: 待测试的栈
    :type stack: Stack
    :return: 无
    :rtype: NoReturn
    """

    assert stack.size == 0

    for i in range(10):
        stack.push(i)
        assert stack.size == i + 1
        assert stack.peek() == i

    for i in range(10):
        assert stack.pop() == 10 - i - 1
        assert stack.size == 10 - i - 1

    assert stack.size == 0

    try:
        stack.pop()
    except IndexError:
        pass

    try:
        stack.peek()
    except IndexError:
        pass


if __name__ == "__main__":
    test(StackList())
    test(StackArray())
    print("All tests passed!")
