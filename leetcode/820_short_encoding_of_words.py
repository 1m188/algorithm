#
# @lc app=leetcode.cn id=820 lang=python3
# @lcpr version=30204
#
# [820] 单词的压缩编码
#
# https://leetcode.cn/problems/short-encoding-of-words/description/
#
# algorithms
# Medium (52.87%)
# Likes:    344
# Dislikes: 0
# Total Accepted:    77.9K
# Total Submissions: 147.4K
# Testcase Example:  '["time","me","bell"]'
#
# 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
#
#
# words.length == indices.length
# 助记字符串 s 以 '#' 字符结尾
# 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与
# words[i] 相等
#
#
# 给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
#
#
#
# 示例 1：
#
# 输入：words = ["time", "me", "bell"]
# 输出：10
# 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
# words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
# words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
# words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示
# "time#bell#"
#
#
# 示例 2：
#
# 输入：words = ["t"]
# 输出：2
# 解释：一组有效编码为 s = "t#" 和 indices = [0] 。
#
#
#
#
# 提示：
#
#
# 1 <= words.length <= 2000
# 1 <= words[i].length <= 7
# words[i] 仅由小写字母组成
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        """
        Set 去重 + 移除后缀

        核心思路：
        - 若单词 A 是单词 B 的后缀，则编码 B 时 A 已被包含（共享同一个 # 结尾）
        - 因此只需保留那些不是任何其他单词后缀的单词
        - 结果 = 所有保留单词的 (长度 + 1) 之和（每个单词后跟一个 #）
        """
        word_set = set(words)

        for w in words:
            # 枚举 w 的所有后缀（不包含 w 自身），从集合中移除
            for i in range(1, len(w)):
                suffix = w[i:]
                word_set.discard(suffix)

        return sum(len(w) + 1 for w in word_set)


# @lc code=end


#
# @lcpr case=start
# ["time", "me", "bell"]\n
# @lcpr case=end

# @lcpr case=start
# ["t"]\n
# @lcpr case=end

#
