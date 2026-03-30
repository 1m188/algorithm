"""
描述
给定整数序列
a
1
,
a
2
,
…
,
a
N
a
1
​
 ,a
2
​
 ,…,a
N
​
  和常数
C
C，统计序列中有多少有序数对
(
i
,
j
)
(i,j) 满足
1
≦
i
,
j
≦
N
1≦i,j≦N 且
a
i
−
a
j
=
C
a
i
​
 −a
j
​
 =C。
输入描述：
第一行输入两个整数
N
,
C

(
1
≦
N
≦
2
×
1
0
5
,

0
≦
C
<
2
30
)
N,C (1≦N≦2×10
5
 , 0≦C<2
30
 )；
第二行输入
N
N 个整数
a
1
,
a
2
,
…
,
a
N

(
0
≦
a
i
<
2
30
)
a
1
​
 ,a
2
​
 ,…,a
N
​
  (0≦a
i
​
 <2
30
 )。
输出描述：
输出一个整数，表示满足条件的有序数对数量。
示例1
输入：
5 2
1 3 3 4 5
复制
输出：
4
复制
说明：
在此样例中，满足条件的有序数对有
(
2
,
1
)
,
(
3
,
1
)
,
(
5
,
2
)
,
(
5
,
3
)
(2,1),(3,1),(5,2),(5,3)，共
4
4 对。
"""

n, c = map(int, input().split())
a = list(map(int, input().split()))
di: dict[int, int] = {}
for i in a:
    di[i] = di.get(i, 0) + 1
ans = 0
for k, v in di.items():
    ans += v * di.get(k + c, 0)
print(ans)
