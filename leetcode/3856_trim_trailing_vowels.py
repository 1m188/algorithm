#
# @lc app=leetcode.cn id=3856 lang=python3
# @lcpr version=30204
#
# [3856] 移除尾部元音字母
#
# https://leetcode.cn/problems/trim-trailing-vowels/description/
#
# algorithms
# Easy (79.37%)
# Likes:    1
# Dislikes: 0
# Total Accepted:    2.9K
# Total Submissions: 3.6K
# Testcase Example:  '"idea"'
#
# 给定一个由小写英文字母组成的字符串 s。
#
# 返回移除字符串 s 尾部 所有元音字母 后得到的字符串。
#
# 元音字母包括字符 'a'、'e'、'i'、'o' 和 'u'。
#
#
#
# 示例 1：
#
#
# 输入： s = "idea"
#
# 输出： "id"
#
# 解释：
#
# 移除 "idea" 后，得到字符串 "id"。
#
#
# 示例 2：
#
#
# 输入： s = "day"
#
# 输出： "day"
#
# 解释：
#
# 字符串 "day" 尾部没有元音字母。
#
#
# 示例 3：
#
#
# 输入： s = "aeiou"
#
# 输出： ""
#
# 解释：
#
# 移除 "aeiou" 后，得到字符串 ""。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 100
# s 仅由小写英文字母组成。
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def trimTrailingVowels(self, s: str) -> str:

        return s.rstrip("aeiou")


# @lc code=end


#
# @lcpr case=start
# "idea"\n
# @lcpr case=end

# @lcpr case=start
# "day"\n
# @lcpr case=end

# @lcpr case=start
# "aeiou"\n
# @lcpr case=end

#
