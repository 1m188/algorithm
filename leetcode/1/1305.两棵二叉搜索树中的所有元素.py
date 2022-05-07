#
# @lc app=leetcode.cn id=1305 lang=python3
#
# [1305] 两棵二叉搜索树中的所有元素
#
# https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/description/
#
# algorithms
# Medium (73.98%)
# Likes:    28
# Dislikes: 0
# Total Accepted:    8.3K
# Total Submissions: 11.3K
# Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
#
# 给你 root1 和 root2 这两棵二叉搜索树。
#
# 请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
#
#
#
# 示例 1：
#
#
#
# 输入：root1 = [2,1,4], root2 = [1,0,3]
# 输出：[0,1,1,2,3,4]
#
#
# 示例 2：
#
# 输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
# 输出：[-10,0,0,1,2,5,7,10]
#
#
# 示例 3：
#
# 输入：root1 = [], root2 = [5,1,7,0,2]
# 输出：[0,1,2,5,7]
#
#
# 示例 4：
#
# 输入：root1 = [0,-10,10], root2 = []
# 输出：[-10,0,10]
#
#
# 示例 5：
#
#
#
# 输入：root1 = [1,null,8], root2 = [8,1]
# 输出：[1,1,8,8]
#
#
#
#
# 提示：
#
#
# 每棵树最多有 5000 个节点。
# 每个节点的值在 [-10^5, 10^5] 之间。
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
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(root, li):
            if root:
                inorder(root.left, li)
                li.append(root.val)
                inorder(root.right, li)

        def merge(m, n):
            res = []
            idxm, idxn = 0, 0
            while idxm < len(m) and idxn < len(n):
                if m[idxm] <= n[idxn]:
                    res.append(m[idxm])
                    idxm += 1
                else:
                    res.append(n[idxn])
                    idxn += 1
            if idxn < len(n):
                m = n
                idxm = idxn
            while idxm < len(m):
                res.append(m[idxm])
                idxm += 1
            return res

        root1l, root2l = [], []
        inorder(root1, root1l)
        inorder(root2, root2l)
        return (root1l if root1l else root2l) if not root1l or not root2l \
            else merge(root1l, root2l)


# @lc code=end
