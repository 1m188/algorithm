"""
描述
你有一个背包，最大容量为
V
V。现有
n
n 件物品，第
i
i 件物品的体积为
v
i
v
i
​
 ，价值为
w
i
w
i
​
 。研究人员提出以下两种装填方案：
1.

1.
​
  不要求装满背包，求能获得的最大总价值；
2.

2.
​
  要求最终恰好装满背包，求能获得的最大总价值。若不存在使背包恰好装满的装法，则答案记为
0
0。
输入描述：
第一行输入两个整数
n
n 和
V
(
1
≦
n
,
V
≦
1
0
3
)
V(1≦n,V≦10
3
 )，分别表示物品数量与背包容量。
此后
n
n 行，第
i
i 行输入两个整数
v
i
,
w
i
(
1
≦
v
i
,
w
i
≦
1
0
3
)
v
i
​
 ,w
i
​
 (1≦v
i
​
 ,w
i
​
 ≦10
3
 )，分别表示第
i
i 件物品的体积与价值。
输出描述：
输出两行：
1.

1.
​
  第一行输出方案
1
1 的答案；
2.

2.
​
  第二行输出方案
2
2 的答案（若无解输出
0
0）。
示例1
输入：
3 5
2 10
4 5
1 4
复制
输出：
14
9
复制
说明：
在该组样例中：
∙

∙ 选择第
1
1、第
3
3 件物品即可获得最大价值
10
+
4
=
14
10+4=14（未装满）；
∙

∙ 选择第
2
2、第
3
3 件物品可使背包体积
4
+
1
=
5
4+1=5 恰好装满且价值最大，为
5
+
4
=
9
5+4=9。
示例2
输入：
3 8
12 6
11 8
6 8
复制
输出：
8
0
复制
说明：
装第三个物品时总价值最大但是不满，装满背包无解。
备注：
要求
O
(
n
V
)
O(nV) 的时间复杂度，
O
(
V
)
O(V) 空间复杂度。
"""

n, V = map(int, input().split())
v, w = [0 for _ in range(n + 1)], [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    v[i], w[i] = map(int, input().split())
sumw = sum(w)


def case1() -> int:
    dp = [[0 for _ in range(V + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, V + 1):
            if j >= v[i]:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][V]


def case2() -> int:
    dp = [[0 for _ in range(V + 1)] for _ in range(n + 1)]
    dp[0][0] = 0
    for i in range(1, n + 1):
        dp[i][0] = 0
    for j in range(1, V + 1):
        dp[0][j] = -sumw - 1
    for i in range(1, n + 1):
        for j in range(1, V + 1):
            if j >= v[i]:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
            else:
                dp[i][j] = dp[i - 1][j]
    if dp[n][V] < 0:
        dp[n][V] = 0
    return dp[n][V]


print(case1())
print(case2())
