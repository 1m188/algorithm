#
# @lc app=leetcode.cn id=3884 lang=python3
# @lcpr version=30204
#
# [3884] 双端字符匹配
#
# https://leetcode.cn/problems/first-matching-character-from-both-ends/description/
#
# algorithms
# Easy (76.19%)
# Likes:    0
# Dislikes: 0
# Total Accepted:    2.8K
# Total Submissions: 3.7K
# Testcase Example:  '"abcacbd"'
#
# 给你一个长度为 n 的字符串 s，其中只包含小写英文字母。
#
# 返回最小的下标 i，使得 s[i] == s[n - i - 1]。
#
# 如果不存在这样的下标，返回 -1。
#
#
#
# 示例 1：
#
#
# 输入： s = "abcacbd"
#
# 输出： 1
#
# 解释：
#
# 在下标 i = 1 处，s[1] 和 s[5] 的值均为 'b'。
#
# 没有更小的下标满足条件，因此答案是 1。
#
#
# 示例 2：
#
#
# 输入： s = "abc"
#
# 输出： 1
#
# 解释：
#
# ​​​​​​​在下标 i = 1 处，左右对应位置重合，因此字符均为 'b'。
#
# 没有更小的下标满足条件，因此答案是 1。
#
#
# 示例 3：
#
#
# 输入： s = "abcdab"
#
# 输出： -1
#
# 解释：
#
# ​​​​​​​对于每个下标 i，位置 i 和 n - i - 1 的字符均不相同。
#
# 因此，不存在有效下标，答案是 -1。
#
#
#
#
# 提示：
#
#
# 1 <= n == s.length <= 100
# s 仅包含小写英文字母。
#
#
#


# @lcpr-template-start
import math


# @lcpr-template-end
# @lc code=start
class Solution:
    def firstMatchingIndex(self, s: str) -> int:

        n = len(s)
        for i in range(math.ceil(n / 2)):
            if s[i] == s[n - i - 1]:
                return i
        return -1


# @lc code=end


#
# @lcpr case=start
# "abcacbd"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n
# @lcpr case=end

# @lcpr case=start
# "abcdab"\n
# @lcpr case=end

#
