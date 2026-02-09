#
# @lc app=leetcode.cn id=1382 lang=python3
# @lcpr version=30204
#
# [1382] 将二叉搜索树变平衡
#
# https://leetcode.cn/problems/balance-a-binary-search-tree/description/
#
# algorithms
# Medium (75.69%)
# Likes:    240
# Dislikes: 0
# Total Accepted:    39.1K
# Total Submissions: 51.4K
# Testcase Example:  '[1,null,2,null,3,null,4]'
#
# 给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
#
# 如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
#
#
#
# 示例 1：
#
#
#
# 输入：root = [1,null,2,null,3,null,4,null,null]
# 输出：[2,1,3,null,null,null,4]
# 解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
#
#
# 示例 2：
#
#
#
# 输入: root = [2,1,3]
# 输出: [2,1,3]
#
#
#
#
# 提示：
#
#
# 树节点的数目在 [1, 10^4] 范围内。
# 1 <= Node.val <= 10^5
#
#
#


# @lcpr-template-start
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if not root:
            return root

        arr = []

        def inorder(root):
            if not root:
                return
            inorder(root.left)
            arr.append(root.val)
            inorder(root.right)

        inorder(root)

        def build(arr: list[int]) -> Optional[TreeNode]:
            if not arr:
                return None
            if len(arr) == 1:
                return TreeNode(arr[0])
            mid = len(arr) // 2
            node = TreeNode(arr[mid])
            node.left = build(arr[:mid])
            node.right = build(arr[mid + 1 :])
            return node

        return build(arr)


# @lc code=end


#
# @lcpr case=start
# [1,null,2,null,3,null,4,null,null]\n
# @lcpr case=end

# @lcpr case=start
# [2,1,3]\n
# @lcpr case=end

#
