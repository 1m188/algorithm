#
# @lc app=leetcode.cn id=3492 lang=python3
# @lcpr version=30204
#
# [3492] 船上可以装载的最大集装箱数量
#
# https://leetcode.cn/problems/maximum-containers-on-a-ship/description/
#
# algorithms
# Easy (82.65%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    5.6K
# Total Submissions: 6.7K
# Testcase Example:  '2\n3\n15'
#
# 给你一个正整数 n，表示船上的一个 n x n 的货物甲板。甲板上的每个单元格可以装载一个重量 恰好 为 w 的集装箱。
#
# 然而，如果将所有集装箱装载到甲板上，其总重量不能超过船的最大承载重量 maxWeight。
#
# 请返回可以装载到船上的 最大 集装箱数量。
#
#
#
# 示例 1：
#
#
# 输入： n = 2, w = 3, maxWeight = 15
#
# 输出： 4
#
# 解释：
#
# 甲板有 4 个单元格，每个集装箱的重量为 3。将所有集装箱装载后，总重量为 12，未超过 maxWeight。
#
#
# 示例 2：
#
#
# 输入： n = 3, w = 5, maxWeight = 20
#
# 输出： 4
#
# 解释：
#
# 甲板有 9 个单元格，每个集装箱的重量为 5。可以装载的最大集装箱数量为 4，此时总重量不超过 maxWeight。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 1000
# 1 <= w <= 1000
# 1 <= maxWeight <= 10^9
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def maxContainers(self, n: int, w: int, maxWeight: int) -> int:

        left, right = 1, n * n
        while left <= right:
            mid = (left + right) // 2
            if mid * w == maxWeight:
                return mid
            elif mid * w > maxWeight:
                right = mid - 1
            else:
                left = mid + 1
        for i in range(right, left + 1):
            if i * w <= maxWeight:
                return i


# @lc code=end

#
# @lcpr case=start
# 2\n3\n15\n
# @lcpr case=end

# @lcpr case=start
# 3\n5\n20\n
# @lcpr case=end

#
