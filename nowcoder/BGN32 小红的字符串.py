"""
描述
小红拥有一个长度为
n
n 的小写字母字符串
s
s。她可以重复执行如下操作任意次：
∙

∙ 选择一个下标
i

(
1
≦
i
≦
n
)
i (1≦i≦n)，将字符
s
i
s
i
​
  循环右移到字母表中的下一个字母。特别地，``
z
z`` 右移后变成 ``
a
a``。

请计算，使
s
s 变为回文串所需的最少操作次数。

【名词解释】回文串：一个字符串从左往右与从右往左读完全相同。
输入描述：
一行输入一个长度不超过
1000
1000 的小写字母字符串
s
s。
输出描述：










在一行上输出一个整数，代表把
s
s 变成回文串的最少操作次数。
示例1
输入：
abcd
复制
输出：
4
复制
说明：
一种可行方案：
"abcd"
→
"dccd"
"abcd"→"dccd"（共
4
4 次操作）。
示例2
输入：
nuhhhh
复制
输出：
19
"""

s = input()
ans = 0
left, right = 0, len(s) - 1
while left < right:
    if s[left] != s[right]:
        x1, x2 = ord(s[left]) - ord("a"), ord(s[right]) - ord("a")
        if x1 < x2:
            ans += min(x2 - x1, 26 - x2 + x1)
        else:
            ans += min(x1 - x2, 26 - x1 + x2)
    left += 1
    right -= 1
print(ans)
