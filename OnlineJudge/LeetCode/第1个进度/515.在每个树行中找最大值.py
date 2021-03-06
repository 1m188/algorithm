#
# @lc app=leetcode.cn id=515 lang=python3
#
# [515] 在每个树行中找最大值
#
# https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
#
# algorithms
# Medium (61.24%)
# Likes:    85
# Dislikes: 0
# Total Accepted:    16.1K
# Total Submissions: 26.3K
# Testcase Example:  '[1,3,2,5,3,null,9]'
#
# 您需要在二叉树的每一行中找到最大的值。
#
# 示例：
#
#
# 输入:
#
# ⁠         1
# ⁠        / \
# ⁠       3   2
# ⁠      / \   \
# ⁠     5   3   9
#
# 输出: [1, 3, 9]
#
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
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        res = []
        que = [root]
        while que:
            res.append(max(que, key=lambda x: x.val).val)
            que = [i for n in que for i in (n.left, n.right) if i]
        return res


# @lc code=end
