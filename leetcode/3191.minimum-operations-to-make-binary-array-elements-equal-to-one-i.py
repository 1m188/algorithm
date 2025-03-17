#
# @lc app=leetcode.cn id=3191 lang=python3
# @lcpr version=30204
#
# [3191] 使二进制数组全部等于 1 的最少操作次数 I
#
# https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
#
# algorithms
# Medium (80.36%)
# Likes:    46
# Dislikes: 0
# Total Accepted:    21.6K
# Total Submissions: 26.8K
# Testcase Example:  '[0,1,1,1,0,0]'
#
# 给你一个二进制数组 nums 。
#
# 你可以对数组执行以下操作 任意 次（也可以 0 次）：
#
#
# 选择数组中 任意连续 3 个元素，并将它们 全部反转 。
#
#
# 反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。
#
# 请你返回将 nums 中所有元素变为 1 的 最少 操作次数。如果无法全部变成 1 ，返回 -1 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [0,1,1,1,0,0]
#
# 输出：3
#
# 解释：
# 我们可以执行以下操作：
#
#
# 选择下标为 0 ，1 和 2 的元素并反转，得到 nums = [1,0,0,1,0,0] 。
# 选择下标为 1 ，2 和 3 的元素并反转，得到 nums = [1,1,1,0,0,0] 。
# 选择下标为 3 ，4 和 5 的元素并反转，得到 nums = [1,1,1,1,1,1] 。
#
#
#
# 示例 2：
#
#
# 输入：nums = [0,1,1,1]
#
# 输出：-1
#
# 解释：
# 无法将所有元素都变为 1 。
#
#
#
#
# 提示：
#
#
# 3 <= nums.length <= 10^5
# 0 <= nums[i] <= 1
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        j = 0
        while True:
            for i in range(j, n):
                if nums[i] == 0:
                    break
            if i == n - 1 and nums[i] == 1: break
            if i + 3 > n: return -1

            nums[i] = abs(nums[i] - 1)
            nums[i + 1] = abs(nums[i + 1] - 1)
            nums[i + 2] = abs(nums[i + 2] - 1)
            j = i

            res += 1

        return res


# @lc code=end

#
# @lcpr case=start
# [0,1,1,1,0,0]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,1,1]\n
# @lcpr case=end

#
