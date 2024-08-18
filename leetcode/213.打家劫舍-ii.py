#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#
# https://leetcode.cn/problems/house-robber-ii/description/
#
# algorithms
# Medium (43.74%)
# Likes:    1053
# Dislikes: 0
# Total Accepted:    248K
# Total Submissions: 567K
# Testcase Example:  '[2,3,2]'
#
# 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
# ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
#
# 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
#
#
#
# 示例 1：
#
#
# 输入：nums = [2,3,2]
# 输出：3
# 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
#
#
# 示例 2：
#
#
# 输入：nums = [1,2,3,1]
# 输出：4
# 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
# 偷窃到的最高金额 = 1 + 3 = 4 。
#
# 示例 3：
#
#
# 输入：nums = [1,2,3]
# 输出：3
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 1000
#
#
#
'''
考虑两种情况：

1. 偷第1家，不偷最后1家
2. 偷最后1家，不偷第1家

其他的和原来的相同，最后由于最后1家是定好的了，不一定是最优解，最优解
可能在前面，因此要返回所有元素里的最大值

以及最后，考虑只有1个元素和2个元素的情况
'''

from typing import List


# @lc code=start
class Solution:

    def rob(self, nums: List[int]) -> int:

        if len(nums) == 1: return nums[0]
        elif len(nums) == 2: return max(nums)

        l1 = [0 for _ in range(len(nums))]
        l2 = l1.copy()

        l1[0] = nums[0]
        l1[1] = l1[0]
        for i in range(2, len(l1)):
            if i == len(l1) - 1:
                l1[i] = l1[i - 1]
            else:
                l1[i] = max(l1[i - 1], l1[i - 2] + nums[i])

        l2[0] = 0
        l2[1] = nums[1]
        for i in range(2, len(l1)):
            if i == len(l2) - 1:
                l2[i] = l2[i - 2] + nums[i]
            else:
                l2[i] = max(l2[i - 1], l2[i - 2] + nums[i])

        return max(max(l1), max(l2))


# @lc code=end
