#
# @lc app=leetcode.cn id=1646 lang=python3
#
# [1646] 获取生成数组中的最大值
#
# https://leetcode.cn/problems/get-maximum-in-generated-array/description/
#
# algorithms
# Easy (51.66%)
# Likes:    88
# Dislikes: 0
# Total Accepted:    52.9K
# Total Submissions: 102.5K
# Testcase Example:  '7'
#
# 给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：
#
#
# nums[0] = 0
# nums[1] = 1
# 当 2  时，nums[2 * i] = nums[i]
# 当 2  时，nums[2 * i + 1] = nums[i] + nums[i + 1]
#
#
# 返回生成数组 nums 中的 最大 值。
#
#
#
# 示例 1：
#
#
# 输入：n = 7
# 输出：3
# 解释：根据规则：
# ⁠ nums[0] = 0
# ⁠ nums[1] = 1
# ⁠ nums[(1 * 2) = 2] = nums[1] = 1
# ⁠ nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
# ⁠ nums[(2 * 2) = 4] = nums[2] = 1
# ⁠ nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
# ⁠ nums[(3 * 2) = 6] = nums[3] = 2
# ⁠ nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
# 因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
#
#
# 示例 2：
#
#
# 输入：n = 2
# 输出：1
# 解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
#
#
# 示例 3：
#
#
# 输入：n = 3
# 输出：2
# 解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
#
#
#
#
# 提示：
#
#
# 0
#
#
#


# @lc code=start
class Solution:

    def getMaximumGenerated(self, n: int) -> int:

        li = [
            0, 1, 1, 2, 1, 3, 2, 3, 1, 4, 3, 5, 2, 5, 3, 4, 1, 5, 4, 7, 3, 8, 5, 7, 2, 7, 5, 8, 3, 7, 4, 5, 1, 6, 5, 9, 4, 11, 7, 10, 3, 11, 8, 13, 5, 12, 7, 9, 2, 9, 7, 12, 5, 13, 8, 11, 3, 10, 7, 11, 4, 9, 5, 6, 1, 7, 6, 11, 5, 14, 9, 13, 4, 15, 11, 18,
            7, 17, 10, 13, 3, 14, 11, 19, 8, 21, 13, 18, 5, 17, 12, 19, 7, 16, 9, 11, 2, 11, 9, 16, 7
        ]

        return max(li[:n + 1])


# @lc code=end
