"""
描述
藏宝秘窟的大门上有一把密码锁，只有输入正确的密码才能打开。大门旁刻有
n
n 个仅由小写字母组成的字符串。茉茉的研究表明，只要是这
n
n 个字符串的公共非空子串，就能作为密码开启大门。请你帮助茉茉给出任意一个满足条件的密码。我们可以证明，一定存在满足题意的答案。

【名词解释】
∙

∙公共子串：
n
n 个字符串的一个公共子串，是指在这
n
n 个字符串中均出现过的一段连续字符。
输入描述：
在一行上输入一个整数
n
(
1
≦
n
≦
1
0
5
)
n(1≦n≦10
5
 )，代表字符串的数量。
此后
n
n 行，每行输入一个仅由小写字母组成的字符串
s
i
s
i
​
 。保证
∑
i
=
1
n
∣
s
i
∣
≦
1
0
5
i=1
∑
n
​
 ∣s
i
​
 ∣≦10
5
 。
输出描述：
输出一行一个字符串，表示任意一个满足要求的公共子串。
如果存在多个可行答案，你可以输出其中任意一个，系统将自动判定答案正确性。
示例1
输入：
3
ababcdefcg
oaagdabac
dfsabaegezx
复制
输出：
aba
复制
说明：
在该组数据中，字符串集合为
{
"ababcdefcg"
,
"oaagdabac"
,
"dfsabaegezx"
}
{"ababcdefcg","oaagdabac","dfsabaegezx"}。子串
"aba"
"aba" 在三个字符串中均出现，因此可以作为答案。
示例2
输入：
2
abca
cabc
复制
输出：
abc
复制
说明：
在该组数据中，字符串集合为
{
"abca"
,
"cabc"
}
{"abca","cabc"}。子串
"abc"
"abc" 同时出现在两个字符串中，可以作为答案。
备注：
本题已于下方时间节点更新，请注意题解时效性：
1. 2025-12-10 题面补充一定有解。
"""

n = int(input())
li = [0 for _ in range(26)]
for _ in range(n):
    for c in set(input()):
        li[ord(c) - ord("a")] += 1
for i in range(len(li)):
    if li[i] >= n:
        print(chr(i + ord("a")))
        break
