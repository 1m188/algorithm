#
# @lc app=leetcode.cn id=3634 lang=python3
# @lcpr version=30204
#
# [3634] 使数组平衡的最少移除数目
#
# https://leetcode.cn/problems/minimum-removals-to-balance-array/description/
#
# algorithms
# Medium (45.35%)
# Likes:    27
# Dislikes: 0
# Total Accepted:    12.2K
# Total Submissions: 25.8K
# Testcase Example:  '[2,1,5]\n2'
#
# 给你一个整数数组 nums 和一个整数 k。
#
# 如果一个数组的 最大 元素的值 至多 是其 最小 元素的 k 倍，则该数组被称为是 平衡 的。
#
# 你可以从 nums 中移除 任意 数量的元素，但不能使其变为 空 数组。
#
# 返回为了使剩余数组平衡，需要移除的元素的 最小 数量。
#
# 注意：大小为 1 的数组被认为是平衡的，因为其最大值和最小值相等，且条件总是成立。
#
#
#
# 示例 1:
#
#
# 输入：nums = [2,1,5], k = 2
#
# 输出：1
#
# 解释：
#
#
# 移除 nums[2] = 5 得到 nums = [2, 1]。
# 现在 max = 2, min = 1，且 max <= min * k，因为 2 <= 1 * 2。因此，答案是 1。
#
#
#
# 示例 2:
#
#
# 输入：nums = [1,6,2,9], k = 3
#
# 输出：2
#
# 解释：
#
#
# 移除 nums[0] = 1 和 nums[3] = 9 得到 nums = [6, 2]。
# 现在 max = 6, min = 2，且 max <= min * k，因为 6 <= 2 * 3。因此，答案是 2。
#
#
#
# 示例 3:
#
#
# 输入：nums = [4,6], k = 2
#
# 输出：0
#
# 解释：
#
#
# 由于 nums 已经平衡，因为 6 <= 4 * 2，所以不需要移除任何元素。
#
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^9
# 1 <= k <= 10^5
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return 0

        if len(nums) == 2:
            min_val = min(nums)
            max_val = max(nums)
            return 0 if max_val <= min_val * k else 1

        nums.sort()
        n = len(nums)
        ans = n
        right = 0
        for left in range(n):
            while right < n and nums[right] <= nums[left] * k:
                right += 1
            ans = min(ans, n - (right - left))
        return ans


# @lc code=end


#
# @lcpr case=start
# [2,1,5]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,6,2,9]\n3\n
# @lcpr case=end

# @lcpr case=start
# [4,6]\n2\n
# @lcpr case=end

#
