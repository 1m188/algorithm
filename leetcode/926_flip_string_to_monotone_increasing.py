#
# @lc app=leetcode.cn id=926 lang=python3
# @lcpr version=30204
#
# [926] 将字符串翻转到单调递增
#
# https://leetcode.cn/problems/flip-string-to-monotone-increasing/description/
#
# algorithms
# Medium (64.05%)
# Likes:    391
# Dislikes: 0
# Total Accepted:    45.7K
# Total Submissions: 71.3K
# Testcase Example:  '"00110"'
#
# 如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。
#
# 给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。
#
# 返回使 s 单调递增的最小翻转次数。
#
#
#
# 示例 1：
#
# 输入：s = "00110"
# 输出：1
# 解释：翻转最后一位得到 00111.
#
#
# 示例 2：
#
# 输入：s = "010110"
# 输出：2
# 解释：翻转得到 011111，或者是 000111。
#
#
# 示例 3：
#
# 输入：s = "00011000"
# 输出：2
# 解释：翻转得到 00000000。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 10^5
# s[i] 为 '0' 或 '1'
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        """
        前缀和枚举分割点

        单调递增字符串要求：前部分全 0，后部分全 1
        枚举分割点 i（[0..i] 全 0，[i+1..n-1] 全 1）：
        - 左侧需翻转的 1 的个数 = ones_left
        - 右侧需翻转的 0 的个数 = (右侧长度) - ones_right
        """
        n = len(s)
        total_ones = s.count("1")

        ans = float("inf")
        prefix_ones = 0  # 当前前缀中 1 的个数

        for i in range(n):
            # 分割点 i：左侧 [0..i] 全 0，右侧 [i+1..n-1] 全 1
            prefix_ones += int(s[i])
            ones_left = prefix_ones  # 左侧需要翻转的 1
            ones_right = total_ones - prefix_ones
            zeros_right = (n - i - 1) - ones_right  # 右侧需要翻转的 0
            flips = ones_left + zeros_right
            if flips < ans:
                ans = flips

        # 边界情况：全部变 1（分割点在 -1，左侧为空）
        ans = min(ans, total_ones)
        # 边界情况：全部变 0（分割点在 n-1，即全部在左侧）
        ans = min(ans, n - total_ones)

        return ans


# @lc code=end


#
# @lcpr case=start
# "00110"\n
# @lcpr case=end

# @lcpr case=start
# "010110"\n
# @lcpr case=end

# @lcpr case=start
# "00011000"\n
# @lcpr case=end

#
