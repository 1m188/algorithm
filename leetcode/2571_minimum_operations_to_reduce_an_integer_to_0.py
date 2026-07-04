#
# @lc app=leetcode.cn id=2571 lang=python3
# @lcpr version=30204
#
# [2571] 将整数减少到零需要的最少操作数
#
# https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/description/
#
# algorithms
# Medium (59.18%)
# Likes:    61
# Dislikes: 0
# Total Accepted:    11.9K
# Total Submissions: 20K
# Testcase Example:  '39'
#
# 给你一个正整数 n ，你可以执行下述操作 任意 次：
#
#
# n 加上或减去 2 的某个 幂
#
#
# 返回使 n 等于 0 需要执行的 最少 操作数。
#
# 如果 x == 2^i 且其中 i >= 0 ，则数字 x 是 2 的幂。
#
#
#
# 示例 1：
#
# 输入：n = 39
# 输出：3
# 解释：我们可以执行下述操作：
# - n 加上 2^0 = 1 ，得到 n = 40 。
# - n 减去 2^3 = 8 ，得到 n = 32 。
# - n 减去 2^5 = 32 ，得到 n = 0 。
# 可以证明使 n 等于 0 需要执行的最少操作数是 3 。
#
#
# 示例 2：
#
# 输入：n = 54
# 输出：3
# 解释：我们可以执行下述操作：
# - n 加上 2^1 = 2 ，得到 n = 56 。
# - n 加上 2^3 = 8 ，得到 n = 64 。
# - n 减去 2^6 = 64 ，得到 n = 0 。
# 使 n 等于 0 需要执行的最少操作数是 3 。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 10^5
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def minOperations(self, n: int) -> int:
        """
        位运算贪心

        核心思路：
        - 每次操作可加减任意 2 的幂，目标是用最少操作使 n 变为 0
        - 从低到高扫描 n 的二进制位：
          若当前位和更高一位均为 1（连续两个 1），则加上 2^i 产生进位，
          将连续 1 的区间消去（进位后变成单个高位的 1）；
          否则（孤立 1），直接减去 2^i。
        - 每次操作 ans+1，直到 n 为 0
        """
        ans = 0
        while n:
            lowbit = n & -n  # 最低位的 1
            if n & (lowbit << 1):
                # 连续两个 1：加上 2^i 触发进位，消除连续 1
                n += lowbit
            else:
                # 孤立 1：直接减去
                n -= lowbit
            ans += 1
        return ans


# @lc code=end


#
# @lcpr case=start
# 39\n
# @lcpr case=end

# @lcpr case=start
# 54\n
# @lcpr case=end

#
