#
# @lc app=leetcode.cn id=124 lang=python3
#
# [124] 二叉树中的最大路径和
#
# https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
#
# algorithms
# Hard (42.94%)
# Likes:    648
# Dislikes: 0
# Total Accepted:    68.9K
# Total Submissions: 160.4K
# Testcase Example:  '[1,2,3]'
#
# 给定一个非空二叉树，返回其最大路径和。
#
# 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
#
# 示例 1:
#
# 输入: [1,2,3]
#
# ⁠      1
# ⁠     / \
# ⁠    2   3
#
# 输出: 6
#
#
# 示例 2:
#
# 输入: [-10,9,20,null,null,15,7]
#
# -10
# / \
# 9  20
# /  \
# 15   7
#
# 输出: 42
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
    def maxPathSum(self, root: TreeNode) -> int:
        res = -float('inf')

        def maxg(root: TreeNode = root):
            if root:
                nonlocal res
                l, r = max(maxg(root.left), 0), max(maxg(root.right), 0)
                res = max(res, l + r + root.val)
                # 每个节点本身的最大路径需要考虑到它的左右两个子路径，但其本身所提供的最大增益只需要考虑到其中大的那一个即可
                return max(l, r) + root.val
            else:
                return 0

        maxg()
        return res


# @lc code=end
