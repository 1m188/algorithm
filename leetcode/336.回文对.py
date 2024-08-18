#
# @lc app=leetcode.cn id=336 lang=python3
#
# [336] 回文对
#
# https://leetcode-cn.com/problems/palindrome-pairs/description/
#
# algorithms
# Hard (39.45%)
# Likes:    305
# Dislikes: 0
# Total Accepted:    24.1K
# Total Submissions: 61.2K
# Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
#
# 给定一组 互不相同 的单词， 找出所有 不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j]
# ，可拼接成回文串。
#
#
#
# 示例 1：
#
#
# 输入：words = ["abcd","dcba","lls","s","sssll"]
# 输出：[[0,1],[1,0],[3,2],[2,4]]
# 解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
#
#
# 示例 2：
#
#
# 输入：words = ["bat","tab","cat"]
# 输出：[[0,1],[1,0]]
# 解释：可拼接成的回文串为 ["battab","tabbat"]
#
# 示例 3：
#
#
# 输入：words = ["a",""]
# 输出：[[0,1],[1,0]]
#
#
#
# 提示：
#
#
# 1 <= words.length <= 5000
# 0 <= words[i].length <= 300
# words[i] 由小写英文字母组成
#
#
#

from typing import List


# @lc code=start
class Solution:

    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        '''
        对于两个字符串s1和s2 如果s1+s2为回文串 考虑s1和s2中的某个字符串s

        将s分为两个部分t1和t2 如果t1为回文串 那么要考察t2的翻转是否在字符串数组中  
        如果存在  意味着rev(t2)+t1+t2即rev(t2)+s为回文串  相应的  如果t2为回文串  
        那么相反的  t1+t2+rev(t2)即s+rev(t2)为回文串  这里的两种情况对应了不同的
        索引排列顺序

        提前用一个哈希表存储所有字符串的翻转及其索引  在寻找翻转是否存在的时候可以节省时间

        这里的思路最开始是用双循环暴力判断法  超时  很自然想到能不能用某种方法在第二次寻找中
        加快速度

        如果能在第二次查找中直接找到需要找的某个能够直接判断回文的字符串就好了
        '''

        di = {}  # 提前存储每个字符串的翻转，待查找
        for i in range(len(words)):
            di[words[i][::-1]] = i  # 注意使用字符串切片的方法，如果用函数做列表翻转会超时

        ans = set()  # 去除重复的索引对

        for i in range(len(words)):

            t1 = ''
            t2 = words[i]

            # 这里将每个字符串分割成两个部分，然后讨论两种情况
            while t2:
                if t1 == t1[::-1] and t2 in di and di[t2] != i:
                    ans.add((di[t2], i))
                if t2 == t2[::-1] and t1 in di and di[t1] != i:
                    ans.add((i, di[t1]))
                t1 += t2[0]
                t2 = t2[1:]
            if t1 == t1[::-1] and t2 in di and di[t2] != i:
                ans.add((di[t2], i))
            if t2 == t2[::-1] and t1 in di and di[t1] != i:
                ans.add((i, di[t1]))

        return list(ans)


# @lc code=end
