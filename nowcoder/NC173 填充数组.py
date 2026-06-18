"""
描述
牛妹给了牛牛一个长度为
n
n 的下标从
0
0开始的正整型数组
a
a ，粗心的牛牛不小心把其中的一些数字删除了。

假如
a
i
a
i
​
 被删除了，则
a
i
=
0
a
i
​
 =0。对于所有被删除的数字，牛牛必须选择一个正整数填充上。现在牛牛想知道有多少种填充方案使得：

a
0
≤
a
1
≤
.
.
.
≤
a
n
−
1
a
0
​
 ≤a
1
​
 ≤...≤a
n−1
​
  且对于所有的
0
≤
i
≤
n
−
1
0≤i≤n−1满足
1
≤
a
i
≤
k
1≤a
i
​
 ≤k 。
函数传入一个下标从
0
0开始的数组
a
a 和一个正整数
k
k ，请返回合法的填充方案数对
1
0
9
+
7
10
9
 +7取模的值,保证不存在方案数为0的数据。

示例1
输入：
[0,4,5],6
复制
返回值：
4
复制
说明：
所有的合法填充方案是：[1,4,5],[2,4,5],[3,4,5],[4,4,5]，共4种。
示例2
输入：
[1,0,0],3
复制
返回值：
6
复制
说明：
所有的合法填充方案是：[1,1,1],[1,1,2],[1,2,2],[1,2,3],[1,3,3],[1,1,3]共6种
示例3
输入：
[0,0,0,0,0,67,0,0],100
复制
返回值：
746845806
复制
备注：
1
≤
n
,
k
≤
1000
1≤n,k≤1000

数组
a
a满足
0
≤
a
i
≤
k
0≤a
i
​
 ≤k
"""

from typing import List

MOD = 10**9 + 7


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param a int整型一维数组
# @param k int整型
# @return int整型
#
class Solution:
    def FillArray(self, a: List[int], k: int) -> int:
        n = len(a)
        # 预处理组合数 C(max_n, *) 所需的最大 n = n + k (最坏情况 hi-lo+len 可达 n + k)
        max_n = n + k
        fact = [1] * (max_n + 1)
        for i in range(1, max_n + 1):
            fact[i] = fact[i - 1] * i % MOD
        inv_fact = [1] * (max_n + 1)
        inv_fact[max_n] = pow(fact[max_n], MOD - 2, MOD)
        for i in range(max_n, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD

        def C(N, M: int) -> int:
            """组合数 C(N, M) mod MOD (0 <= M <= N)"""
            if M < 0 or M > N:
                return 0
            return fact[N] * inv_fact[M] % MOD * inv_fact[N - M] % MOD

        # 收集所有已知位置（值不为 0 的索引）
        known_pos = []
        for i, v in enumerate(a):
            if v != 0:
                known_pos.append(i)

        # 如果没有任何已知值，整个数组全为 0
        if not known_pos:
            # 需要填充 n 个位置，值在 [1, k] 且非递减
            # 方案数 = C(k - 1 + n, n)
            return C(k - 1 + n, n) % MOD

        ans = 1

        # 处理前缀：索引 [0, known_pos[0]-1]，值范围为 [1, a[known_pos[0]]]
        first_pos = known_pos[0]
        if first_pos > 0:
            lo, hi = 1, a[first_pos]
            length = first_pos
            ans = ans * C(hi - lo + length, length) % MOD

        # 处理相邻已知位置之间的区间
        for idx in range(len(known_pos) - 1):
            p1, p2 = known_pos[idx], known_pos[idx + 1]
            if p1 + 1 == p2:
                continue  # 相邻，没有空隙
            lo, hi = a[p1], a[p2]
            length = p2 - p1 - 1
            ans = ans * C(hi - lo + length, length) % MOD

        # 处理后缀：索引 [known_pos[-1]+1, n-1]，值范围为 [a[known_pos[-1]], k]
        last_pos = known_pos[-1]
        if last_pos < n - 1:
            lo, hi = a[last_pos], k
            length = n - 1 - last_pos
            ans = ans * C(hi - lo + length, length) % MOD

        return ans % MOD
