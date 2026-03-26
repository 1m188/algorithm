"""
描述
给定字符串
J
J 和
S
S，计算字符串
S
S 中同时存在于字符串
J
J 的字符数量。
需要注意的是，字符区分大小写，
a
a 与
A
A 视为不同的字符。

函数参数：
∙

∙字符串
J
J，满足
(
1
≦
∣
J
∣
≦
50
)
(1≦∣J∣≦50)，表示不重复的宝石类型；
∙

∙字符串
S
S，满足
(
1
≦
∣
S
∣
≦
50
)
(1≦∣S∣≦50)，表示手中石头序列。

返回值为一个整数，表示字符串
S
S 中同时存在于字符串
J
J 的字符数量。
示例1
输入：
"wangzai","awsl"
复制
返回值：
2
复制
备注：
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param jewels string字符串
# @param stones string字符串
# @return int整型
#
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        # write code here

        return sum(1 if c in jewels else 0 for c in stones)
