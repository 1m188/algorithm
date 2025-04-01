#
# @lc app=leetcode.cn id=3498 lang=python3
# @lcpr version=30204
#
# [3498] 字符串的反转度
#
# https://leetcode.cn/problems/reverse-degree-of-a-string/description/
#
# algorithms
# Easy (85.84%)
# Likes:    1
# Dislikes: 0
# Total Accepted:    1.9K
# Total Submissions: 2.2K
# Testcase Example:  '"abc"'
#
# 给你一个字符串 s，计算其 反转度。
#
# 反转度的计算方法如下：
#
#
# 对于每个字符，将其在 反转 字母表中的位置（'a' = 26, 'b' = 25, ..., 'z' = 1）与其在字符串中的位置（下标从1
# 开始）相乘。
# 将这些乘积加起来，得到字符串中所有字符的和。
#
#
# 返回 反转度。
#
#
#
# 示例 1：
#
#
# 输入： s = "abc"
#
# 输出： 148
#
# 解释：
#
#
#
#
# 字母
# 反转字母表中的位置
# 字符串中的位置
# 乘积
#
#
# 'a'
# 26
# 1
# 26
#
#
# 'b'
# 25
# 2
# 50
#
#
# 'c'
# 24
# 3
# 72
#
#
#
#
# 反转度是 26 + 50 + 72 = 148 。
#
#
# 示例 2：
#
#
# 输入： s = "zaza"
#
# 输出： 160
#
# 解释：
#
#
#
#
# 字母
# 反转字母表中的位置
# 字符串中的位置
# 乘积
#
#
# 'z'
# 1
# 1
# 1
#
#
# 'a'
# 26
# 2
# 52
#
#
# 'z'
# 1
# 3
# 3
#
#
# 'a'
# 26
# 4
# 104
#
#
#
#
#
# 反转度是 1 + 52 + 3 + 104 = 160 。
#
#
#
# 提示：
#
#
# 1 <= s.length <= 1000
# s 仅包含小写字母。
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def reverseDegree(self, s: str) -> int:
        return sum((26 - ord(c) + ord('a')) * (i + 1) for i, c in enumerate(s))


# @lc code=end

#
# @lcpr case=start
# "abc"\n
# @lcpr case=end

# @lcpr case=start
# "zaza"\n
# @lcpr case=end

#
