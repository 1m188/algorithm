"""
REAL696 小红的元音距离

描述
小红定义一个字符串的权值是：最远的两个元音的距离。例如，"xiaohongshu"的权值为8，因为相距最远的两个元音是第3个字母和第11个字母。特殊的，如果一个字符串的元音数量不超过1个，则认为权值是0。
现在给定一个字符串，小红需要删除一部分字母，使得剩余字符串的权值尽可能大。小红想知道，最多可以删除多少个字母？

注：只有"aeiou"这五个字母是元音字母。
输入描述：
一行仅由小写字母组成的字符串，长度不超过200000。
输出描述：
最多能删除的字母数量。
示例1
输入：
abcdefg
复制
输出：
2
复制
说明：
删除f和g即可。
示例2
输入：
ccpc
复制
输出：
4
复制
说明：
因为字符串的权值最大为0，所以删除所有字母形成空串（空串的权值也是0）。
"""

s = input().strip()
targets = ["a", "e", "i", "o", "u"]

for start in range(len(s)):
    if s[start] in targets:
        break
for end in range(len(s) - 1, -1, -1):
    if s[end] in targets:
        break

print((len(s) - (end - start + 1)) if start < end else len(s))
