"""
描述
给定
n
n 个元素，第
i
i 个元素具有特征值
A
i
A
i
​
 。定义FST 距离如下：

d
i
s
t
(
i
,
j
)
=
∣
i
2
−
j
2
∣
+
∣
A
i
2
−
A
j
2
∣
dist(i,j)=∣i
2
 −j
2
 ∣+∣A
i
2
​
 −A
j
2
​
 ∣

请计算
A
i
A
i
​
  中所有元素对儿中的最大 FST 距离。
输入描述：
第一行输入一个整数
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
 )。
第二行输入
n
n 个整数
A
1
,
A
2
,
…
,
A
n
(
1
≦
A
i
≦
1
0
9
)
A
1
​
 ,A
2
​
 ,…,A
n
​
 (1≦A
i
​
 ≦10
9
 )。
输出描述：
输出一个整数，表示最大距离。
示例1
输入：
2
4 3
复制
输出：
10
复制
说明：
∣
4
2
−
3
2
∣
+
∣
2
2
−
1
2
∣
=
7
+
3
=
10
∣4
2
 −3
2
 ∣+∣2
2
 −1
2
 ∣=7+3=10。
备注：
"""

# 看做曼哈顿距离, 之后转换为切比雪夫距离, 利用切比雪夫距离的性质来做

n = int(input())
A = [0] + list(map(int, input().split()))
U = [i * i + A[i] * A[i] for i in range(1, n + 1)]
V = [i * i - A[i] * A[i] for i in range(1, n + 1)]
ans = max(max(U) - min(U), max(V) - min(V))
print(ans)
