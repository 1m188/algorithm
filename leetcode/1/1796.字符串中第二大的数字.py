#
# @lc app=leetcode.cn id=1796 lang=python3
#
# [1796] 字符串中第二大的数字
#
# https://leetcode-cn.com/problems/second-largest-digit-in-a-string/description/
#
# algorithms
# Easy (48.99%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    9.1K
# Total Submissions: 18.7K
# Testcase Example:  '"dfa12321afd"'
#
# 给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。
#
# 混合字符串 由小写英文字母和数字组成。
#
#
#
# 示例 1：
#
#
# 输入：s = "dfa12321afd"
# 输出：2
# 解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
#
#
# 示例 2：
#
#
# 输入：s = "abc1111"
# 输出：-1
# 解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 500
# s 只包含小写英文字母和（或）数字。
#
#
#


# @lc code=start
class Solution:

    def secondHighest(self, s: str) -> int:

        first, second = -1, -1

        for c in s:
            if c.isdigit():
                k = int(c)
                if first == -1 or second == -1:
                    if first == -1:
                        first = k
                    elif second == -1:
                        if k > first:
                            first, second = k, first
                        elif k < first:
                            second = k
                else:
                    if k > first:
                        first, second = k, first
                    elif first > k > second:
                        second = k

        return second


# @lc code=end
