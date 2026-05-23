#
# @lc app=leetcode.cn id=3471 lang=python3
# @lcpr version=30204
#
# [3471] 找出最大的几近缺失整数
#
# https://leetcode.cn/problems/find-the-largest-almost-missing-integer/description/
#
# algorithms
# Easy (31.83%)
# Likes:    10
# Dislikes: 0
# Total Accepted:    5.4K
# Total Submissions: 16.9K
# Testcase Example:  '[3,9,2,1,7]\n3'
#
# 给你一个整数数组 nums 和一个整数 k 。
#
# 如果整数 x 恰好仅出现在 nums 中的一个大小为 k 的子数组中，则认为 x 是 nums 中的几近缺失（almost missing）整数。
#
# 返回 nums 中 最大的几近缺失 整数，如果不存在这样的整数，返回 -1 。
# 子数组 是数组中的一个连续元素序列。
#
#
#
# 示例 1：
#
#
# 输入：nums = [3,9,2,1,7], k = 3
#
# 输出：7
#
# 解释：
#
#
# 1 出现在两个大小为 3 的子数组中：[9, 2, 1]、[2, 1, 7]
# 2 出现在三个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]、[2, 1, 7]
# 3 出现在一个大小为 3 的子数组中：[3, 9, 2]
# 7 出现在一个大小为 3 的子数组中：[2, 1, 7]
# 9 出现在两个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]
#
#
# 返回 7 ，因为它满足题意的所有整数中最大的那个。
#
#
# 示例 2：
#
#
# 输入：nums = [3,9,7,2,1,7], k = 4
#
# 输出：3
#
# 解释：
#
#
# 1 出现在两个大小为 4 的子数组中：[9, 7, 2, 1]、[7, 2, 1, 7]
# 2 出现在三个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
# 3 出现在一个大小为 4 的子数组中：[3, 9, 7, 2]
# 7 出现在三个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
# 9 出现在两个大小为 4 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]
#
#
# 返回 3 ，因为它满足题意的所有整数中最大的那个。
#
#
# 示例 3：
#
#
# 输入：nums = [0,0], k = 1
#
# 输出：-1
#
# 解释：
#
# 不存在满足题意的整数。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 50
# 0 <= nums[i] <= 50
# 1 <= k <= nums.length
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        # 用于记录每个数字出现在多少个不同的大小为k的子数组中
        frequency = {}
        n = len(nums)

        # 遍历所有起始索引，生成大小为k的子数组
        for i in range(n - k + 1):
            # 获取当前子数组
            subarray = nums[i : i + k]
            # 提取当前子数组中的唯一数字（去重）
            unique_in_sub = set(subarray)

            # 更新频率字典
            for num in unique_in_sub:
                frequency[num] = frequency.get(num, 0) + 1

        # 筛选出所有恰好只在一个子数组中出现过的数字
        candidates = [num for num in frequency if frequency[num] == 1]

        # 返回最大的候选数，若无候选数则返回-1
        return max(candidates) if candidates else -1


# @lc code=end


#
# @lcpr case=start
# [3,9,2,1,7]\n3\n
# @lcpr case=end

# @lcpr case=start
# [3,9,7,2,1,7]\n4\n
# @lcpr case=end

# @lcpr case=start
# [0,0]\n1\n
# @lcpr case=end

#
