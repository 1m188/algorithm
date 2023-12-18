'''

描述
牛牛是一头聪明的程序牛，他喜欢研究树的问题。最近，他对于N叉树的最大深度非常感兴趣。现在，请你帮助牛牛解决这个问题。
给定一棵N叉树，以二叉树的形式表示，每个节点除了包含一个值，还包含一个指向它的第一个子节点的指针和一个指向它的兄弟节点的指针（兄弟节点在N叉树中同一层的节点），即左子女右兄弟的表示方法。请你编写一个函数，计算N叉树的最大深度。最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
示例1
输入：
{1, 3, #, 5, 2, #, 6, #, 4}
复制
返回值：
3
复制
示例2
输入：
{1,2,#,6,3,#,7,8,4,#,9,#,5,#,10}
复制
返回值：
3
复制
备注：
N叉树的深度不会超过 1000。
N叉树的节点数目位于 [0, 10^4] 之间。

'''


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
# @return int整型
#
class Solution:

    def maxDepth(self, root: TreeNode) -> int:
        # write code here

        if not root: return 0
        cur = root
        li = []
        while cur:
            li.append(self.maxDepth(cur.right))
            cur = cur.right
        li.append(1 + self.maxDepth(root.left))
        return max(li)
