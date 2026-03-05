"""
描述
给定一个正整数
X
X,令
X
=
1
X=1 :
你可以对整数
X
X执行以下操作(次数不限):
选择一个大于等于
2
2的整数
K
K。支付
K
K单位的成本，令
X
=
K
×
X
X=K×X。
给定正整数
N
N，找出使
X
=
N
X=N所需的最小成本
输入描述：
输入的第一行包含一个正整数
N
N。
1
≤
N
≤
3
×
1
0
5
1≤N≤3×10
5

输出描述：
输出使
X
=
N
X=N所需的最小成本
示例1
输入：
12
复制
输出：
7
"""

n = int(input())
ans = 0
for i in range(2, int(n**0.5) + 1):
    while n % i == 0:
        ans += i
        n //= i
if n > 1:
    ans += n
print(ans)
