#
# @lc app=leetcode.cn id=337 lang=python3
# @lcpr version=30204
#
# [337] 打家劫舍 III
#
# https://leetcode.cn/problems/house-robber-iii/description/
#
# algorithms
# Medium (62.58%)
# Likes:    2180
# Dislikes: 0
# Total Accepted:    450.2K
# Total Submissions: 719.4K
# Testcase Example:  '[3,2,3,null,3,null,1]'
#
# 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
#
# 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
# 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
#
# 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
#
#
#
# 示例 1:
#
#
#
# 输入: root = [3,2,3,null,3,null,1]
# 输出: 7
# 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
#
# 示例 2:
#
#
#
# 输入: root = [3,4,5,1,3,null,1]
# 输出: 9
# 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
#
#
#
#
# 提示：
#
#
#
#
# 树的节点数在 [1, 10^4] 范围内
# 0 <= Node.val <= 10^4
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
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]):
            """返回 [偷当前节点的最大收益, 不偷当前节点的最大收益]"""
            if not node:
                return [0, 0]

            left = dfs(node.left)
            right = dfs(node.right)

            # 偷当前节点：当前节点值 + 不偷左 + 不偷右
            rob_cur = node.val + left[1] + right[1]
            # 不偷当前节点：左右子树各自的最大值之和
            not_rob_cur = max(left[0], left[1]) + max(right[0], right[1])

            return [rob_cur, not_rob_cur]

        result = dfs(root)
        return max(result[0], result[1])


# @lc code=end


#
# @lcpr case=start
# [3,2,3,null,3,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,4,5,1,3,null,1]\n
# @lcpr case=end

#
