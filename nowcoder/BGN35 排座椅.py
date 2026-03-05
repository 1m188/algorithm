"""
描述
教室内共有
n
n 行
m
m 列座位，坐在第
i
i 行第
j
j 列同学的位置记为
(
i
,
j
)
(i,j)。

为了方便进出，班主任计划设置
k
k 条横向通道（贯穿整列的水平通道）与
l
l 条纵向通道（贯穿整行的竖直通道）。通道位于相邻两行（或两列）之间。

班主任记录了
d
d 对经常交头接耳的同学，他们的位置
(
x
i
,
y
i
)
(x
i
​
 ,y
i
​
 ) 与
(
p
i
,
q
i
)
(p
i
​
 ,q
i
​
 ) 保证相邻（上下或左右）。她希望通过合理放置通道，使尽可能多的"交头接耳"对被通道隔开。

现请你输出唯一的最优方案，在该方案下，仍未被通道隔开的"交头接耳"对的数量最少。
输入描述：
第一行输入五个整数
n
,
m
,
k
,
l
,
d
(
2
≦
n
,
m
≦
1
0
3
;

0
<
k
<
n
;

0
<
l
<
m
;

0
<
d
≦
2
×
min
⁡
{
n
×
m
,
2
×
1
0
3
}
)
n,m,k,l,d(2≦n,m≦10
3
 ; 0<k<n; 0<l<m; 0<d≦2×min{n×m,2×10
3
 })。

接下来
d
d 行，每行输入四个整数
x
i
,
y
i
,
p
i
,
q
i
x
i
​
 ,y
i
​
 ,p
i
​
 ,q
i
​
 ，表示坐标
(
x
i
,
y
i
)
(x
i
​
 ,y
i
​
 ) 与
(
p
i
,
q
i
)
(p
i
​
 ,q
i
​
 ) 的两位同学会交头接耳，且两坐标上下相邻或左右相邻。

保证最优方案存在且唯一。
输出描述：
第一行输出
k
k 个严格递增的整数
a
1
,
a
2
,
…
,
a
k
(
1
≦
a
1
<
⋯
<
a
k
≦
n
−
1
)
a
1
​
 ,a
2
​
 ,…,a
k
​
 (1≦a
1
​
 <⋯<a
k
​
 ≦n−1)，在行
a
i
a
i
​
  与
a
i
+
1
a
i
​
 +1 之间设置横向通道。

第二行输出
l
l 个严格递增的整数
b
1
,
b
2
,
…
,
b
l
(
1
≦
b
1
<
⋯
<
b
l
≦
m
−
1
)
b
1
​
 ,b
2
​
 ,…,b
l
​
 (1≦b
1
​
 <⋯<b
l
​
 ≦m−1)，在列
b
i
b
i
​
  与
b
i
+
1
b
i
​
 +1 之间设置纵向通道。
示例1
输入：
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4
复制
输出：
2
2 4
复制
说明：
该样例如下图所示，蓝底斜线方格为第一对交头接耳的同学，绿底带叉方格为第二对交头接耳的同学，粉底带星方格为第三对交头接耳的同学。粗线代表通道。该划分方案为唯一最优方案。

示例2
输入：
2 2 1 1 4
1 1 1 2
1 1 2 1
2 1 2 2
1 2 2 2
复制
输出：
1
1
"""

n, m, k, l, d = map(int, input().split())
li = []
for _ in range(d):
    x, y, p, q = map(int, input().split())
    li.append((x, y, p, q))

lik, lil = [], []
for i in range(1, n):
    cnt = 0
    for x, y, p, q in li:
        if y == q and ((x == i and p == i + 1) or (x == i + 1 and p == i)):
            cnt += 1
    lik.append((i, cnt))
for i in range(1, m):
    cnt = 0
    for x, y, p, q in li:
        if x == p and ((y == i and q == i + 1) or (y == i + 1 and q == i)):
            cnt += 1
    lil.append((i, cnt))
lik.sort(key=lambda x: x[1], reverse=True)
lil.sort(key=lambda x: x[1], reverse=True)

print(" ".join(map(str, sorted(lik[i][0] for i in range(k)))))
print(" ".join(map(str, sorted(lil[i][0] for i in range(l)))))
