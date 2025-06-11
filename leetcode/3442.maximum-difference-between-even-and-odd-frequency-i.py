#
# @lc app=leetcode.cn id=3442 lang=python3
# @lcpr version=30204
#
# [3442] 奇偶频次间的最大差值 I
#
# https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/description/
#
# algorithms
# Easy (60.66%)
# Likes:    11
# Dislikes: 0
# Total Accepted:    16.1K
# Total Submissions: 24.5K
# Testcase Example:  '"aaaaabbc"'
#
# 给你一个由小写英文字母组成的字符串 s。
#
# 请你找出字符串中两个字符 a1 和 a2 的出现频次之间的 最大 差值 diff = freq(a1) -
# freq(a2)，这两个字符需要满足：
#
#
# a1 在字符串中出现 奇数次 。
# a2 在字符串中出现 偶数次 。
#
#
# 返回 最大 差值。
#
#
#
# 示例 1：
#
#
# 输入：s = "aaaaabbc"
#
# 输出：3
#
# 解释：
#
#
# 字符 'a' 出现 奇数次 ，次数为 5 ；字符 'b' 出现 偶数次 ，次数为 2 。
# 最大差值为 5 - 2 = 3 。
#
#
#
# 示例 2：
#
#
# 输入：s = "abcabcab"
#
# 输出：1
#
# 解释：
#
#
# 字符 'a' 出现 奇数次 ，次数为 3 ；字符 'c' 出现 偶数次 ，次数为 2 。
# 最大差值为 3 - 2 = 1 。
#
#
#
#
#
# 提示：
#
#
# 3 <= s.length <= 100
# s 仅由小写英文字母组成。
# s 至少由一个出现奇数次的字符和一个出现偶数次的字符组成。
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def maxDifference(self, s: str) -> int:

        counts = [0 for _ in range(26)]
        for c in s:
            counts[ord(c) - ord('a')] += 1
        odd = max([c for c in counts if c % 2 == 1 and c > 0])
        even = min([c for c in counts if c % 2 == 0 and c > 0])
        return odd - even


# @lc code=end

#
# @lcpr case=start
# "aaaaabbc"\n
# @lcpr case=end

# @lcpr case=start
# "abcabcab"\n
# @lcpr case=end

#
