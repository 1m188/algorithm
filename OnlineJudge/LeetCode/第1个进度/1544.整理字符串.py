#
# @lc app=leetcode.cn id=1544 lang=python3
#
# [1544] 整理字符串
#
# https://leetcode-cn.com/problems/make-the-string-great/description/
#
# algorithms
# Easy (55.18%)
# Likes:    41
# Dislikes: 0
# Total Accepted:    22.4K
# Total Submissions: 40.7K
# Testcase Example:  '"leEeetcode"'
#
# 给你一个由大小写英文字母组成的字符串 s 。
#
# 一个整理好的字符串中，两个相邻字符 s[i] 和 s[i+1]，其中 0 ，要满足如下条件:
#
#
# 若 s[i] 是小写字符，则 s[i+1] 不可以是相同的大写字符。
# 若 s[i] 是大写字符，则 s[i+1] 不可以是相同的小写字符。
#
#
# 请你将字符串整理好，每次你都可以从字符串中选出满足上述条件的 两个相邻 字符并删除，直到字符串整理好为止。
#
# 请返回整理好的 字符串 。题目保证在给出的约束条件下，测试样例对应的答案是唯一的。
#
# 注意：空字符串也属于整理好的字符串，尽管其中没有任何字符。
#
#
#
# 示例 1：
#
#
# 输入：s = "leEeetcode"
# 输出："leetcode"
# 解释：无论你第一次选的是 i = 1 还是 i = 2，都会使 "leEeetcode" 缩减为 "leetcode" 。
#
#
# 示例 2：
#
#
# 输入：s = "abBAcC"
# 输出：""
# 解释：存在多种不同情况，但所有的情况都会导致相同的结果。例如：
# "abBAcC" --> "aAcC" --> "cC" --> ""
# "abBAcC" --> "abBA" --> "aA" --> ""
#
#
# 示例 3：
#
#
# 输入：s = "s"
# 输出："s"
#
#
#
#
# 提示：
#
#
# 1
# s 只包含小写和大写英文字母
#
#
#


# @lc code=start
class Solution:

    def makeGood(self, s: str) -> str:
        '''

        遍历整个数组，两个两个字符比较

        注意删除两个字符之后新的接触的前后两个字符也有可能符合要求

        '''

        ls = list(s)

        i = 0
        while i < len(ls) - 1:
            if (ls[i].islower() and ls[i + 1] == ls[i].upper()) or (ls[i].isupper() and ls[i + 1] == ls[i].lower()):
                ls.pop(i)
                ls.pop(i)
                if i != 0:
                    i -= 1
            else:
                i += 1

        return ''.join(ls)


# @lc code=end
