'''

描述
对于一个长度为 n 字符串，我们需要对它做一些变形。

首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把这个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。

比如"Hello World"变形后就变成了"wORLD hELLO"。

数据范围: 
1
≤
�
≤
1
0
6
1≤n≤10 
6
  , 字符串中包括大写英文字母、小写英文字母、空格。
进阶：空间复杂度 
�
(
�
)
O(n) ， 时间复杂度 
�
(
�
)
O(n)
输入描述：
给定一个字符串s以及它的长度n(1 ≤ n ≤ 10^6)
返回值描述：
请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
示例1
输入：
"This is a sample",16
复制
返回值：
"SAMPLE A IS tHIS"
复制
示例2
输入：
"nowcoder",8
复制
返回值：
"NOWCODER"
复制
示例3
输入：
"iOS",3
复制
返回值：
"Ios"

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @param n int整型
# @return string字符串
#
class Solution:

    def trans(self, s: str, n: int) -> str:
        # write code here

        li = s.split(' ')
        li.reverse()
        for i, word in enumerate(li):
            s = ''
            for c in word:
                if c.isupper(): s += c.lower()
                else: s += c.upper()
            li[i] = s
        return ' '.join(li)
