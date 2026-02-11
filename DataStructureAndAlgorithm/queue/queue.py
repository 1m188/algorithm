"""
基于 Python 的队列实现
"""

from typing import Protocol


class IQueue[T](Protocol):
    """
    队列接口
    """

    @property
    def length(self) -> int:
        """
        队列长度

        :param self: 队列
        :return: 队列长度
        :rtype: int
        """

    def enqueue(self, item: T) -> None:
        """
        入队

        :param self: 队列
        :param item: 待入队的元素
        :type item: T
        """

    def dequeue(self) -> T:
        """
        出队并且返回出队的元素, 如果队列为空则抛出异常

        :param self: 队列
        :return: 出队元素
        :rtype: T
        """

    def front(self) -> T:
        """
        返回队首元素, 如果队列为空则抛出异常

        :param self: 队列
        :return: 队首元素
        :rtype: T
        """


class Node[T]:
    """
    链表节点
    """

    def __init__(self, val: T):
        self.val: T = val
        self.next: Node[T] | None = None


class QueueList[T](IQueue[T]):
    """
    基于链表的队列实现
    """

    def __init__(self) -> None:
        self._head: Node[T] | None = None
        self._tail: Node[T] | None = None
        self._length: int = 0

    @property
    def length(self) -> int:
        return self._length

    def enqueue(self, item: T) -> None:
        node = Node(item)
        if self._length == 0:
            self._head = node
            self._tail = node
        else:
            self._tail.next = node
            self._tail = node
        self._length += 1

    def dequeue(self) -> T:
        if self._length == 0:
            raise Exception("queue is empty")
        val = self._head.val
        self._head = self._head.next
        self._length -= 1
        if self._length == 0:
            self._tail = None
        return val

    def front(self) -> T:
        if self._length == 0:
            raise Exception("queue is empty")
        return self._head.val


class QueueArray[T](IQueue[T]):
    """
    基于数组的队列实现
    """

    def __init__(self) -> None:
        self.arr: list[T] = []

    @property
    def length(self) -> int:
        return len(self.arr)

    def enqueue(self, item: T) -> None:
        self.arr.append(item)

    def dequeue(self) -> T:
        if len(self.arr) == 0:
            raise Exception("queue is empty")
        return self.arr.pop(0)

    def front(self) -> T:
        if len(self.arr) == 0:
            raise Exception("queue is empty")
        return self.arr[0]


def test(queue: IQueue[int]) -> None:
    assert queue.length == 0

    for i in range(10):
        queue.enqueue(i)
        assert queue.length == i + 1
        assert queue.front() == 0

    for i in range(10):
        assert queue.front() == i
        assert queue.dequeue() == i
        assert queue.length == 10 - i - 1


if __name__ == "__main__":
    test(QueueList[int]())
    test(QueueArray[int]())
    print("All tests passed!")
