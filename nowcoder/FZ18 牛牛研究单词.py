'''

描述
牛牛是一头聪明的牛，他喜欢研究单词。现在，给定一个由小写字母组成的字符串数组 words 和一个字符串 prefix，请你实现一个函数 countWordsWithPrefix，来帮助牛牛统计在 words 中以 prefix 为前缀的单词数量。
示例1
输入：
["apple", "banana", "application", "apply", "book", "cat"],"app"
复制
返回值：
3
复制
示例2
输入：
["apple", "banana", "application", "apply", "book", "cat"],"ba"
复制
返回值：
1
复制
示例3
输入：
["apple", "banana", "application", "apply", "book", "cat"],"xyz"
复制
返回值：
0
复制
备注：
字符串数组 words 中的单词数量不超过 10^4。
每个单词的长度不超过 100。
字符串 prefix 的长度不超过 100。

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param words string字符串一维数组
# @param prefix string字符串
# @return int整型
#
class Solution:

    def countWordsWithPrefix(self, words: List[str], prefix: str) -> int:
        # write code here

        if len(words) == 0: return 0

        res = 0
        pn = len(prefix)
        for word in words:
            if len(word) < pn: continue
            f = True
            for i in range(pn):
                if word[i] != prefix[i]:
                    f = False
                    break
            if f: res += 1

        return res
