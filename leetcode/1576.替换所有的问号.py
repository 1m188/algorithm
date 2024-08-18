#
# @lc app=leetcode.cn id=1576 lang=python3
#
# [1576] 替换所有的问号
#
# https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/
#
# algorithms
# Easy (51.53%)
# Likes:    104
# Dislikes: 0
# Total Accepted:    48.5K
# Total Submissions: 94.1K
# Testcase Example:  '"?zs"'
#
# 给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。
#
# 注意：你 不能 修改非 '?' 字符。
#
# 题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。
#
# 在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。
#
#
#
# 示例 1：
#
#
# 输入：s = "?zs"
# 输出："azs"
# 解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs"
# 中有连续重复的两个 'z' 。
#
# 示例 2：
#
#
# 输入：s = "ubv?w"
# 输出："ubvaw"
# 解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww"
# 都包含连续重复的字符。
#
#
#
#
# 提示：
#
#
#
# 1 <= s.length <= 100
#
#
# s 仅包含小写英文字母和 '?' 字符
#
#
#
#


# @lc code=start
class Solution:

    def modifyString(self, s: str) -> str:

        sl = list(s)

        for i in range(len(sl)):
            if sl[i] == '?':
                a1 = sl[i - 1] if i - 1 >= 0 and sl[i - 1].isalpha() else ''
                a2 = sl[i + 1] if i + 1 < len(sl) and sl[i + 1].isalpha() else ''
                for j in range(26):
                    a = chr(ord('a') + j)
                    if a != a1 and a != a2:
                        sl[i] = a
                        break

        return ''.join(sl)


# @lc code=end
