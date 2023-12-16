'''

描述
农场里有一群牛，牛群的成员分布在山坡上，形成了一个二叉树结构。每头牛都有一个编号，表示它在牛群中的身份。现在农场主想要重建牛群的二叉树结构。给定两个整数数组 preOrder 和 inOrder，其中 preOrder 是牛群二叉树的先序遍历，inOrder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
示例1
输入：
[1, 2, 3, 4, 5],[1, 2, 3, 4, 5]
复制
返回值：
{1,#,2,#,3,#,4,#,5}
复制
示例2
输入：
[1],[1]
复制
返回值：
{1}
复制
备注：
1 <= preOrder.length <= 3000
inOrder.length == preOrder.length
0 <= preOrder[i], inOrder[i] <= 3000
preOrder 和 inOrder 均无重复元素
inOrder 均出现在 preOrder
preOrder 保证为二叉树的前序遍历序列
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
# @param preOrder int整型一维数组
# @param inOrder int整型一维数组
# @return TreeNode类
#
class Solution:

    def buildTreeII(self, preOrder: List[int], inOrder: List[int]) -> TreeNode:
        # write code here

        if not preOrder or not inOrder: return None

        a = preOrder[0]
        root = TreeNode(a)

        idx = inOrder.index(a)

        inOrder1 = inOrder[:idx]
        inOrder2 = inOrder[idx + 1:]
        preOrder1 = preOrder[1:1 + len(inOrder1)]
        preOrder2 = preOrder[1 + len(inOrder1):]

        root.left = self.buildTreeII(preOrder1, inOrder1)
        root.right = self.buildTreeII(preOrder2, inOrder2)

        return root
