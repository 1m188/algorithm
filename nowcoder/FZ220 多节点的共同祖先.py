'''

描述
牛牛是一只聪明的牛，它生活在一个由节点构成的二叉树中。每个节点都有一个唯一的整数值。现在给定一个二叉树的根节点和一个整数数组nodes，其中nodes中的整数代表二叉树中的节点值。请你编写一个函数，返回nodes中所有节点的最近公共祖先（LCA）。公共祖先的定义是：对于nodes中的每个节点，它们都是LCA的后代（包括自身）。

给定二叉树的根节点和一个整数数组nodes，找到nodes中所有节点的最近公共祖先，并返回其值。


示例1
输入：
{4, 5, 1, 6, 2, 0, 7, #, #, 8, 9},[8, 9]
复制
返回值：
2
复制
示例2
输入：
{5, 7, 4},[5, 7, 4]
复制
返回值：
5
复制
备注：
二叉树中节点的数量范围为 [1, 10^4]。
节点值的范围为 [-10^9, 10^9]。
所有节点的值都是唯一的。
nodes数组中的节点值都存在于二叉树中。
nodes数组中的节点值都是不重复的。

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
# @param nodes int整型一维数组
# @return int整型
#
class Solution:

    def findLCA(self, root: TreeNode, nodes: List[int]) -> int:
        # write code here

        self.ret = None

        nodes = set(nodes)

        def dfs(node: TreeNode) -> list[int]:
            if not node: return []
            if self.ret != None: return []
            a = dfs(node.left)
            if self.ret != None: return []
            b = dfs(node.right)
            if self.ret != None: return []
            c = []
            if node.val in nodes: c = [node.val]
            x = a + b + c
            if len(x) == len(nodes) and self.ret == None:
                self.ret = node
            return x

        dfs(root)

        return self.ret.val
