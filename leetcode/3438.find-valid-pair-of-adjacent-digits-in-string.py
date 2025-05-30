#
# @lc app=leetcode.cn id=3438 lang=python3
# @lcpr version=30204
#
# [3438] 找到字符串中合法的相邻数字
#
# https://leetcode.cn/problems/find-valid-pair-of-adjacent-digits-in-string/description/
#
# algorithms
# Easy (75.45%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    1.9K
# Total Submissions: 2.5K
# Testcase Example:  '"2523533"'
#
# 给你一个只包含数字的字符串 s 。如果 s 中两个 相邻 的数字满足以下条件，我们称它们是 合法的 ：
#
#
# 前面的数字 不等于 第二个数字。
# 两个数字在 s 中出现的次数 恰好 分别等于这个数字本身。
#
#
# 请你从左到右遍历字符串 s ，并返回最先找到的 合法 相邻数字。如果这样的相邻数字不存在，请你返回一个空字符串。
#
#
#
# 示例 1：
#
#
# 输入：s = "2523533"
#
# 输出："23"
#
# 解释：
#
# 数字 '2' 出现 2 次，数字 '3' 出现 3 次。"23" 中每个数字在 s 中出现的次数都恰好分别等于数字本身。所以输出 "23" 。
#
#
# 示例 2：
#
#
# 输入：s = "221"
#
# 输出："21"
#
# 解释：
#
# 数字 '2' 出现 2 次，数字 '1' 出现 1 次。所以输出 "21" 。
#
#
# 示例 3：
#
#
# 输入：s = "22"
#
# 输出：""
#
# 解释：
#
# 没有合法的相邻数字。
#
#
#
#
# 提示：
#
#
# 2 <= s.length <= 100
# s 只包含 '1' 到 '9' 的数字。
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def findValidPair(self, s: str) -> str:
        di = {str(i): 0 for i in range(0, 10)}
        for i in s:
            di[i] += 1
        for i in range(1, len(s)):
            if s[i] != s[i - 1] and di[s[i]] == int(s[i]) and di[s[i - 1]] == int(s[i - 1]):
                return s[i - 1] + s[i]
        return ""


# @lc code=end

#
# @lcpr case=start
# "2523533"\n
# @lcpr case=end

# @lcpr case=start
# "221"\n
# @lcpr case=end

# @lcpr case=start
# "22"\n
# @lcpr case=end

#
