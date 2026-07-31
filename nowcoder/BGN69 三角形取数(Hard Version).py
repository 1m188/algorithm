"""
描述
给定一个由
n
n 行构成的数字三角形。第
i
i 行共有
2
i
−
1
2i−1 个整数，整体形状如下图所示（以
n
=
3
n=3 为例）：



从顶点（第一行唯一的数字）出发，依次向下移动恰好
n
−
1
n−1 次直到抵达最后一行。
假设当前位于第
i
i 行第
j
j 列：
1.

1.
​
 可以向正下方移动至第
(
i
+
1
)
(i+1) 行第
j
j 列；
2.

2.
​
 可以向左下方移动至第
(
i
+
1
)
(i+1) 行第
(
j
−
1
)
(j−1) 列；
3.

3.
​
 可以向右下方移动至第
(
i
+
1
)
(i+1) 行第
(
j
+
1
)
(j+1) 列。

每到达一个位置都会获得该位置的数值。定义在整个行走过程中，向左下方移动的次数记为
l
l，向右下方移动的次数记为
r
r。我们需要满足


∣
l
−
r
∣
≦
k
∣l−r∣≦k



请你选择一条合法路径，使得获得数值之和最大，并输出该最大值。
输入描述：
在一行上输入两个整数
n
,
k
(
1
≦
n
≦
300
;

0
≦
k
≦
n
)
n,k(1≦n≦300; 0≦k≦n)，分别表示数字三角形的行数与允许的移动差。
此后
n
n 行，第
i
i 行输入
2
i
−
1
2i−1 个整数

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
2
i
−
1
(
−
2
×
1
0
9
≦
a
i
,
j
≦
2
×
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
i,2i−1
​
 (−2×10
9
 ≦a
i,j
​
 ≦2×10
9
 )

共计
∑
i
=
1
n
(
2
i
−
1
)
=
n
2
i=1
∑
n
​
 (2i−1)=n
2
  个整数。
输出描述：
一个整数，表示满足条件的路径可以取得的最大数值之和。

示例1 输入：3 1 / 1 / 2 3 4 / 5 6 7 8 9 → 输出：13
示例2 输入：3 0 / 1 / 2 3 4 / 5 6 7 8 9 → 输出：12
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1
    k = int(data[idx])
    idx += 1

    a = []
    for i in range(1, n + 1):
        row = [int(data[idx + j]) for j in range(2 * i - 1)]
        idx += 2 * i - 1
        a.append(row)

    # 核心思路：令 d = r - l（右移次数减左移次数）
    # 在视觉坐标系中，d 等于当前行中偏离中心的列偏移量
    # 行 i(1-indexed) 中，d 对应的数组下标为 d + i - 1
    # 约束 |l-r|≤k 等价于最终 |d|≤k（仅对最后一行生效）
    # dp[d] = 到达当前行时 d=r-l 的最大路径和
    NEG_INF = -(10**18)
    k = min(k, n - 1)
    offset = n
    dp = [NEG_INF] * (2 * n + 1)
    dp[offset] = a[0][0]

    for i in range(2, n + 1):
        new_dp = [NEG_INF] * (2 * n + 1)
        for d in range(-(i - 2), i - 1):
            if dp[d + offset] == NEG_INF:
                continue
            val = dp[d + offset]
            # 正下方: d'=d, 数组下标 d+i-1
            new_dp[d + offset] = max(new_dp[d + offset], val + a[i - 1][d + i - 1])
            # 左下方: d'=d-1, 数组下标 d+i-2
            new_dp[d - 1 + offset] = max(
                new_dp[d - 1 + offset], val + a[i - 1][d + i - 2]
            )
            # 右下方: d'=d+1, 数组下标 d+i
            new_dp[d + 1 + offset] = max(new_dp[d + 1 + offset], val + a[i - 1][d + i])
        dp = new_dp

    ans = NEG_INF
    for d in range(-k, k + 1):
        ans = max(ans, dp[d + offset])
    print(ans)


if __name__ == "__main__":
    solve()
