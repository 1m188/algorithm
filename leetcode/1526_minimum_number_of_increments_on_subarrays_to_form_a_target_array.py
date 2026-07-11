#
# @lc app=leetcode.cn id=1526 lang=python3
# @lcpr version=30204
#
# [1526] 形成目标数组的子数组最少增加次数
#
# https://leetcode.cn/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
#
# algorithms
# Hard (73.51%)
# Likes:    128
# Dislikes: 0
# Total Accepted:    19.5K
# Total Submissions: 26.5K
# Testcase Example:  '[1,2,3,2,1]'
#
# 给你一个整数数组 target 和一个数组 initial ，initial 数组与 target  数组有同样的大小，且一开始全部为 0 。
#
# 一次操作中，你可以从 initial 数组中选择 任何 子数组，并将每个值加 1。
#
# 返回从 initial 数组构造 target 数组的最少操作次数。
#
# 答案保证在 32 位整数以内。
#
#
#
# 示例 1：
#
# 输入：target = [1,2,3,2,1]
# 输出：3
# 解释：我们需要至少 3 次操作从 intial 数组得到 target 数组。
# [0,0,0,0,0] 将下标为 0 到 4 的元素（包含二者）加 1 。
# [1,1,1,1,1] 将下标为 1 到 3 的元素（包含二者）加 1 。
# [1,2,2,2,1] 将下标为 2 的元素增加 1 。
# [1,2,3,2,1] 得到了目标数组。
#
#
# 示例 2：
#
# 输入：target = [3,1,1,2]
# 输出：4
# 解释：(initial)[0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2]
# (target) 。
#
#
# 示例 3：
#
# 输入：target = [3,1,5,4,2]
# 输出：7
# 解释：(initial)[0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1]
# ⁠                                 -> [3,1,2,2,2] -> [3,1,3,3,2] ->
# [3,1,4,4,2] -> [3,1,5,4,2] (target)。
#
#
# 示例 4：
#
# 输入：target = [1,1,1,1]
# 输出：1
#
#
#
#
# 提示：
#
#
# 1 <= target.length <= 10^5
# 1 <= target[i] <= 10^5
# 输入保证答案在 32 位整数范围内。
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        """
        贪心：差分正贡献

        核心思路：
        - 从全零数组出发，每次操作对子数组 +1
        - 操作次数 = target[0] + Σ max(0, target[i] - target[i-1])
        - 因为当 target[i] > target[i-1] 时，需要额外的操作来"拔高"
        - 当 target[i] <= target[i-1] 时，之前的操作已经覆盖了当前高度
        """
        ans = target[0]
        for i in range(1, len(target)):
            diff = target[i] - target[i - 1]
            if diff > 0:
                ans += diff
        return ans


# @lc code=end


#
# @lcpr case=start
# [1,2,3,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,5,4,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,1]\n
# @lcpr case=end

#
