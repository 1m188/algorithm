#
# @lc app=leetcode.cn id=面试题 04.10 lang=python3
# @lcpr version=30204
#
# [面试题 04.10] 检查子树
#
# https://leetcode.cn/problems/check-subtree-lcci/description/
#
# LCCI
# Medium (64.18%)
# Likes:    91
# Dislikes: 0
# Total Accepted:    33.3K
# Total Submissions: 51.9K
# Testcase Example:  '[1, 2, 3]\n[2]'
#
# 检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。
#
# 如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。
#
# 注意：此题相对书上原题略有改动。
#
# 示例 1：
#
# ⁠输入：t1 = [1, 2, 3], t2 = [2]
# ⁠输出：true
#
#
# 示例 2：
#
# ⁠输入：t1 = [1, null, 2, 4], t2 = [3, 2]
# ⁠输出：false
#
#
# 提示：
#
#
# 树的节点数目范围为 [0, 20000]。
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
    def checkSubTree(self, t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:

        def pre(root: Optional[TreeNode], li: list[str]):
            if not root:
                li.append("#")
                return
            li.append(str(root.val))
            pre(root.left, li)
            pre(root.right, li)

        li_t1, li_t2 = [], []
        pre(t1, li_t1)
        pre(t2, li_t2)

        n1, n2 = len(li_t1), len(li_t2)
        if n1 < n2:
            return False

        for i in range(n1 - n2 + 1):
            if li_t1[i : i + n2] == li_t2:
                return True
        return False


# @lc code=end


#
# @lcpr case=start
# [1, 2, 3]\n[2]\n
# @lcpr case=end

# @lcpr case=start
# [1, null, 2, 4]\n[3, 2]\n
# @lcpr case=end

#
