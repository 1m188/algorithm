"""
描述
给定一个由
n
n 行
m
m 列整数组成的矩阵
{
a
i
,
j
}
{a
i,j
​
 }（下标均从
1
1 开始）。
现有
q
q 次独立查询，第
k
k 次查询给定四个整数
x
1
,
y
1
,
x
2
,
y
2
x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 ，表示左上角坐标
(
x
1
,
y
1
)
(x
1
​
 ,y
1
​
 ) 与右下角坐标
(
x
2
,
y
2
)
(x
2
​
 ,y
2
​
 ) 满足
1
≦
x
1
≦
x
2
≦
n
1≦x
1
​
 ≦x
2
​
 ≦n 且
1
≦
y
1
≦
y
2
≦
m
1≦y
1
​
 ≦y
2
​
 ≦m。
请你计算该子矩阵中全部元素之和，记为

S
(
x
1
,
y
1
,
x
2
,
y
2
)
=
∑
i
=
x
1
x
2

∑
j
=
y
1
y
2
a
i
,
j
S(x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 )=
i=x
1
​

∑
x
2
​

​

j=y
1
​

∑
y
2
​

​
 a
i,j
​
 。

你需要依次回答所有查询。
输入描述：
在一行上输入三个整数
n
,
m
,
q
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
q
≦
1
0
5
)
n,m,q(1≦n,m≦10
3
 ; 1≦q≦10
5
 )，依次表示矩阵的行数、列数与查询次数。
此后
n
n 行，每行输入
m
m 个整数
a
i
,
1
,
a
i
,
2
,
…
,
a
i
,
m
(
−
1
0
9
≦
a
i
,
j
≦
1
0
9
)
a
i,1
​
 ,a
i,2
​
 ,…,a
i,m
​
 (−10
9
 ≦a
i,j
​
 ≦10
9
 )，表示矩阵第
i
i 行的元素；共计
n
×
m
n×m 个整数。
此后
q
q 行，每行输入四个整数
x
1
,
y
1
,
x
2
,
y
2
x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 ，所有变量均满足

1
≦
x
1
≦
x
2
≦
n
,
1
≦
y
1
≦
y
2
≦
m
1≦x
1
​
 ≦x
2
​
 ≦n,1≦y
1
​
 ≦y
2
​
 ≦m。

输出描述：
对于每一次查询，在一行上输出一个整数，表示对应子矩阵元素之和。
示例1
输入：
3 4 3
1 2 3 4
3 2 1 0
1 5 7 8
1 1 2 2
1 1 3 3
1 2 3 4
复制
输出：
8
25
32
复制
说明：
以第一组样例中的第二次查询
(
x
1
,
y
1
,
x
2
,
y
2
)
=
(
1
,
1
,
3
,
3
)
(x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 )=(1,1,3,3) 为例：
∙

∙查询的子矩阵包含矩阵的左上
3
×
3
3×3 区域；
∙

∙其内部所有元素之和为
1
+
2
+
3
+
3
+
2
+
1
+
1
+
5
+
7
=
25
1+2+3+3+2+1+1+5+7=25；
因此输出
25
25。
备注：
读入数据可能很大，请注意读写时间。
"""

import sys

inputs = sys.stdin.read().strip().split("\n")
n, m, q = map(int, inputs[0].split())

mat = []
for i in range(1, n + 1):
    mat.append(list(map(int, inputs[i].split())))
prefix = [[0 for _ in range(m)] for _ in range(n)]
prefix[0][0] = mat[0][0]
for i in range(1, m):
    prefix[0][i] = prefix[0][i - 1] + mat[0][i]
for i in range(1, n):
    prefix[i][0] = prefix[i - 1][0] + mat[i][0]
for i in range(1, n):
    for j in range(1, m):
        prefix[i][j] = (
            prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i][j]
        )

ans = []
for i in range(n + 1, n + 1 + q):
    x1, y1, x2, y2 = map(int, inputs[i].split())
    x1, y1, x2, y2 = x1 - 1, y1 - 1, x2 - 1, y2 - 1
    s = prefix[x2][y2]
    if y1 - 1 >= 0:
        s -= prefix[x2][y1 - 1]
    if x1 - 1 >= 0:
        s -= prefix[x1 - 1][y2]
    if x1 - 1 >= 0 and y1 - 1 >= 0:
        s += prefix[x1 - 1][y1 - 1]
    ans.append(s)

print("\n".join(map(str, ans)))
