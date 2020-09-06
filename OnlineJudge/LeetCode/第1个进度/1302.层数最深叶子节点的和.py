#
# @lc app=leetcode.cn id=1302 lang=python3
#
# [1302] 层数最深叶子节点的和
#
# https://leetcode-cn.com/problems/deepest-leaves-sum/description/
#
# algorithms
# Medium (80.66%)
# Likes:    30
# Dislikes: 0
# Total Accepted:    9.5K
# Total Submissions: 11.8K
# Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
#
# 给你一棵二叉树，请你返回层数最深的叶子节点的和。
#
#
#
# 示例：
#
#
#
# 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
# 输出：15
#
#
#
#
# 提示：
#
#
# 树中节点数目在 1 到 10^4 之间。
# 每个节点的值在 1 到 100 之间。
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
    def deepestLeavesSum(self, root: TreeNode) -> int:
        res = 0
        que = [root]

        while que:
            res = sum((n.val for n in que))
            que = [i for n in que for i in (n.left, n.right) if i]

        return res


# @lc code=end
