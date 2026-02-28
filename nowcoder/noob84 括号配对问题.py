"""
描述
给定一个字符串
S
S，请检查字符串中仅由括号字符
‘[’
‘[’、
‘]’
‘]’、
‘(’
‘(’、
‘)’
‘)’ 组成的子序列是否构成合法括号序列。合法括号序列的定义如下：

∙

∙空序列是合法括号序列；

∙

∙如果
A
A 是合法括号序列，则 `(A)` 和 `[A]` 都是合法括号序列；

∙

∙如果
A
A 和
B
B 都是合法括号序列，则它们的拼接
A
B
AB 也是合法括号序列。

字符串
S
S 可能包含其他字符，但只需考虑括号部分，忽略其他字符。
输入描述：
在一行中输入一个字符串
S
S，长度
1
≦
∣
S
∣
≦
1
0
4
1≦∣S∣≦10
4
 ，由可见字符组成。
输出描述：
如果字符串
S
S 中的括号部分能构成合法括号序列，则输出
true
true；否则输出
false
false。
示例1
输入：
abcd(])[efg
复制
输出：
false
复制
说明：
提取括号 `(`、`)`、`[`、`]` 后为 `(])[`，不是合法括号序列。
示例2
输入：
a[x(y)z]
复制
输出：
true
复制
说明：
提取括号后为 `[()]`，是合法括号序列。
"""

s = input().strip()
cnt1, cnt2 = 0, 0
stack = []
f = True
for c in s:
    if c == "(":
        stack.append(c)
        cnt1 += 1
    elif c == "[":
        stack.append(c)
        cnt2 += 1
    elif c == ")":
        if cnt1 > 0 and stack[-1] == "(":
            stack.pop()
            cnt1 -= 1
        else:
            f = False
            break
    elif c == "]":
        if cnt2 > 0 and stack[-1] == "[":
            stack.pop()
            cnt2 -= 1
        else:
            f = False
            break


print("true" if f and cnt1 == 0 and cnt2 == 0 else "false")
