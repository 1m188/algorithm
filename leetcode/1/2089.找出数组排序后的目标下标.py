#
# @lc app=leetcode.cn id=2089 lang=python3
#
# [2089] 找出数组排序后的目标下标
#
# https://leetcode-cn.com/problems/find-target-indices-after-sorting-array/description/
#
# algorithms
# Easy (81.06%)
# Likes:    14
# Dislikes: 0
# Total Accepted:    11K
# Total Submissions: 13.6K
# Testcase Example:  '[1,2,5,2,3]\n2'
#
# 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
#
# 目标下标 是一个满足 nums[i] == target 的下标 i 。
#
# 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增
# 顺序排列。
#
#
#
# 示例 1：
#
# 输入：nums = [1,2,5,2,3], target = 2
# 输出：[1,2]
# 解释：排序后，nums 变为 [1,2,2,3,5] 。
# 满足 nums[i] == 2 的下标是 1 和 2 。
#
#
# 示例 2：
#
# 输入：nums = [1,2,5,2,3], target = 3
# 输出：[3]
# 解释：排序后，nums 变为 [1,2,2,3,5] 。
# 满足 nums[i] == 3 的下标是 3 。
#
#
# 示例 3：
#
# 输入：nums = [1,2,5,2,3], target = 5
# 输出：[4]
# 解释：排序后，nums 变为 [1,2,2,3,5] 。
# 满足 nums[i] == 5 的下标是 4 。
#
#
# 示例 4：
#
# 输入：nums = [1,2,5,2,3], target = 4
# 输出：[]
# 解释：nums 中不含值为 4 的元素。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i], target <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:

    def targetIndices(self, nums: List[int], target: int) -> List[int]:

        nums.sort()

        ans = []

        for i in range(len(nums)):
            if nums[i] == target: ans.append(i)
            elif nums[i] > target: return ans

        return ans


# @lc code=end
