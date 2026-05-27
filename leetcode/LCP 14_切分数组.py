#
# @lc app=leetcode.cn id=LCP 14 lang=python3
# @lcpr version=30204
#
# [LCP 14] 切分数组
#
# https://leetcode.cn/problems/qie-fen-shu-zu/description/
#
# algorithms
# Hard (26.38%)
# Likes:    66
# Dislikes: 0
# Total Accepted:    5.5K
# Total Submissions: 20.7K
# Testcase Example:  '[2,3,3,2,3,3]'
#
# 给定一个整数数组 nums ，小李想将 nums 切割成若干个非空子数组，使得每个子数组最左边的数和最右边的数的最大公约数大于 1
# 。为了减少他的工作量，请求出最少可以切成多少个子数组。
#
# 示例 1：
#
#
# 输入：nums = [2,3,3,2,3,3]
#
# 输出：2
#
# 解释：最优切割为 [2,3,3,2] 和 [3,3] 。第一个子数组头尾数字的最大公约数为 2 ，第二个子数组头尾数字的最大公约数为 3 。
#
#
# 示例 2：
#
#
# 输入：nums = [2,3,5,7]
#
# 输出：4
#
# 解释：只有一种可行的切割：[2], [3], [5], [7]
#
#
# 限制：
#
#
# 1 <= nums.length <= 10^5
# 2 <= nums[i] <= 10^6
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
# 预处理：计算 1e6 以内每个数的最小质因数 (Lowest Prime Factor)
max_num = 10**6
lpf = list(range(max_num + 1))  # lpf[i] 初始化为 i
for i in range(2, int(max_num**0.5) + 1):
    if lpf[i] == i:  # i 是质数
        for j in range(i * i, max_num + 1, i):
            if lpf[j] == j:
                lpf[j] = i


class Solution:
    def splitArray(self, nums: List[int]) -> int:
        def get_factors(x):
            """利用预处理的 lpf 快速分解质因数"""
            factors = set()
            while x != 1:
                p = lpf[x]
                factors.add(p)
                while x % p == 0:
                    x = x // p
            return factors

        n = len(nums)
        if n == 0:
            return 0

        # prev_dp 表示 dp[i]，即前 i 个元素的最少分割数
        prev_dp = 0
        # prime_min[p]: 记录包含质因数 p 的位置对应的最小 dp 值
        prime_min = dict()

        for i in range(n):
            num = nums[i]
            factors = get_factors(num)

            # 1. 初始情况：当前元素自己作为一个新子数组
            curr_dp = prev_dp + 1

            # 2. 尝试通过质因数与前面的数组合并
            for p in factors:
                if p in prime_min:
                    curr_dp = min(curr_dp, prime_min[p] + 1)

            # 3. 更新当前质因数对应的最小 dp 值 (为了后面的元素能合并到这里)
            # 注意：这里用的是 prev_dp (即 dp[i])，因为如果后面合并到 i，分割数是 dp[i] + 1
            for p in factors:
                if p in prime_min:
                    if prev_dp < prime_min[p]:
                        prime_min[p] = prev_dp
                else:
                    prime_min[p] = prev_dp

            prev_dp = curr_dp

        return prev_dp


# @lc code=end


#
# @lcpr case=start
# [2,3,3,2,3,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,3,5,7]\n
# @lcpr case=end

#
