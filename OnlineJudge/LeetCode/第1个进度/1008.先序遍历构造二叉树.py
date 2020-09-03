#
# @lc app=leetcode.cn id=1008 lang=python3
#
# [1008] 先序遍历构造二叉树
#
# https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#
# algorithms
# Medium (72.18%)
# Likes:    91
# Dislikes: 0
# Total Accepted:    8.4K
# Total Submissions: 11.7K
# Testcase Example:  '[8,5,1,7,10,12]'
#
# 返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
#
# (回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right
# 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历 node.right。）
#
#
#
# 示例：
#
# 输入：[8,5,1,7,10,12]
# 输出：[8,5,10,1,7,null,12]
#
#
#
#
#
# 提示：
#
#
# 1 <= preorder.length <= 100
# 先序 preorder 中的值是不同的。
#
#
#

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insert(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            root = TreeNode(key)
        else:
            if key < root.val:
                root.left = self.insert(root.left, key)
            elif key > root.val:
                root.right = self.insert(root.right, key)
        return root

    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = None
        for k in preorder:
            root = self.insert(root, k)
        return root


# @lc code=end
