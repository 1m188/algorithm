#
# @lc app=leetcode.cn id=894 lang=python3
#
# [894] 所有可能的真二叉树
#
# https://leetcode.cn/problems/all-possible-full-binary-trees/description/
#
# algorithms
# Medium (77.72%)
# Likes:    314
# Dislikes: 0
# Total Accepted:    20.5K
# Total Submissions: 26.4K
# Testcase Example:  '7'
#
# 给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树 ，并以列表形式返回。答案中每棵树的每个节点都必须符合 Node.val == 0 。
#
# 答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序 返回最终的真二叉树列表。
#
# 真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
#
#
#
# 示例 1：
#
#
# 输入：n = 7
#
# 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
#
#
# 示例 2：
#
#
# 输入：n = 3
# 输出：[[0,0,0]]
#
#
#
#
# 提示：
#
#
# 1 <= n <= 20
#
#
#

from typing import List, Optional


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

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:

        if n == 1: return [TreeNode()]
        if (n - 1) % 2 != 0: return []

        def dfs(n: int) -> list[TreeNode]:
            if n <= 0: return []
            if n == 1: return [TreeNode()]
            if (n - 1) % 2 != 0: return []

            li = []
            for i in range(n):
                left = dfs(i)
                right = dfs(n - i - 1)
                li.extend([TreeNode(0, ln, rn) for ln in left for rn in right])
            return li

        return dfs(n)


# @lc code=end
