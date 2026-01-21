#
# @lc app=leetcode.cn id=LCR 152 lang=python3
# @lcpr version=30204
#
# [LCR 152] 验证二叉搜索树的后序遍历序列
#
# https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/description/
#
# algorithms
# Medium (57.04%)
# Likes:    793
# Dislikes: 0
# Total Accepted:    246.9K
# Total Submissions: 432.9K
# Testcase Example:  '[4,9,6,5,8]'
#
# 请实现一个函数来判断整数数组 postorder 是否为二叉搜索树的后序遍历结果。
#
#
#
# 示例 1：
#
#
#
# 输入: postorder = [4,9,6,5,8]
# 输出: false
# 解释：从上图可以看出这不是一颗二叉搜索树
#
#
# 示例 2：
#
#
#
# 输入: postorder = [4,6,5,9,8]
# 输出: true
# 解释：可构建的二叉搜索树如上图
#
#
#
#
# 提示：
#
#
# 数组长度 <= 1000
# postorder 中无重复数字
#
#
#
#
#

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def verifyTreeOrder(self, postorder: List[int]) -> bool:
        if len(postorder) < 2: return True

        def judge(left: int, right: int) -> bool:
            if left >= right: return True
            root = postorder[right]
            mid = right
            for i in range(left, right):
                if postorder[i] > root:
                    mid = i
                    break
            if mid == right:
                return judge(left, right - 1)
            for i in range(mid, right):
                if postorder[i] < root:
                    return False
            return judge(left, mid - 1) and judge(mid, right - 1)

        return judge(0, len(postorder) - 1)


# @lc code=end

#
# @lcpr case=start
# [4,9,6,5,8]\n
# @lcpr case=end

# @lcpr case=start
# [4,6,5,9,8]\n
# @lcpr case=end

#
