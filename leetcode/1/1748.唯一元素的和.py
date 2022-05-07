#
# @lc app=leetcode.cn id=1748 lang=python3
#
# [1748] 唯一元素的和
#
# https://leetcode-cn.com/problems/sum-of-unique-elements/description/
#
# algorithms
# Easy (79.04%)
# Likes:    65
# Dislikes: 0
# Total Accepted:    39.1K
# Total Submissions: 49.5K
# Testcase Example:  '[1,2,3,2]'
#
# 给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
#
# 请你返回 nums 中唯一元素的 和 。
#
#
#
# 示例 1：
#
# 输入：nums = [1,2,3,2]
# 输出：4
# 解释：唯一元素为 [1,3] ，和为 4 。
#
#
# 示例 2：
#
# 输入：nums = [1,1,1,1,1]
# 输出：0
# 解释：没有唯一元素，和为 0 。
#
#
# 示例 3 ：
#
# 输入：nums = [1,2,3,4,5]
# 输出：15
# 解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:

    def sumOfUnique(self, nums: List[int]) -> int:

        di = {}

        for i in nums:
            if i not in di:
                di[i] = 1
            else:
                di[i] += 1

        res = 0
        for i, j in list(di.items()):
            if j == 1:
                res += i
        return res


# @lc code=end
