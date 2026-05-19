#
# @lc app=leetcode.cn id=3866 lang=python3
# @lcpr version=30204
#
# [3866] 找到第一个唯一偶数
#
# https://leetcode.cn/problems/first-unique-even-element/description/
#
# algorithms
# Easy (65.08%)
# Likes:    0
# Dislikes: 0
# Total Accepted:    2.1K
# Total Submissions: 3.2K
# Testcase Example:  '[3,4,2,5,4,6]'
#
# 给你一个整数数组 nums。
#
# 请你返回一个整数，表示 nums 中出现 恰好 一次的第一个 偶数（以数组下标最早为准）。如果不存在这样的整数，返回 -1。
#
# 如果一个整数 x 能被 2 整除，那么它就被认为是 偶数。
#
#
#
# 示例 1：
#
#
# 输入： nums = [3,4,2,5,4,6]
#
# 输出： 2
#
# 解释：
#
# 2 和 6 都是偶数，并且它们都恰好出现一次。因为 2 在数组中出现得更早，所以答案是 2。
#
#
# 示例 2：
#
#
# 输入： nums = [4,4]
#
# 输出： -1
#
# 解释：
#
# 没有恰好出现一次的偶数，所以返回 -1。
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


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:

        se = [0 for _ in range(101)]
        for n in nums:
            se[n] += 1
        for n in nums:
            if se[n] == 1 and n & 0x1 == 0:
                return n
        return -1


# @lc code=end


#
# @lcpr case=start
# [3,4,2,5,4,6]\n
# @lcpr case=end

# @lcpr case=start
# [4,4]\n
# @lcpr case=end

#
