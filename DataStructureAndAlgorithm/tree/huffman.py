"""
基于 Python 的霍夫曼编码树实现
"""


class Node[T]:
    """
    霍夫曼树节点
    """

    def __init__(
        self,
        val: T,
        left: "Node[T] | None" = None,
        right: "Node[T] | None" = None,
    ) -> None:
        self.val: T = val
        self.left: Node[T] | None = left
        self.right: Node[T] | None = right


def build_huffman[T](arr: list[T]) -> Node[T] | None:
    """
    构建霍夫曼树

    :param arr: 待构建的元素序列
    :type arr: list[T]
    :return: 霍夫曼树根节点
    :rtype: Node[T] | None
    """

    if not arr:
        return None
    if len(arr) == 1:
        return Node[T](arr[0])

    li: list[Node[T]] = sorted([Node[T](x) for x in arr], key=lambda x: x.val)
    while len(li) > 1:
        left: Node[T] = li.pop(0)
        right: Node[T] = li.pop(0)
        node: Node[T] = Node[T](left.val + right.val, left, right)
        li.append(node)
        li.sort(key=lambda x: x.val)
    return li[0]


def test():
    """
    测试函数
    """

    def layer[T](root: Node[T] | None) -> list[list[T]]:
        """
        层序遍历

        :param root: 根节点
        :type root: Node[T] | None
        :return: 层序序列
        :rtype: list[list[T]]
        """

        if not root:
            return []

        li: list[list[T]] = []
        queue: list[Node[T]] = [root]
        while queue:
            li.append([x.val for x in queue])
            n = len(queue)
            for _ in range(n):
                node: Node[T] = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return li

    arr = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6]
    root = build_huffman(arr)
    li = layer(root)
    print("\n".join(" ".join(map(str, x)) for x in li))
    assert li[0][0] == 55
    assert li[1][0] == 22 and li[1][1] == 33
    assert li[2][0] == 10 and li[2][1] == 12 and li[2][2] == 15 and li[2][3] == 18
    assert (
        li[3][0] == 6
        and li[3][1] == 6
        and li[3][2] == 7
        and li[3][3] == 8
        and li[3][4] == 9
        and li[3][5] == 9
    )
    assert li[4][0] == 3 and li[4][1] == 3 and li[4][2] == 4 and li[4][3] == 5
    assert li[5][0] == 1 and li[5][1] == 2


if __name__ == "__main__":
    test()
    print("All tests passed!")
