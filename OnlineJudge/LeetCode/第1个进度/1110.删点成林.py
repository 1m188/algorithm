#
# @lc app=leetcode.cn id=1110 lang=python3
#
# [1110] 删点成林
#
# https://leetcode-cn.com/problems/delete-nodes-and-return-forest/description/
#
# algorithms
# Medium (60.12%)
# Likes:    64
# Dislikes: 0
# Total Accepted:    4.6K
# Total Submissions: 7.6K
# Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
#
# 给出二叉树的根节点 root，树上每个节点都有一个不同的值。
#
# 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
#
# 返回森林中的每棵树。你可以按任意顺序组织答案。
#
#
#
# 示例：
#
#
#
# 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
# 输出：[[1,2,null,4],[6],[7]]
#
#
#
#
# 提示：
#
#
# 树中的节点数最大为 1000。
# 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
# to_delete.length <= 1000
# to_delete 包含一些从 1 到 1000、各不相同的值。
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
    def dn(self, root: TreeNode, fo: List[TreeNode],
           to_delete: List[int]) -> TreeNode:
        if not root:
            return None
        root.left = self.dn(root.left, fo, to_delete)
        root.right = self.dn(root.right, fo, to_delete)
        if root.val in to_delete:
            if root.left:
                fo.append(root.left)
            if root.right:
                fo.append(root.right)
            root = None
        return root

    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        res = [root]
        idx = 0
        while idx < len(res):
            res[idx] = self.dn(res[idx], res, to_delete)
            if not res[idx]:
                res.pop(idx)
            else:
                idx += 1
        return res


# @lc code=end
