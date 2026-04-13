"""
描述
给定仅由小写字母构成的字符串
S
S 和
T
T，判断是否可以从
T
T 中选取若干字符（每个字符最多使用一次），拼接成与
S
S 完全相同的字符串。

请实现函数，接收以下参数：
∙

∙字符串
S
S，长度为
(
1
≦
∣
S
∣
≦
1
0
5
)
(1≦∣S∣≦10
5
 )；
∙

∙字符串
T
T，长度为
(
1
≦
∣
T
∣
≦
1
0
5
)
(1≦∣T∣≦10
5
 )；
函数返回布尔值，表示能否从
T
T 构造出
S
S。
示例1
输入：
"wc","nowcoder"
复制
返回值：
true
复制
备注：
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param ransomNote string字符串
# @param magazine string字符串
# @return bool布尔型
#
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # write code here

        li = [0 for _ in range(26)]
        for c in magazine:
            li[ord(c) - ord("a")] += 1
        for c in ransomNote:
            li[ord(c) - ord("a")] -= 1
            if li[ord(c) - ord("a")] < 0:
                return False
        return True
