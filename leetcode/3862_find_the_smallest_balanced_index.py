#
# @lc app=leetcode.cn id=3862 lang=python3
# @lcpr version=30204
#
# [3862] 找出最小平衡下标
#
# https://leetcode.cn/problems/find-the-smallest-balanced-index/description/
#
# algorithms
# Medium (22.40%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3K
# Total Submissions: 13.4K
# Testcase Example:  '[2,1,2]'
#
# 给你一个整数数组 nums。
#
# 如果某个下标 i 满足以下条件，则称其为 平衡下标： i 左侧所有元素的总和等于 i 右侧所有元素的乘积。
#
# 如果左侧没有元素，则总和视为 0。同样，如果右侧没有元素，则乘积视为 1。
#
# 要求返回最小的 平衡下标，如果不存在平衡下标，则返回 -1。
#
#
#
# 示例 1：
#
#
# 输入： nums = [2,1,2]
#
# 输出： 1
#
# 解释：
#
# 对于下标 i = 1：
#
#
# 左侧总和 = nums[0] = 2
# 右侧乘积 = nums[2] = 2
# 由于左侧总和等于右侧乘积，下标 1 是平衡下标。
#
#
# 没有更小的下标满足条件，因此答案是 1。
#
#
# 示例 2：
#
#
# 输入： nums = [2,8,2,2,5]
#
# 输出： 2
#
# 解释：
#
# 对于下标 i = 2：
#
#
# 左侧总和 = 2 + 8 = 10
# 右侧乘积 = 2 * 5 = 10
# 由于左侧总和等于右侧乘积，下标 2 是平衡下标。
#
#
# 没有更小的下标满足条件，因此答案是 2。
#
#
# 示例 3：
#
#
# 输入： nums = [1]
#
# 输出： -1
#
# 对于下标 i = 0：
#
#
# 左侧为空，因此左侧总和为 0。
# 右侧为空，因此右侧乘积为 1。
# 由于左侧总和不等于右侧乘积，下标 0 不是平衡下标。
#
#
# 因此，不存在平衡下标，答案是 -1。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^9
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        n = len(nums)
        # 计算前缀和
        prefix = [0] * (n + 1)  # prefix[i] = sum(nums[0..i-1])
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        total_sum = prefix[n]  # 数组总和，最大约 10^14
        # 右侧乘积上限：前缀和最大不超过 total_sum，超过此值不可能匹配
        CAP = total_sum  # 存为 total_sum 可安全截断

        # 从右向左计算后缀乘积，超过 CAP 时标记为 CAP+1
        suff_prod = [0] * (n + 1)  # suff_prod[i] = product(nums[i..n-1])，截断后
        suff_prod[n] = 1  # 空区间的乘积定义为 1
        for i in range(n - 1, -1, -1):
            if suff_prod[i + 1] > CAP // nums[i]:
                suff_prod[i] = CAP + 1  # 溢出标记
            else:
                suff_prod[i] = suff_prod[i + 1] * nums[i]

        # 从左向右寻找第一个平衡下标
        for i in range(n):
            # i 左侧和为 prefix[i]，i 右侧乘积为 suff_prod[i+1]
            if prefix[i] == suff_prod[i + 1]:
                return i

        return -1


#
# @lcpr case=start
# [2,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,8,2,2,5]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#
