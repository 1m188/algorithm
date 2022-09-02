#
# @lc app=leetcode.cn id=229 lang=python3
#
# [229] 多数元素 II
#
# https://leetcode.cn/problems/majority-element-ii/description/
#
# algorithms
# Medium (53.67%)
# Likes:    612
# Dislikes: 0
# Total Accepted:    83.7K
# Total Submissions: 156K
# Testcase Example:  '[3,2,3]'
#
# 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
#
#
#
# 示例 1：
#
#
# 输入：nums = [3,2,3]
# 输出：[3]
#
# 示例 2：
#
#
# 输入：nums = [1]
# 输出：[1]
#
#
# 示例 3：
#
#
# 输入：nums = [1,2]
# 输出：[1,2]
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 5 * 10^4
# -10^9 <= nums[i] <= 10^9
#
#
#
#
# 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
#
#
'''
排序做比较，并且计数
'''

from typing import List


# @lc code=start
class Solution:

    def majorityElement(self, nums: List[int]) -> List[int]:

        if len(nums) < 3: return list(set(nums))

        limit = len(nums) // 3

        nums.sort()

        cnt = 1
        res = []

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]: cnt += 1
            else:
                if cnt > limit: res.append(nums[i - 1])
                cnt = 1
        if cnt > limit: res.append(nums[i - 1])  # 这里不要忘记最后可能还有没有计数判断的内容

        return res


# @lc code=end
