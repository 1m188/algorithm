#
# @lc app=leetcode.cn id=3110 lang=python3
# @lcpr version=30204
#
# [3110] 字符串的分数
#
# https://leetcode.cn/problems/score-of-a-string/description/
#
# algorithms
# Easy (91.39%)
# Likes:    12
# Dislikes: 0
# Total Accepted:    19.1K
# Total Submissions: 20.6K
# Testcase Example:  '"hello"'
#
# 给你一个字符串 s 。一个字符串的 分数 定义为相邻字符 ASCII 码差值绝对值的和。
#
# 请你返回 s 的 分数 。
#
#
#
# 示例 1：
#
#
# 输入：s = "hello"
#
# 输出：13
#
# 解释：
#
# s 中字符的 ASCII 码分别为：'h' = 104 ，'e' = 101 ，'l' = 108 ，'o' = 111 。所以 s 的分数为 |104
# - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13 。
#
#
# 示例 2：
#
#
# 输入：s = "zaz"
#
# 输出：50
#
# 解释：
#
# s 中字符的 ASCII 码分别为：'z' = 122 ，'a' = 97 。所以 s 的分数为 |122 - 97| + |97 - 122| = 25
# + 25 = 50 。
#
#
#
#
# 提示：
#
#
# 2 <= s.length <= 100
# s 只包含小写英文字母。
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def scoreOfString(self, s: str) -> int:
        return sum(abs(ord(s[i]) - ord(s[i - 1])) for i in range(1, len(s)))


# @lc code=end

#
# @lcpr case=start
# "hello"\n
# @lcpr case=end

# @lcpr case=start
# "zaz"\n
# @lcpr case=end

#
