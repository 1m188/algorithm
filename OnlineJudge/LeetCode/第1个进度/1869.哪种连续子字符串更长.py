#
# @lc app=leetcode.cn id=1869 lang=python3
#
# [1869] 哪种连续子字符串更长
#
# https://leetcode-cn.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/
#
# algorithms
# Easy (75.72%)
# Likes:    19
# Dislikes: 0
# Total Accepted:    14.6K
# Total Submissions: 19.3K
# Testcase Example:  '"1101"'
#
# 给你一个二进制字符串 s 。如果字符串中由 1 组成的 最长 连续子字符串 严格长于 由 0 组成的 最长 连续子字符串，返回 true ；否则，返回
# false 。
#
#
# 例如，s = "110100010" 中，由 1 组成的最长连续子字符串的长度是 2 ，由 0 组成的最长连续子字符串的长度是 3 。
#
#
# 注意，如果字符串中不存在 0 ，此时认为由 0 组成的最长连续子字符串的长度是 0 。字符串中不存在 1 的情况也适用此规则。
#
#
#
# 示例 1：
#
#
# 输入：s = "1101"
# 输出：true
# 解释：
# 由 1 组成的最长连续子字符串的长度是 2："1101"
# 由 0 组成的最长连续子字符串的长度是 1："1101"
# 由 1 组成的子字符串更长，故返回 true 。
#
#
# 示例 2：
#
#
# 输入：s = "111000"
# 输出：false
# 解释：
# 由 1 组成的最长连续子字符串的长度是 3："111000"
# 由 0 组成的最长连续子字符串的长度是 3："111000"
# 由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
#
#
# 示例 3：
#
#
# 输入：s = "110100010"
# 输出：false
# 解释：
# 由 1 组成的最长连续子字符串的长度是 2："110100010"
# 由 0 组成的最长连续子字符串的长度是 3："110100010"
# 由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 100
# s[i] 不是 '0' 就是 '1'
#
#
#


# @lc code=start
class Solution:

    def checkZeroOnes(self, s: str) -> bool:

        l = 0
        res = True
        ni = 0
        i = 0
        for i in range(1, len(s)):
            if s[i] != s[ni]:
                if s[ni] == '1' and i - ni > l:
                    l = i - ni
                    res = True
                elif s[ni] == '0' and i - ni >= l:
                    l = i - ni
                    res = False
                ni = i
        i += 1
        if s[ni] == '1' and i - ni > l:
            res = True
        elif s[ni] == '0' and i - ni >= l:
            res = False
        return res


# @lc code=end
