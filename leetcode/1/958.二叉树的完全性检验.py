#
# @lc app=leetcode.cn id=958 lang=python3
#
# [958] 二叉树的完全性检验
#
# https://leetcode.cn/problems/check-completeness-of-a-binary-tree/description/
#
# algorithms
# Medium (54.54%)
# Likes:    240
# Dislikes: 0
# Total Accepted:    44.8K
# Total Submissions: 82.2K
# Testcase Example:  '[1,2,3,4,5,6]'
#
# 给定一个二叉树的 root ，确定它是否是一个 完全二叉树 。
#
# 在一个 完全二叉树 中，除了最后一个关卡外，所有关卡都是完全被填满的，并且最后一个关卡中的所有节点都是尽可能靠左的。它可以包含 1 到 2^h
# 节点之间的最后一级 h 。
#
#
#
# 示例 1：
#
#
#
#
# 输入：root = [1,2,3,4,5,6]
# 输出：true
# 解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
#
#
# 示例 2：
#
#
#
#
# 输入：root = [1,2,3,4,5,null,7]
# 输出：false
# 解释：值为 7 的结点没有尽可能靠向左侧。
#
#
#
#
# 提示：
#
#
# 树的结点数在范围  [1, 100] 内。
# 1 <= Node.val <= 1000
#
#
#

from typing import Optional


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

    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:

        if not root: return True

        nodes = []
        que = [root]
        while que:
            p = que.pop(0)
            nodes.append(p)
            if not p: continue
            que.append(p.left)
            que.append(p.right)

        # print(nodes)

        for i, v in enumerate(nodes):
            if not v: break
        for j in range(i + 1, len(nodes)):
            if nodes[j]: return False
        return True


# @lc code=end
