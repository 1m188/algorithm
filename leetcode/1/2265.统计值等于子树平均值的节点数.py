#
# @lc app=leetcode.cn id=2265 lang=python3
#
# [2265] 统计值等于子树平均值的节点数
#
# https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/description/
#
# algorithms
# Medium (82.64%)
# Likes:    37
# Dislikes: 0
# Total Accepted:    11.8K
# Total Submissions: 14.3K
# Testcase Example:  '[4,8,5,0,1,null,6]'
#
# 给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。
#
# 注意：
#
#
# n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
# root 的 子树 由 root 和它的所有后代组成。
#
#
#
#
# 示例 1：
#
# 输入：root = [4,8,5,0,1,null,6]
# 输出：5
# 解释：
# 对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
# 对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
# 对值为 0 的节点：子树的平均值 0 / 1 = 0 。
# 对值为 1 的节点：子树的平均值 1 / 1 = 1 。
# 对值为 6 的节点：子树的平均值 6 / 1 = 6 。
#
#
# 示例 2：
#
# 输入：root = [1]
# 输出：1
# 解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
#
#
#
#
# 提示：
#
#
# 树中节点数目在范围 [1, 1000] 内
# 0 <= Node.val <= 1000
#
#
#


class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def averageOfSubtree(self, root: TreeNode) -> int:

        self.res = 0
        self.dfs(root)
        return self.res

    def dfs(self, root: TreeNode) -> (int, int):
        if not root: return 0, 0
        left_n, left_v = self.dfs(root.left)
        right_n, right_v = self.dfs(root.right)
        a = root.val + left_v + right_v
        b = 1 + left_n + right_n
        if a // b == root.val: self.res += 1
        return b, a


# @lc code=end
