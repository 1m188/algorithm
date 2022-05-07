#
# @lc app=leetcode.cn id=508 lang=python3
#
# [508] 出现次数最多的子树元素和
#
# https://leetcode-cn.com/problems/most-frequent-subtree-sum/description/
#
# algorithms
# Medium (64.81%)
# Likes:    81
# Dislikes: 0
# Total Accepted:    7.9K
# Total Submissions: 12.2K
# Testcase Example:  '[5,2,-3]'
#
# 给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
#
# 你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
#
#
#
# 示例 1：
# 输入:
#
# ⁠ 5
# ⁠/  \
# 2   -3
#
#
# 返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
#
# 示例 2：
# 输入：
#
# ⁠ 5
# ⁠/  \
# 2   -5
#
#
# 返回 [2]，只有 2 出现两次，-5 只出现 1 次。
#
#
#
# 提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
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
    def nsum(self, root: TreeNode) -> int:
        return root.val + self.nsum(root.left) + self.nsum(root.right) \
               if root else 0

    def tsum(self, root: TreeNode) -> dict:
        res = {}
        st = []
        while root or st:
            if root:
                ns = self.nsum(root)
                res[ns] = res.get(ns, 0) + 1
                st.append(root)
                root = root.left
            else:
                root = st.pop()
                root = root.right
        return res

    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        di = list(self.tsum(root).items())
        di.sort(key=lambda x: x[1], reverse=True)
        return [i[0] for i in di if i[1] == di[0][1]]


# @lc code=end
