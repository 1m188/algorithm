#
# @lc app=leetcode.cn id=3833 lang=python3
# @lcpr version=30204
#
# [3833] 统计主导元素下标数
#
# https://leetcode.cn/problems/count-dominant-indices/description/
#
# algorithms
# Easy (76.50%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    2.6K
# Total Submissions: 3.4K
# Testcase Example:  '[5,4,3]'
#
# 给你一个长度为 n 的整数数组 nums。
#
# 当下标 i 满足以下条件时，该下标处的元素被称为 主导元素：nums[i] > average(nums[i + 1], nums[i + 2],
# ..., nums[n - 1])
#
# 你的任务是统计数组中 主导元素 的下标数。
#
# 平均值 是指一组数的总和除以该组数的个数得到的值。
#
# 注意：数组的 最右边元素 不算作 主导元素 。
#
#
#
# 示例 1：
#
#
# 输入： nums = [5,4,3]
#
# 输出： 2
#
# 解释：
#
#
# 在下标 i = 0 处，值 5 是主导元素，因为 5 > average(4, 3) = 3.5。
# 在下标 i = 1 处，值 4 是主导元素，相对于子数组 [3]。
# 下标 i = 2 不是主导元素，因为它右侧没有元素。因此答案是 2。
#
#
#
# 示例 2：
#
#
# 输入： nums = [4,1,2]
#
# 输出： 1
#
# 解释：
#
#
# 在下标 i = 0 处，值 4 是主导元素，相对于子数组 [1, 2]。
# 在下标 i = 1 处，值 1 不是主导元素。
# 下标 i = 2 不是主导元素，因为它右侧没有元素。因此答案是 1。
#
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 100​​​​​​​
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def dominantIndices(self, nums: List[int]) -> int:

        ans = 0
        n = len(nums)
        sums = nums[-1]
        cnt = 1

        for i in range(n - 2, -1, -1):
            avg = sums / cnt
            if nums[i] > avg:
                ans += 1
            sums += nums[i]
            cnt += 1

        return ans


# @lc code=end


#
# @lcpr case=start
# [5,4,3]\n
# @lcpr case=end

# @lcpr case=start
# [4,1,2]\n
# @lcpr case=end

#
