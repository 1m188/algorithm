#
# @lc app=leetcode.cn id=1909 lang=python3
#
# [1909] 删除一个元素使数组严格递增
#
# https://leetcode.cn/problems/remove-one-element-to-make-the-array-strictly-increasing/description/
#
# algorithms
# Easy (29.94%)
# Likes:    44
# Dislikes: 0
# Total Accepted:    11.6K
# Total Submissions: 38.8K
# Testcase Example:  '[1,2,10,5,7]'
#
# 给你一个下标从 0 开始的整数数组 nums ，如果 恰好 删除 一个 元素后，数组 严格递增 ，那么请你返回 true ，否则返回 false
# 。如果数组本身已经是严格递增的，请你也返回 true 。
#
# 数组 nums 是 严格递增 的定义为：对于任意下标的 1 <= i < nums.length 都满足 nums[i - 1] < nums[i]
# 。
#
#
#
# 示例 1：
#
# 输入：nums = [1,2,10,5,7]
# 输出：true
# 解释：从 nums 中删除下标 2 处的 10 ，得到 [1,2,5,7] 。
# [1,2,5,7] 是严格递增的，所以返回 true 。
#
#
# 示例 2：
#
# 输入：nums = [2,3,1,2]
# 输出：false
# 解释：
# [3,1,2] 是删除下标 0 处元素后得到的结果。
# [2,1,2] 是删除下标 1 处元素后得到的结果。
# [2,3,2] 是删除下标 2 处元素后得到的结果。
# [2,3,1] 是删除下标 3 处元素后得到的结果。
# 没有任何结果数组是严格递增的，所以返回 false 。
#
# 示例 3：
#
# 输入：nums = [1,1,1]
# 输出：false
# 解释：删除任意元素后的结果都是 [1,1] 。
# [1,1] 不是严格递增的，所以返回 false 。
#
#
# 示例 4：
#
# 输入：nums = [1,2,3]
# 输出：true
# 解释：[1,2,3] 已经是严格递增的，所以返回 true 。
#
#
#
#
# 提示：
#
#
# 2 <= nums.length <= 1000
# 1 <= nums[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def canBeIncreasing(self, nums: List[int]) -> bool:

        def judge(li: list[int]) -> bool:
            for i in range(1, len(li)):
                if not li[i] > li[i - 1]: return False
            return True

        n = len(nums)

        if n == 2: return True

        for i in range(n - 1):
            if not nums[i + 1] > nums[i]: break
        if nums[i + 1] > nums[i]: return True

        for j in range(i + 1, n - 1):
            if not nums[j + 1] > nums[j]: return False

        if judge(nums[:i] + nums[i + 1:]): return True
        if judge(nums[:i + 1] + nums[i + 2:]): return True
        return False


# @lc code=end
