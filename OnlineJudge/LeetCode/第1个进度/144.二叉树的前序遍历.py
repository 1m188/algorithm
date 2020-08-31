#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] 二叉树的前序遍历
#
# https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
#
# algorithms
# Medium (66.49%)
# Likes:    354
# Dislikes: 0
# Total Accepted:    159K
# Total Submissions: 238.7K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的 前序 遍历。
#
# 示例:
#
# 输入: [1,null,2,3]
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3
#
# 输出: [1,2,3]
#
#
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
#
#

from typing import List


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
    def preorder(self, root: TreeNode, res: List[int]):
        '''
        递归版
        '''

        if root:
            res.append(root.val)
            self.preorder(root.left, res)
            self.preorder(root.right, res)

    def preorder_c(self, root: TreeNode, res: List[int]):
        '''
        非递归版
        '''

        st = []
        while root or len(st):
            if root:
                res.append(root.val)
                st.append(root)
                root = root.left
            else:
                root = st.pop().right

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        # self.preorder(root, res)
        self.preorder_c(root, res)
        return res


# @lc code=end
