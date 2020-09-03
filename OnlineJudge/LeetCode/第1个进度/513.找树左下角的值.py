#
# @lc app=leetcode.cn id=513 lang=python3
#
# [513] 找树左下角的值
#
# https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
#
# algorithms
# Medium (71.02%)
# Likes:    108
# Dislikes: 0
# Total Accepted:    19.1K
# Total Submissions: 26.9K
# Testcase Example:  '[2,1,3]'
#
# 给定一个二叉树，在树的最后一行找到最左边的值。
#
# 示例 1:
#
#
# 输入:
#
# ⁠   2
# ⁠  / \
# ⁠ 1   3
#
# 输出:
# 1
#
#
#
#
# 示例 2:
#
#
# 输入:
#
# ⁠       1
# ⁠      / \
# ⁠     2   3
# ⁠    /   / \
# ⁠   4   5   6
# ⁠      /
# ⁠     7
#
# 输出:
# 7
#
#
#
#
# 注意: 您可以假设树（即给定的根节点）不为 NULL。
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
    def findBottomLeftValue(self, root: TreeNode) -> int:
        res = root.val
        st = [root]
        while st:
            nst = []
            while st:
                p = st.pop(0)
                if p.left:
                    nst.append(p.left)
                if p.right:
                    nst.append(p.right)
            st = nst
            if st:
                res = st[0].val
        return res


# @lc code=end
