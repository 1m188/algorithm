#
# @lc app=leetcode.cn id=3139 lang=python3
# @lcpr version=30204
#
# [3139] 使数组中所有元素相等的最小开销
#
# https://leetcode.cn/problems/minimum-cost-to-equalize-array/description/
#
# algorithms
# Hard (22.38%)
# Likes:    11
# Dislikes: 0
# Total Accepted:    2.7K
# Total Submissions: 12.2K
# Testcase Example:  '[4,1]\n5\n2'
#
# 给你一个整数数组 nums 和两个整数 cost1 和 cost2 。你可以执行以下 任一 操作 任意 次：
#
#
# 从 nums 中选择下标 i 并且将 nums[i] 增加 1 ，开销为 cost1。
# 选择 nums 中两个 不同 下标 i 和 j ，并且将 nums[i] 和 nums[j] 都 增加 1 ，开销为 cost2 。
#
#
# 你的目标是使数组中所有元素都 相等 ，请你返回需要的 最小开销 之和。
#
# 由于答案可能会很大，请你将它对 10^9 + 7 取余 后返回。
#
#
#
# 示例 1：
#
#
# 输入：nums = [4,1], cost1 = 5, cost2 = 2
#
# 输出：15
#
# 解释：
#
# 执行以下操作可以使数组中所有元素相等：
#
#
# 将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,2] 。
# 将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,3] 。
# 将 nums[1] 增加 1 ，开销为 5 ，nums 变为 [4,4] 。
#
#
# 总开销为 15 。
#
#
# 示例 2：
#
#
# 输入：nums = [2,3,3,3,5], cost1 = 2, cost2 = 1
#
# 输出：6
#
# 解释：
#
# 执行以下操作可以使数组中所有元素相等：
#
#
# 将 nums[0] 和 nums[1] 同时增加 1 ，开销为 1 ，nums 变为 [3,4,3,3,5] 。
# 将 nums[0] 和 nums[2] 同时增加 1 ，开销为 1 ，nums 变为 [4,4,4,3,5] 。
# 将 nums[0] 和 nums[3] 同时增加 1 ，开销为 1 ，nums 变为 [5,4,4,4,5] 。
# 将 nums[1] 和 nums[2] 同时增加 1 ，开销为 1 ，nums 变为 [5,5,5,4,5] 。
# 将 nums[3] 增加 1 ，开销为 2 ，nums 变为 [5,5,5,5,5] 。
#
#
# 总开销为 6 。
#
#
# 示例 3：
#
#
# 输入：nums = [3,5,3], cost1 = 1, cost2 = 3
#
# 输出：4
#
# 解释：
#
# 执行以下操作可以使数组中所有元素相等：
#
#
# 将 nums[0] 增加 1 ，开销为 1 ，nums 变为 [4,5,3] 。
# 将 nums[0] 增加 1 ，开销为 1 ，nums 变为 [5,5,3] 。
# 将 nums[2] 增加 1 ，开销为 1 ，nums 变为 [5,5,4] 。
# 将 nums[2] 增加 1 ，开销为 1 ，nums 变为 [5,5,5] 。
#
#
# 总开销为 4 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^6
# 1 <= cost1 <= 10^6
# 1 <= cost2 <= 10^6
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def minCostToEqualizeArray(self, nums: List[int], cost1: int, cost2: int) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        S = sum(nums)  # 数组总和
        M = max(nums)  # 最大值
        m = min(nums)  # 最小值

        # 如果双倍操作不比两个单倍操作划算，全部使用单倍操作
        if cost2 >= 2 * cost1:
            total = n * M - S  # 所有元素提升到 M 需要的总增量
            return (total * cost1) % MOD

        # 辅助函数：计算目标值为 t 时的最小开销（不取模，中间值可能很大）
        def calc_cost(t: int) -> int:
            total = n * t - S  # 总共需要的增量
            max_diff = t - m  # 最小值元素需要的增量最多
            other_sum = total - max_diff  # 其余元素需要的增量之和

            if max_diff > other_sum:
                # 最大差值元素需要的增量超过其余元素之和
                # 最多只能配对 other_sum 次
                pairs = other_sum
            else:
                # 可以充分配对
                pairs = total // 2

            remaining = total - 2 * pairs  # 剩余单次操作次数
            return pairs * cost2 + remaining * cost1

        # 收集候选目标值
        candidates = {M}

        if n > 2:
            # 情况2a与2b的分界点：max_diff == other_sum 时
            # 即 t = (S - 2*m) / (n - 2)，ceil 取整得到进入2b的最小 t
            t_border = (S - 2 * m + n - 3) // (n - 2)
            if t_border < M:
                t_border = M

            # 在2a区域内，开销是 t 的线性函数，斜率 A = (n-1)*cost2 + (2-n)*cost1
            A = (n - 1) * cost2 + (2 - n) * cost1
            if A < 0:
                # 斜率为负，在2a内 t 越大开销越小，取2a的最大 t
                t_2a_end = t_border - 1
                if t_2a_end >= M:
                    candidates.add(t_2a_end)

            # 2b区域起点及附近值，以处理 n 为奇数时 total 奇偶性导致的开销波动
            for dt in range(-2, 3):
                t_cand = t_border + dt
                if t_cand >= M:
                    candidates.add(t_cand)
        else:
            # n <= 2 时最优目标值必为 M，额外检查 M+1 以防边界情况
            candidates.add(M + 1)

        ans = min(calc_cost(t) for t in candidates)
        return ans % MOD


# @lc code=end


#
# @lcpr case=start
# [4,1]\n5\n2\n
# @lcpr case=end

# @lcpr case=start
# [2,3,3,3,5]\n2\n1\n
# @lcpr case=end

# @lcpr case=start
# [3,5,3]\n1\n3\n
# @lcpr case=end

#
