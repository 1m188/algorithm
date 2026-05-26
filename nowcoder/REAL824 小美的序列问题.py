r"""
# REAL824 小美的序列问题
困难  通过率：7.05%  时间限制：2秒    空间限制：256M
知识点：数组、前缀和

校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。

## 描述
对于给定的由n个整数组成的数组{a₁,a₂,…,aₙ}，计算其中有多少个三元组(i,j,k)满足1≤i<j<k≤n且aᵢ>aₖ>aⱼ。例如，在数组{4,1,2,3}中三元组(1,2,3),(1,2,4),(1,3,4)都是满足条件的三元组。更具体地，计算：
\sum\limits_{1\le i < j < k \le n}\left[a_i>a_k>a_j\right]

请编写一个函数，计算并返回满足条件的三元组的数量。

【名词解释】
本题公式中的中括号代表艾弗森括号，具体地：
[P] = \begin{cases} 1 & \text{如果 } P \text{ 为真} \\ 0 & \text{如果 } P \text{ 为假} \end{cases}

## 输入描述
第一行输入一个整数n (1≤n≤2×10⁵) 代表数组中的元素个数。
第二行输入n个整数a₁,a₂,…,aₙ (-10⁹≤aᵢ≤10⁹) 代表数组中的元素。

## 输出描述
输出一个整数，表示满足条件的三元组个数。

## 示例1
输入：
```
5
1 5 4 2 3
```
输出：
```
2
```
说明：
在这个样例中，满足条件的三元组有：
- i=2、j=4且k=5构成的三元组{5,2,3}；
- i=3、j=4且k=5构成的三元组{4,2,3}。

## 示例2
输入：
```
20
-6 -9 -90 -73 89 -90 2 19 52 -16 -41 -22 85 24 -22 66 75 78 48 -36
```
输出：
```
134
"""

import sys


class BIT:
    """Fenwick 树：单点加、前缀和"""

    __slots__ = ("n", "tree")

    def __init__(self, n: int):
        self.n = n
        self.tree = [0] * (n + 2)

    def add(self, idx: int, val: int):
        i = idx + 1
        n = self.n + 1
        while i <= n:
            self.tree[i] += val
            i += i & -i

    def sum(self, idx: int) -> int:
        if idx < 0:
            return 0
        i = idx + 1
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    # 按值降序排列，值相同的归为一组
    pairs = [(a[i], i) for i in range(n)]
    pairs.sort(key=lambda x: -x[0])

    bit_cnt = BIT(n)  # 已处理位置的数量
    bit_sum = BIT(n)  # 已处理位置的下标之和

    ans = 0
    i = 0

    while i < n:
        j = i
        while j < n and pairs[j][0] == pairs[i][0]:
            j += 1

        # 同值组内按位置升序处理，避免同值元素互为 j（需 a_j < a_k 严格）
        group_positions = sorted(pairs[k][1] for k in range(i, j))
        running_sub = 0

        for pos in group_positions:
            m = bit_cnt.sum(pos - 1)  # pos 之前已处理的元素数
            sum_q = bit_sum.sum(pos - 1)  # pos 之前已处理元素的下标之和
            total = (pos - 1) * m - sum_q  # ∑_{j<pos} stored[j]
            ans += total - m * (m - 1) // 2 - running_sub
            running_sub += m  # stored[pos] = m

        # 标记为已处理
        for pos in group_positions:
            bit_cnt.add(pos, 1)
            bit_sum.add(pos, pos)

        i = j

    sys.stdout.write(str(ans))


if __name__ == "__main__":
    solve()
