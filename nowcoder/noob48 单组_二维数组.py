"""
描述
给定一个
n
n 行
m
m 列的二维正整数数组
{
a
i
,
j
}
{a
i,j
​
 }，其中
1
≦
i
≦
n
1≦i≦n，
1
≦
j
≦
m
1≦j≦m，且
1
≦
a
i
,
j
≦
1
0
9
1≦a
i,j
​
 ≦10
9
 。
请计算数组中所有元素之和。
输入描述：
在一行上输入两个整数
n
,
m
n,m
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
)
(1≦n,m≦10
3
 )。
接下来
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
a
i,1
​
 ,a
i,2
​
 ,…,a
i,m
​

(
1
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
(1≦a
i,j
​
 ≦10
9
 )。
输出描述：
输出一个整数，表示二维数组所有元素之和。
示例1
输入：
3 4
1 2 3 4
5 6 7 8
9 10 11 12
复制
输出：
78
"""

n, m = map(int, input().split())
ans = 0
for _ in range(n):
    ans += sum(map(int, input().split()))
print(ans)
