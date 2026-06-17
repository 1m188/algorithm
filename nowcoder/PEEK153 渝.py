"""
描述
⭐我喜欢海棠花不眠
可惜一切都来不及了...
Bingbong 拿到一个由数字
0
0 和
1
1 组成的三角形，一共有
n
n 行，第
i
i 行有
i
i 个数字。我们使用
(
i
,
j
)
(i,j) 表示从上往下数第
i
i 行和从左往右数第
j
j 列的位置，使用
a
i
,
j
a
i,j
​
  代表这个单元格中的数字。
Bingbong 初始时位于
(
1
,
1
)
(1,1)，她每次移动会选择移动到
(
i
+
1
,
j
)
(i+1,j) 或者
(
i
+
1
,
j
+
1
)
(i+1,j+1)，每到一个位置会得到该位置的元素值，记作
b
i
b
i
​
 。
最终移动到第
n
n 行时，共得到了
n
n 个元素，通过拼接后，我们记作
b
1
b
2
b
3
⋯
b
n
b
1
​
 b
2
​
 b
3
​
 ⋯b
n
​
 ，即字符串
b
b。
现在请你求出到达第
n
n 行后，有多少条路径满足字符串
b
b 是一个回文串。由于答案可能很大，请将答案对
(
1
0
9
+
7
)
(10
9
 +7) 取模后输出。

一个字符串被称作回文串，当且仅当这个字符串从左往右读和从右往左读是相同的。
输入描述：
第一行输入一个整数
n
(
1
≦
n
≦
500
)
n(1≦n≦500)，表示行数。
此后
n
n 行，第
i
i 行输入
i
i 个整数
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
i
(
0
≦
a
i
,
j
≦
1
)
a
i,1
​
 ,a
i,2
​
 ,…,a
i,i
​
 (0≦a
i,j
​
 ≦1)，其中，
a
i
,
j
a
i,j
​
  表示三角形中第
i
i 行第
j
j 个元素。
输出描述：
一个整数，表示字符串
b
b 为回文串的路径总数。由于答案可能很大，请将答案对
(
1
0
9
+
7
)
(10
9
 +7) 取模后输出。
示例1
输入：
3
1
0 0
1 1 1
复制
输出：
4
复制
示例2
输入：
1
1
复制
输出：
1
"""

MOD = 10**9 + 7


def solve():
    import sys

    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    # 读入三角形，a[row][col]，0-indexed
    a = []
    for i in range(n):
        row = []
        for _ in range(i + 1):
            row.append(int(next(it)))
        a.append(row)

    # n == 1 时只有一条路径，单字符总是回文串
    if n == 1:
        print(1)
        return

    # dp[c1][c2]：forward 到达当前行的第 c1 列，backward 到达对称行的第 c2 列
    # 行列均使用 1-indexed，与输入保持一致
    # 初始：forward 在 (1, 1)，backward 在 (n, c2)，要求 a[1][1] == a[n][c2]
    dp = [[0] * (n + 2) for _ in range(n + 2)]
    for c2 in range(1, n + 1):
        if a[0][0] == a[n - 1][c2 - 1]:
            dp[1][c2] = 1

    # 从第 1 行向中间推进
    r = 1  # 当前 forward 所在行
    # 根据 n 的奇偶性确定终止行
    if n & 1:
        end_row = (n + 1) // 2  # 奇：最终 forward/backward 在中间行相遇
    else:
        end_row = n // 2  # 偶：forward 到达 n/2，backward 在 n/2+1

    while r < end_row:
        nxt = [[0] * (n + 2) for _ in range(n + 2)]
        # forward: 从 (r, c1) → (r+1, c1) 或 (r+1, c1+1)
        # backward: 从 (n+1-r, c2) → (n-r, c2) 或 (n-r, c2-1)
        for c1 in range(1, r + 1):
            for c2 in range(c1, n + 2 - r):
                val = dp[c1][c2]
                if val == 0:
                    continue
                for dc1 in (0, 1):
                    c1_new = c1 + dc1
                    if c1_new > r + 1:
                        continue
                    for dc2 in (0, -1):
                        c2_new = c2 + dc2
                        if c2_new < 1 or c2_new > n - r:
                            continue
                        if c1_new > c2_new:  # forward 列不能超过 backward 列
                            continue
                        # 匹配新行上的值：forward 到达 r+1 行，backward 到达 n-r 行
                        if a[r][c1_new - 1] == a[n - r - 1][c2_new - 1]:
                            nxt[c1_new][c2_new] = (nxt[c1_new][c2_new] + val) % MOD
        dp = nxt
        r += 1

    ans = 0
    if n & 1:  # 奇数：forward 和 backward 在中间行同一列
        for c in range(1, n + 1):
            ans = (ans + dp[c][c]) % MOD
    else:  # 偶数：forward 在 n/2 行，backward 在 n/2+1 行，两者列号差 0 或 1
        for c1 in range(1, n + 1):
            ans = (ans + dp[c1][c1]) % MOD
            ans = (ans + dp[c1][c1 + 1]) % MOD
    print(ans)


if __name__ == "__main__":
    solve()
