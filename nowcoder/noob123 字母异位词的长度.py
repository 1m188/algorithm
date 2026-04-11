"""
描述
现有两个仅由小写英文字母构成的字符串
s
,
x
s,x，请判断它们是否为字母异位词，如果是的话，输出字母异位词的长度，不是的话，返回-1
注：如果每个字符出现的次数都相同，则称他们为字母异位词。

数据范围:
1
≤
s
.
l
e
n
g
t
h
,
x
.
l
e
n
g
t
h
≤
5
∗
1
0
4
1≤s.length,x.length≤5∗10
4

示例1
输入：
"aba","aa"
复制
返回值：
-1
复制
说明：
第一个字符串与第二个字符串a出现的次数相同，而b出现的次数不同，不符合每个字符出现的次数都相同。故输出-1
示例2
输入：
"a","a"
复制
返回值：
1
复制
说明：
第一个字符串与第二个字符串每个字符出现的次数都相同，故输出相同的长度为1
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @param c string字符串
# @return int整型
#
class Solution:
    def isCongruent(self, s: str, c: str) -> int:
        # write code here

        if len(s) != len(c):
            return -1

        n = len(s)
        li = [0 for _ in range(26)]
        for i in range(n):
            li[ord(s[i]) - ord("a")] += 1
            li[ord(c[i]) - ord("a")] -= 1
        return n if not any(li) else -1
