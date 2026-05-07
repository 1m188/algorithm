"""
描述
小鱼儿会吐出两种泡泡：大泡泡
"O"
"O"，小泡泡
"o"
"o"；两种泡泡的变化规则如下：
∙

∙任意两个相邻的小泡泡会融合成一个大泡泡；
∙

∙任意两个相邻的大泡泡会相互爆炸，变成空白（即消失）。
上述合并与爆炸过程自左至右依次进行，直至无法再进行任何操作。

例如，对于初始泡泡序列
"ooOOoooO"
"ooOOoooO"，经过一段时间后会变成
"oO"
"oO"。


输入描述：
第一行输入一个整数
T
(
1
≦
T
≦
10
)
T(1≦T≦10) 代表数据组数。
接下来
T
T 行，每行一个仅由 'O' 和 'o' 构成的字符串
s
s，字符串长度不超过
1
0
5
10
5
 。
输出描述：
每组输出仅包含一行，输出一行字符串代表小鱼儿吐出的泡泡经过融合以后所剩余的泡泡。
示例1
输入：
1
ooOOoooO
复制
输出：
oO
复制
说明：

示例2
输入：
1
OOOOOOOOOOOOOOOooooooooooooooooooOOoOoOoOOOoOoOoOOoOooOoOOoOoOoOoOoOoOoOoOoOooOoOoOOoooOOOOoOOoooOOoOOOOOooOoOOOoOOoooOoOOOooOooooOoOooOoOooOoOooOoOOOOOOOOOOOOOOoOoOoOooOOoOooOoOOoOoOOOOooooOOOOOooooooOOOOOOoooooOoOooOoOoOoooOoOOOOoOoOoOOOOOOOOOOoOooOoOooOOoOOoOooOooOOoooOOOoOoOooOOooOoOOOoOOoOOOoOooOoOOOooOOoooOOoOOoOooOOOOoOooOoOoOoOooOoOoO
复制
输出：
oOoOoOoOoOoO
复制
说明：

备注：
"""

T = int(input())
for _ in range(T):
    s = input()

    stack = []
    for c in s:
        while stack and stack[-1] == c:
            stack.pop()
            if c == "o":
                c = "O"
            elif c == "O":
                c = None
        if c:
            stack.append(c)
    print("".join(stack))
