#
# @lc app=leetcode.cn id=1768 lang=python3
#
# [1768] 交替合并字符串
#
# https://leetcode-cn.com/problems/merge-strings-alternately/description/
#
# algorithms
# Easy (75.86%)
# Likes:    22
# Dislikes: 0
# Total Accepted:    16.5K
# Total Submissions: 21.8K
# Testcase Example:  '"abc"\n"pqr"'
#
# 给你两个字符串 word1 和 word2 。请你从 word1
# 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
#
# 返回 合并后的字符串 。
#
#
#
# 示例 1：
#
#
# 输入：word1 = "abc", word2 = "pqr"
# 输出："apbqcr"
# 解释：字符串合并情况如下所示：
# word1：  a   b   c
# word2：    p   q   r
# 合并后：  a p b q c r
#
#
# 示例 2：
#
#
# 输入：word1 = "ab", word2 = "pqrs"
# 输出："apbqrs"
# 解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
# word1：  a   b
# word2：    p   q   r   s
# 合并后：  a p b q   r   s
#
#
# 示例 3：
#
#
# 输入：word1 = "abcd", word2 = "pq"
# 输出："apbqcd"
# 解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
# word1：  a   b   c   d
# word2：    p   q
# 合并后：  a p b q c   d
#
#
#
#
# 提示：
#
#
# 1 <= word1.length, word2.length <= 100
# word1 和 word2 由小写英文字母组成
#
#
#


# @lc code=start
class Solution:

    def mergeAlternately(self, word1: str, word2: str) -> str:

        word1 = list(word1)
        word2 = list(word2)

        res = []
        while word1 and word2:
            res.append(word1.pop(0))
            res.append(word2.pop(0))
        if word1:
            res.extend(word1)
        if word2:
            res.extend(word2)

        return ''.join(res)


# @lc code=end
