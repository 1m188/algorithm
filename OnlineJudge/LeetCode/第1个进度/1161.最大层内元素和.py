#
# @lc app=leetcode.cn id=1161 lang=python3
#
# [1161] 最大层内元素和
#
# https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/description/
#
# algorithms
# Medium (68.61%)
# Likes:    27
# Dislikes: 0
# Total Accepted:    6K
# Total Submissions: 8.8K
# Testcase Example:  '[1,7,0,7,-8,null,null]'
#
# 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
#
# 请你找出层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
#
#
#
# 示例：
#
#
#
# 输入：[1,7,0,7,-8,null,null]
# 输出：2
# 解释：
# 第 1 层各元素之和为 1，
# 第 2 层各元素之和为 7 + 0 = 7，
# 第 3 层各元素之和为 7 + -8 = -1，
# 所以我们返回第 2 层的层号，它的层内元素之和最大。
#
#
#
#
# 提示：
#
#
# 树中的节点数介于 1 和 10^4 之间
# -10^5 <= node.val <= 10^5
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
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        que = [root]
        maxsum = root.val
        res = 1
        lay = 1
        while que:
            que = [i for n in que for i in (n.left, n.right) if i]
            lay += 1
            s = sum([n.val for n in que])
            if s > maxsum:
                maxsum = s
                res = lay
        return res


# @lc code=end
