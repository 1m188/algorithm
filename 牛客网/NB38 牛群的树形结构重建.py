'''

描述
农场里有一群牛，牛群的成员分布在山坡上，形成了一个二叉树结构。每头牛都有一个编号，表示它在牛群中的身份。现在农场主想要重建牛群的二叉树结构。给定两个整数数组 inOrder 和 postOrder，其中 inOrder 是牛群二叉树的中序遍历，postOrder 是同一棵树的后序遍历，请构造二叉树并返回其根节点。
示例1
输入：
[9, 3, 15, 20, 7],[9, 15, 7, 20, 3]
复制
返回值：
{3,9,20,#,#,15,7}
复制
示例2
输入：
[1],[1]
复制
返回值：
{1}
复制
备注：
1 <= inOrder.length <= 3000
postOrder.length == inOrder.length
-3000 <= inOrder[i], postOrder[i] <= 3000
inOrder 和 postOrder 均无重复元素
postOrder 保证为二叉树的后序遍历序列
inOrder 保证为二叉树的中序遍历序列

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
# @param inOrder int整型一维数组
# @param postOrder int整型一维数组
# @return TreeNode类
#
class Solution:

    def buildTree(self, inOrder: List[int], postOrder: List[int]) -> TreeNode:
        # write code here

        if not inOrder or not postOrder: return None

        a = postOrder[-1]
        root = TreeNode(a)

        idx = inOrder.index(a)

        inOrder1 = inOrder[:idx]
        inOrder2 = inOrder[idx + 1:]
        postOrder1 = postOrder[:len(inOrder1)]
        postOrder2 = postOrder[len(inOrder1):-1]

        root.left = self.buildTree(inOrder1, postOrder1)
        root.right = self.buildTree(inOrder2, postOrder2)

        return root
