#
# @lc app=leetcode.cn id=1662 lang=python3
#
# [1662] 检查两个字符串数组是否相等
#
# https://leetcode-cn.com/problems/check-if-two-string-arrays-are-equivalent/description/
#
# algorithms
# Easy (81.10%)
# Likes:    21
# Dislikes: 0
# Total Accepted:    23.8K
# Total Submissions: 29.3K
# Testcase Example:  '["ab", "c"]\n["a", "bc"]'
#
# 给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
#
# 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
#
#
#
# 示例 1：
#
#
# 输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
# 输出：true
# 解释：
# word1 表示的字符串为 "ab" + "c" -> "abc"
# word2 表示的字符串为 "a" + "bc" -> "abc"
# 两个字符串相同，返回 true
#
# 示例 2：
#
#
# 输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
# 输出：false
#
#
# 示例 3：
#
#
# 输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
# 输出：true
#
#
#
#
# 提示：
#
#
# 1
# 1
# 1
# word1[i] 和 word2[i] 由小写字母组成
#
#
#

from typing import List


# @lc code=start
class Solution:

    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:

        # 简单做法（也许会有大开销？）
        # return ''.join(word1) == ''.join(word2)

        # 从头到尾挨个遍历比对，不需要连接字符串
        i1, i2 = 0, 0
        j1, j2 = 0, 0
        while i1 < len(word1) and i2 < len(word2):
            if word1[i1][j1] == word2[i2][j2]:
                j1 += 1
                if j1 >= len(word1[i1]):
                    i1 += 1
                    j1 = 0
                j2 += 1
                if j2 >= len(word2[i2]):
                    i2 += 1
                    j2 = 0
            else:
                return False
        if i1 != len(word1) or i2 != len(word2):
            return False
        return True


# @lc code=end
