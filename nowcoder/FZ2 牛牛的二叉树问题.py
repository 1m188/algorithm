'''

描述
动物牛牛是一只聪明的牛，它现在面临一个二叉树的问题。给定一个二叉树的根节点 root、一个目标值 target 和一个整数 m，请你返回二叉树中与目标值最接近的 m 个节点值。
请你编写一个函数 findClosestElements，接收一个二叉树的根节点 root、一个整数 target 和一个整数 m 作为参数，返回一个整数数组，表示与目标值最接近的 m 个节点值。
返回数组以非递减的形式给出。
示例1
输入：
{5,3,9,1,4,#,7},6.10000,3
复制
返回值：
[4,5,7]
复制
示例2
输入：
{1,#,2,#,3},2.10000,2
复制
返回值：
[2,3]
复制
备注：
二叉树的节点总数为 n。
1 ≤ m ≤ n ≤ 10^4。
-10^9 ≤ Node.val ≤ 10^9。

'''

from typing import List


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left: TreeNode = None
        self.right: TreeNode = None


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类
# @param target double浮点型
# @param m int整型
# @return int整型一维数组
#
class Solution:

    def findClosestElements(self, root: TreeNode, target: float, m: int) -> List[int]:
        # write code here

        li = []

        def pre(node: TreeNode):
            if not node: return
            li.append(node.val)
            pre(node.left)
            pre(node.right)

        pre(root)

        def adjust(li: list, idx: int):
            n = len(li)
            if n == 0 or idx < 0 or idx >= n: return
            while True:
                index = idx
                left = idx * 2 + 1
                right = idx * 2 + 2
                if left < n and abs(li[left] - target) < abs(li[index] - target): index = left
                if right < n and abs(li[right] - target) < abs(li[index] - target): index = right
                if index == idx: break
                li[idx], li[index] = li[index], li[idx]
                idx = index

        def build_heap(li: list):
            for i in range((len(li) - 1 - 1) // 2, -1, -1):
                adjust(li, i)

        build_heap(li)
        res = []
        for _ in range(m):
            li[0], li[-1] = li[-1], li[0]
            res.append(li.pop())
            adjust(li, 0)
        return sorted(res)
