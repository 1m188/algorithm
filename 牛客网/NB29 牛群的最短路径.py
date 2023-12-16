'''

描述
在一个牧场中，有很多牛。为了方便管理，牧场主将牛的编号排列成一棵二叉树。每个牛的编号为一个正整数。请你编写一个程序，给定一棵二叉树的根节点 root，计算出这棵树中，从根节点到叶子节点的最短路径上的节点数。

叶子节点是指没有子节点的节点。

示例1
输入：
{3, 9, 20, #, #, 15, 7}
复制
返回值：
2
复制
说明：
最短的路径3->9
备注：
树中节点数目范围在[0, 1000] 内
0 <= Node.val <= 1000

'''


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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
# @return int整型
#
class Solution:

    def minDepth(self, root: TreeNode) -> int:
        # write code here

        if not root: return 0
        a, b = self.minDepth(root.left), self.minDepth(root.right)
        if a == 0 and b == 0: return 1
        elif a == 0: return 1 + b
        elif b == 0: return 1 + a
        else: return 1 + min(a, b)
