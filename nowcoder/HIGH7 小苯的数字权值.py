"""
描述
定义正整数 n 的权值为 n 的正因子的数量，即 wt(n)=τ(n)，其中 τ(n) 表示 n 的因子个数。
给定一个正整数 x，你可以将 x 分解为若干个大于 1 的正整数 p₁,p₂,…,pₖ（k≧1），要求
∙ p₁×p₂×⋯×pₖ = x；
∙ 最大化 Σ wt(pᵢ)。

请你求出在最优分解下，上述表达式的最大可能值。

输入描述：
第一行输入一个整数 T (1≦T≦10⁴) 表示测试数据组数。
此后 T 行，每行输入一个整数 x (2≦x≦2×10⁵)。

输出描述：
对于每组数据，在一行上输出对应的最大权值和。

解法：
1. 筛法 O(N log N) 计算 τ(n) = n 的正因数个数
2. DP：f[x] = max(τ(x), max_{d|x, 1<d<x} f[d] + f[x/d])
3. O(1) 回答每个查询
"""

import sys

MAX = 200000


def main() -> None:
    # ---------- 1. 筛法计算 τ(n) ----------
    tau = [0] * (MAX + 1)  # 因数个数
    for i in range(1, MAX + 1):
        step = i
        j = i
        while j <= MAX:
            tau[j] += 1
            j += step

    # ---------- 2. DP 计算 f[x] ----------
    # 初始化：至少可以不分解（取自身），和 = tau[x]
    dp = tau[:]  # copy
    # O(N log N)：枚举每个因数 d，尝试将 x 分解为 d * (x/d)
    for d in range(2, MAX + 1):
        # 枚举 d 的倍数 m，使得 m = d * (m//d) 且 m//d >= 2
        for m in range(d * 2, MAX + 1, d):
            cand = dp[d] + dp[m // d]
            if cand > dp[m]:
                dp[m] = cand

    # ---------- 3. 处理输入输出 ----------
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    out_lines = []
    for i in range(1, t + 1):
        x = int(data[i])
        out_lines.append(str(dp[x]))
    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()
