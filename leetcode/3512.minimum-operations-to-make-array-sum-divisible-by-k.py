#
# @lc app=leetcode.cn id=3512 lang=python3
# @lcpr version=30204
#
# [3512] 使数组和能被 K 整除的最少操作次数
#
# https://leetcode.cn/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/
#
# algorithms
# Easy (90.63%)
# Likes:    1
# Dislikes: 0
# Total Accepted:    3.4K
# Total Submissions: 3.8K
# Testcase Example:  '[3,9,7]\n5'
#
# 给你一个整数数组 nums 和一个整数 k。你可以执行以下操作任意次：
#
#
# 选择一个下标 i，并将 nums[i] 替换为 nums[i] - 1。
#
#
# 返回使数组元素之和能被 k 整除所需的最小操作次数。
#
#
#
# 示例 1：
#
#
# 输入： nums = [3,9,7], k = 5
#
# 输出： 4
#
# 解释：
#
#
# 对 nums[1] = 9 执行 4 次操作。现在 nums = [3, 5, 7]。
# 数组之和为 15，可以被 5 整除。
#
#
#
# 示例 2：
#
#
# 输入： nums = [4,1,3], k = 4
#
# 输出： 0
#
# 解释：
#
#
# 数组之和为 8，已经可以被 4 整除。因此不需要操作。
#
#
#
# 示例 3：
#
#
# 输入： nums = [3,2], k = 6
#
# 输出： 5
#
# 解释：
#
#
# 对 nums[0] = 3 执行 3 次操作，对 nums[1] = 2 执行 2 次操作。现在 nums = [0, 0]。
# 数组之和为 0，可以被 6 整除。
#
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 1000
# 1 <= k <= 100
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k


# @lc code=end

#
# @lcpr case=start
# [3,9,7]\n5\n
# @lcpr case=end

# @lcpr case=start
# [4,1,3]\n4\n
# @lcpr case=end

# @lcpr case=start
# [3,2]\n6\n
# @lcpr case=end

#
