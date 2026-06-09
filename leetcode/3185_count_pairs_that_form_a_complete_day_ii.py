#
# @lc app=leetcode.cn id=3185 lang=python3
# @lcpr version=30204
#
# [3185] 构成整天的下标对数目 II
#
# https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/description/
#
# algorithms
# Medium (59.41%)
# Likes:    49
# Dislikes: 0
# Total Accepted:    38.1K
# Total Submissions: 64.2K
# Testcase Example:  '[12,12,30,24,24]'
#
# 给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天
# 的下标对 i, j 的数目。
#
# 整天 定义为时间持续时间是 24 小时的 整数倍 。
#
# 例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。
#
#
#
# 示例 1：
#
#
# 输入： hours = [12,12,30,24,24]
#
# 输出： 2
#
# 解释：
#
# 构成整天的下标对分别是 (0, 1) 和 (3, 4)。
#
#
# 示例 2：
#
#
# 输入： hours = [72,48,24,3]
#
# 输出： 3
#
# 解释：
#
# 构成整天的下标对分别是 (0, 1)、(0, 2) 和 (1, 2)。
#
#
#
#
# 提示：
#
#
# 1 <= hours.length <= 5 * 10^5
# 1 <= hours[i] <= 10^9
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = [0] * 24  # cnt[r] 表示已遍历元素中模 24 余数为 r 的数量
        ans = 0

        for h in hours:
            r = h % 24
            # 需要找一个之前已遍历的、模 24 余数为 (24 - r) % 24 的元素配对
            complement = (24 - r) % 24
            ans += cnt[complement]
            cnt[r] += 1

        return ans


# @lc code=end


#
# @lcpr case=start
# [12,12,30,24,24]\n
# @lcpr case=end

# @lcpr case=start
# [72,48,24,3]\n
# @lcpr case=end

#
