#
# @lc app=leetcode.cn id=1674 lang=python3
# @lcpr version=30204
#
# [1674] 使数组互补的最少操作次数
#
# https://leetcode.cn/problems/minimum-moves-to-make-array-complementary/description/
#
# algorithms
# Medium (46.00%)
# Likes:    142
# Dislikes: 0
# Total Accepted:    6.9K
# Total Submissions: 14.3K
# Testcase Example:  '[1,2,4,3]\n4'
#
# 给你一个长度为 偶数 n 的整数数组 nums 和一个整数 limit 。每一次操作，你可以将 nums 中的任何整数替换为 1 到 limit
# 之间的另一个整数。
#
# 如果对于所有下标 i（下标从 0 开始），nums[i] + nums[n - 1 - i] 都等于同一个数，则数组 nums 是 互补的 。例如，数组
# [1,2,3,4] 是互补的，因为对于所有下标 i ，nums[i] + nums[n - 1 - i] = 5 。
#
# 返回使数组 互补 的 最少 操作次数。
#
#
#
# 示例 1：
#
# 输入：nums = [1,2,4,3], limit = 4
# 输出：1
# 解释：经过 1 次操作，你可以将数组 nums 变成 [1,2,2,3]（加粗元素是变更的数字）：
# nums[0] + nums[3] = 1 + 3 = 4.
# nums[1] + nums[2] = 2 + 2 = 4.
# nums[2] + nums[1] = 2 + 2 = 4.
# nums[3] + nums[0] = 3 + 1 = 4.
# 对于每个 i ，nums[i] + nums[n-1-i] = 4 ，所以 nums 是互补的。
#
#
# 示例 2：
#
# 输入：nums = [1,2,2,1], limit = 2
# 输出：2
# 解释：经过 2 次操作，你可以将数组 nums 变成 [2,2,2,2] 。你不能将任何数字变更为 3 ，因为 3 > limit 。
#
#
# 示例 3：
#
# 输入：nums = [1,2,1,2], limit = 2
# 输出：0
# 解释：nums 已经是互补的。
#
#
#
#
# 提示：
#
#
# n == nums.length
# 2 <= n <= 10^5
# 1 <= nums[i] <= limit <= 10^5
# n 是偶数。
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        """
        差分数组 + 前缀和（扫描线）解法

        核心思路：
        对于每一对 (a, b)，分析达到目标总和 T 所需的操作次数：
          - T == a+b：不需要操作（0 次）
          - T ∈ [min(a,b)+1, max(a,b)+limit] 且 T ≠ a+b：只需修改一个数（1 次）
          - T 在其他范围：需要修改两个数（2 次）

        使用差分数组 diff，初始假设所有目标总和都需要 2 次操作，
        然后在对应区间上递减，通过前缀和扫描找到最小操作数。
        """
        n = len(nums)
        # 目标总和 T 的范围是 [2, 2*limit]，diff 数组多开一位方便处理
        diff = [0] * (2 * limit + 2)

        # 遍历每一对互补位置的元素
        for i in range(n // 2):
            a = nums[i]
            b = nums[n - 1 - i]

            sum_ab = a + b  # 无需修改就能达到的总和
            lo = min(a, b) + 1  # 修改一个数能达到的最小总和
            hi = max(a, b) + limit  # 修改一个数能达到的最大总和

            # 差分更新：初始假设所有 T ∈ [2, 2*limit] 都需要 2 次操作
            diff[2] += 2
            # 从 lo 开始，只需 1 次操作（比 2 次少 1）
            diff[lo] -= 1
            # 在 sum_ab 处只需要 0 次操作（比 1 次再少 1）
            diff[sum_ab] -= 1
            # 过了 sum_ab 恢复到需要 1 次操作
            diff[sum_ab + 1] += 1
            # 过了 hi 恢复到需要 2 次操作
            diff[hi + 1] += 1

        # 前缀和扫描，找到最小操作次数
        ans = float("inf")
        cur = 0
        for s in range(2, 2 * limit + 1):
            cur += diff[s]
            if cur < ans:
                ans = cur

        return ans


# @lc code=end


#
# @lcpr case=start
# [1,2,4,3]\n4\n
# @lcpr case=end

# @lcpr case=start
# [1,2,2,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,1,2]\n2\n
# @lcpr case=end

#
