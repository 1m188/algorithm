"""
描述
牛牛喜欢跟字符串玩耍，他学会了一种新操作：在当前字符串中任意位置（包括开头和结尾）插入子串
ab
ab。

牛牛称一个字符串为 好串，当且仅当它可以通过若干次上述操作从 空串 生成。

例如，
ab
ab、
aabb
aabb、
aababb
aababb 都是好串，而
aab
aab、
ba
ba、
abbb
abbb 不是好串。

现给定一个字符串
s
s，请判断字符串
s
s 是否是好串。
输入描述：
在一行中输入一个仅由小写字母组成字符串
s
s（
1
≦
∣
s
∣
≦
1
0
5
1≦∣s∣≦10
5
 ）。
输出描述：
如果字符串
s
s 是好串，输出
Good
Good；否则输出
Bad
Bad。
示例1
输入：
ab
复制
输出：
Good
复制
说明：
初始空串，插入一次 "ab" 即可得到 "ab"。
示例2
输入：
aab
复制
输出：
Bad
复制
说明：
无法通过插入 "ab" 操作得到 "aab"。
示例3
输入：
abaababababbaabbaaaabaababaabbabaaabbbbbbbb
复制
输出：
Bad
复制
备注：
"""

s = input()
x = 0
for c in s:
    x += 1 if c == "a" else -1
    if x < 0:
        break
print("Good" if x == 0 else "Bad")
