"""
基于 Python 的二叉查找树(BST, Binary Search Tree)实现
"""


class Node[T]:
    """
    bst节点
    """

    def __init__(
        self,
        data: T,
        left: "Node[T] | None" = None,
        right: "Node[T] | None" = None,
    ):
        self.data: T = data
        self.left: Node[T] | None = left
        self.right: Node[T] | None = right


def insert[T](root: Node[T] | None, data: T) -> Node[T] | None:
    """
    往bst中插入一个节点

    :param root: bst根节点
    :type root: Node[T] | None
    :param data: 要插入的数据
    :type data: T
    :return: bst根节点
    :rtype: Node[T]
    """

    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root


def delete[T](root: Node[T] | None, data: T) -> Node[T] | None:
    """
    删除bst中的节点

    :param root: bst根节点
    :type root: Node[T] | None
    :param data: 要删除的数据
    :type data: T
    :return: bst根节点
    :rtype: Node[T] | None
    """

    if root is None:
        return None

    if data < root.data:
        root.left = delete(root.left, data)
    elif data > root.data:
        root.right = delete(root.right, data)
    else:
        if not root.left and not root.right:
            root = None
        elif root.left and not root.right:
            root = root.left
        elif root.right and not root.left:
            root = root.right
        else:
            cur = root.left
            while cur.right:
                cur = cur.right
            root.data = cur.data
            root.left = delete(root.left, cur.data)

    return root


def search[T](root: Node[T] | None, data: T) -> Node[T] | None:
    """
    在bst中查找一个节点

    :param root: bst根节点
    :type root: Node[T] | None
    :param data: 要查找的数据
    :type data: T
    :return: 查找到的节点
    :rtype: Node[T] | None
    """

    if not root:
        return None

    if root.data == data:
        return root

    if root.data > data:
        return search(root.left, data)
    return search(root.right, data)


def build_bst[T](li: list[T]) -> Node[T] | None:
    """
    根据一个列表构建一个bst

    :param li: 列表
    :type li: list[T]
    :return: bst根节点
    :rtype: Node[T] | None
    """

    if not li:
        return None

    root = Node(li[0])
    for i in li[1:]:
        root = insert(root, i)
    return root


def traverse[T](root: Node[T] | None) -> list[T]:
    """
    遍历bst, 返回一个有序列表

    :param root: bst根节点
    :type root: Node[T] | None
    :return: 有序列表
    :rtype: list[T]
    """

    ans: list[T] = []

    def mid(root: Node[T] | None) -> None:
        if root is None:
            return
        mid(root.left)
        ans.append(root.data)
        mid(root.right)

    mid(root)
    return ans


def test():
    """
    测试函数
    """

    li = [5, 4, 8, 6, 9]
    root = build_bst(li)
    assert traverse(root) == [4, 5, 6, 8, 9]
    assert search(root, 6).data == 6
    assert search(root, 3) is None
    assert search(root, 5) == root

    root = delete(root, 8)
    assert traverse(root) == [4, 5, 6, 9]

    root = delete(root, 5)
    assert traverse(root) == [4, 6, 9]


if __name__ == "__main__":
    test()
    print("All tests passed!")
