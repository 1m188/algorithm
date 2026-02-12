#
# @lc app=leetcode.cn id=面试题 04.08 lang=python3
# @lcpr version=30204
#
# [面试题 04.08] 首个共同祖先
#
# https://leetcode.cn/problems/first-common-ancestor-lcci/description/
#
# LCCI
# Medium (72.17%)
# Likes:    106
# Dislikes: 0
# Total Accepted:    33.6K
# Total Submissions: 46.5K
# Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
#
# 设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。
#
# 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]
#
# ⁠   3
# ⁠  / \
# ⁠ 5   1
# ⁠/ \ / \
# 6  2 0  8
# ⁠ / \
# ⁠7   4
#
#
# 示例 1：
#
# 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
# 输出：3
# 解释：节点 5 和节点 1 的最近公共祖先是节点 3。
#
# 示例 2：
#
# 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
# 输出：5
# 解释：节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
#
# 提示：
#
# 所有节点的值都是唯一的。
# p、q 为不同节点且均存在于给定的二叉树中。
#
#


# @lcpr-template-start
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:

        def dfs(root: TreeNode, target: TreeNode, li: list[TreeNode]) -> bool:
            li.append(root)
            if root == target:
                return True
            if root.left and dfs(root.left, target, li):
                return True
            if root.right and dfs(root.right, target, li):
                return True
            li.pop()
            return False

        path_to_p, path_to_q = [], []
        dfs(root, p, path_to_p)
        dfs(root, q, path_to_q)

        ans = None
        index_p, index_q = 0, 0
        while index_p < len(path_to_p) and index_q < len(path_to_q):
            if path_to_p[index_p] == path_to_q[index_q]:
                ans = path_to_p[index_p]
            index_p += 1
            index_q += 1
        return ans


# @lc code=end


#
# @lcpr case=start
# [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
# @lcpr case=end

# @lcpr case=start
# [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
# @lcpr case=end

#
