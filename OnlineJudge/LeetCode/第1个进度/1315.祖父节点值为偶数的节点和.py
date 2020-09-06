#
# @lc app=leetcode.cn id=1315 lang=python3
#
# [1315] 祖父节点值为偶数的节点和
#
# https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
#
# algorithms
# Medium (80.69%)
# Likes:    34
# Dislikes: 0
# Total Accepted:    7.1K
# Total Submissions: 8.8K
# Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
#
# 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
#
#
# 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
#
#
# 如果不存在祖父节点值为偶数的节点，那么返回 0 。
#
#
#
# 示例：
#
#
#
# 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
# 输出：18
# 解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
#
#
#
#
# 提示：
#
#
# 树中节点的数目在 1 到 10^4 之间。
# 每个节点的值在 1 到 100 之间。
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
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        def preorder(root):
            if root:
                if not root.val % 2:
                    for p in (root.left, root.right):
                        if p:
                            nonlocal res
                            res += p.left.val if p.left else 0
                            res += p.right.val if p.right else 0
                preorder(root.left)
                preorder(root.right)

        res = 0
        preorder(root)
        return res


# @lc code=end
