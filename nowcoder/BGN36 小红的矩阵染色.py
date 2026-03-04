"""
描述
给定一个
n
×
m
n×m 的矩阵，初始时部分格子已被染成黑色（用 ``
*
*`` 表示），其余格子为空白（用 ``
o
o`` 表示）。

小红最多可以任选至多
k
k 个空白格子，将其染成红色。计分规则如下：
∙

∙ 若某个红色格子的正下方（同一列下一行）也是红色，则该格子贡献
1
1 分；
∙

∙ 其他情况不计分。

请你帮小红计算，经过最优染色后，最多能获得多少分数。
输入描述：
第一行输入三个整数
n
,
m
,
k
(
1
≦
n
,
m
≦
1
0
3
;

1
≦
k
≦
n
×
m
)
n,m,k(1≦n,m≦10
3
 ; 1≦k≦n×m)，分别表示矩阵行数、列数及最多可染红的格子数量。
此后
n
n 行，每行输入一个长度为
m
m 的字符串
s
i
s
i
​
 ，描述第
i
i 行初始状态：
∙

∙ ``
*
*`` 代表黑色格子，不能重新染色；
∙

∙ ``
o
o`` 代表空白格子，可选择染为红色。
输出描述：
输出一个整数，表示小红通过最佳策略能够获得的最大分数。
示例1
输入：
4 4 3
*o*o
oooo
****
oooo
复制
输出：
1
复制
说明：
一种可行方案如下（``
r
r`` 为染成红色后的格子）：

*r*o
oroo
****
oooo

红色格子共有
2
2 个，其中正下方同列的红色对数为
1
1，因此得分
1
1。
示例2
输入：
3 3 3
*o*
*o*
*o*
复制
输出：
2

"""

n, m, k = map(int, input().split())
mat = []
for _ in range(n):
    mat.append(list(input()))

lo = []
for col in range(m):
    row = 0
    while row < n:
        if mat[row][col] == "o":
            cnt = 1
            row2 = row + 1
            while row2 < n and mat[row2][col] == "o":
                cnt += 1
                row2 += 1
            lo.append(cnt)
            row = row2
        row += 1
lo.sort(reverse=True)

ans = 0
for i in lo:
    if k > i:
        k -= i
        ans += i - 1
    else:
        ans += k - 1
        break
print(ans)
