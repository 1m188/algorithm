"""
描述
给定
T
T 个正整数，对于每个整数
n
n，请你判断
n
n 是否为质数（素数）。若
n
n 是质数输出
Yes
Yes，否则输出
No
No。
输入描述：
第一行输入一个整数
T
(
1
≦
T
≦
1
0
5
)
T(1≦T≦10
5
  ) 代表测试用例数量。
接下来
T
T 行，每行输入一个整数
n
(
1
≦
n
≦
1
0
6
)
n(1≦n≦10
6
  )。
输出描述：
对于每个输入的
n
n，在一行上输出
Yes
Yes 或
No
No，表示
n
n 是否为质数。
示例1
输入：
1
1
复制
输出：
No
"""

import sys

# 预处理：埃氏筛，上限 10^6
MAXN = 10**6
is_prime = [True] * (MAXN + 1)
is_prime[0] = is_prime[1] = False  # 0 和 1 不是质数

for i in range(2, MAXN + 1):
    if is_prime[i]:
        # 将 i 的所有倍数标记为合数
        step = i
        start = i * i
        if start > MAXN:
            continue
        for j in range(start, MAXN + 1, step):
            is_prime[j] = False


def solve() -> None:
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    out_lines = []
    for idx in range(1, t + 1):
        n = int(data[idx])
        out_lines.append("Yes" if is_prime[n] else "No")
    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()
