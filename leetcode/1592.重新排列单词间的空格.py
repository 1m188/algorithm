#
# @lc app=leetcode.cn id=1592 lang=python3
#
# [1592] 重新排列单词间的空格
#
# https://leetcode-cn.com/problems/rearrange-spaces-between-words/description/
#
# algorithms
# Easy (44.33%)
# Likes:    18
# Dislikes: 0
# Total Accepted:    8.9K
# Total Submissions: 20.1K
# Testcase Example:  '"  this   is  a sentence "'
#
# 给你一个字符串 text ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证
# text 至少包含一个单词 。
#
# 请你重新排列空格，使每对相邻单词之间的空格数目都 相等 ，并尽可能 最大化 该数目。如果不能重新平均分配所有空格，请 将多余的空格放置在字符串末尾
# ，这也意味着返回的字符串应当与原 text 字符串的长度相等。
#
# 返回 重新排列空格后的字符串 。
#
#
#
# 示例 1：
#
# 输入：text = "  this   is  a sentence "
# 输出："this   is   a   sentence"
# 解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
#
#
# 示例 2：
#
# 输入：text = " practice   makes   perfect"
# 输出："practice   makes   perfect "
# 解释：总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
#
#
# 示例 3：
#
# 输入：text = "hello   world"
# 输出："hello   world"
#
#
# 示例 4：
#
# 输入：text = "  walks  udp package   into  bar a"
# 输出："walks  udp  package  into  bar  a "
#
#
# 示例 5：
#
# 输入：text = "a"
# 输出："a"
#
#
#
#
# 提示：
#
#
# 1 <= text.length <= 100
# text 由小写英文字母和 ' ' 组成
# text 中至少包含一个单词
#
#
#


# @lc code=start
class Solution:

    def reorderSpaces(self, text: str) -> str:
        '''

        记录所有空格数目和单词，把所有空格平均分配到单词之间，多余的部分加到后面
        注意编程时候各个变量的所指以及各项所需数据

        '''

        spn = text.count(' ')
        words = [i for i in text.split(' ') if i]
        n = len(words)
        if n == 1:
            for _ in range(spn):
                words[0] += ' '
            return words[0]

        itn = int(spn / (n - 1))

        sp = []
        for _ in range(itn):
            sp.append(' ')
        sp = ''.join(sp)

        words = sp.join(words)

        sp = []
        for _ in range(spn - (n - 1) * itn):
            sp.append(' ')
        sp = ''.join(sp)

        return words + sp


# @lc code=end
