#
# @lc app=leetcode.cn id=450 lang=python3
#
# [450] 删除二叉搜索树中的节点
#
# https://leetcode-cn.com/problems/delete-node-in-a-bst/description/
#
# algorithms
# Medium (42.92%)
# Likes:    274
# Dislikes: 0
# Total Accepted:    20.6K
# Total Submissions: 47.3K
# Testcase Example:  '[5,3,6,2,4,null,7]\n3'
#
# 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
# 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
#
# 一般来说，删除节点可分为两个步骤：
#
#
# 首先找到需要删除的节点；
# 如果找到了，删除它。
#
#
# 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
#
# 示例:
#
#
# root = [5,3,6,2,4,null,7]
# key = 3
#
# ⁠   5
# ⁠  / \
# ⁠ 3   6
# ⁠/ \   \
# 2   4   7
#
# 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
#
# 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
#
# ⁠   5
# ⁠  / \
# ⁠ 4   6
# ⁠/     \
# 2       7
#
# 另一个正确答案是 [5,2,6,null,4,null,7]。
#
# ⁠   5
# ⁠  / \
# ⁠ 2   6
# ⁠  \   \
# ⁠   4   7
#
#
#


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def leftmax(self, root: TreeNode) -> int:
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def rightmin(self, root: TreeNode) -> int:
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None

        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if not (root.left or root.right):
                root = None
            elif root.right:
                root.val = self.rightmin(root)
                root.right = self.deleteNode(root.right, root.val)
            else:
                root.val = self.leftmax(root)
                root.left = self.deleteNode(root.left, root.val)

        return root


# @lc code=end
