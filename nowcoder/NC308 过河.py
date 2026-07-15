"""
描述
在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧。在桥上有一些石子，青蛙很讨厌踩在这些石子上。由于桥的长度和青蛙一次跳过的距离都是正整数，我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。青蛙从桥的起点开始，不停的向终点方向跳跃。一次跳跃的距离是S到T之间的任意正整数（包括S,T）。当青蛙跳到或跳过坐标为L的点时，就算青蛙已经跳出了独木桥。

题目给出独木桥的长度L，青蛙跳跃的距离范围S,T，桥上石子的位置。你的任务是确定青蛙要想过河，最少需要踩到的石子数。

其中正整数 l ，表示独木桥的长度。s，t，分别表示青蛙一次跳跃的最小距离，最大距离，数组 nums 中 m 个不同的正整数分别表示这 m 个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。

数据范围：
1
≤
L
≤
1
0
9

1≤L≤10
9
   ，
1
≤
S
≤
T
≤
10

1≤S≤T≤10 ，
1
≤
M
≤
100

1≤M≤100
示例1
输入：
10,2,3,[2,3,5,6,7]
复制
返回值：
2
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param l int整型
# @param s int整型
# @param t int整型
# @param nums int整型一维数组
# @return int整型
#
class Solution:
    def crossRiver(self, l: int, s: int, t: int, nums: List[int]) -> int:
        """
        路径压缩 + DP

        核心思路：
        - L 可达 10^9，但石头数 M ≤ 100，S,T ≤ 10
        - 当 S == T 时，青蛙只能跳固定步长，直接检查位置是 S 倍数的石头数
        - 当 S < T 时，两点间距 > S*T 的部分可压缩（因为 S..T 的连续跳跃总能到达
          足够远的点，超过 S*T 的间隙可以缩短为 S*T 而不影响可达性）
        - 压缩后将所有石头排在紧凑的位置上，用 DP 求到终点的最小踩石头数
        """
        stones = sorted(nums)

        # 特判：S == T，步长固定
        if s == t:
            return sum(1 for x in stones if x % s == 0)

        # 路径压缩：两点间距超过 S*T 的，压缩到 S*T
        # 这样 DP 数组最多约 M * S * T ≈ 100 * 100 = 10000 长度
        max_gap = s * t  # 最大间隔，9*10=90 以内
        compressed = []
        offset = 0  # 累积偏移量
        prev = 0
        for x in stones:
            gap = x - prev
            if gap > max_gap:
                gap = max_gap
            offset += gap
            compressed.append(offset)
            prev = x

        # 最终终点也做压缩
        gap = l - prev
        if gap > max_gap:
            gap = max_gap
        L_comp = offset + gap

        # DP: dp[i] = 到达位置 i 最少踩到几个石子
        INF = 10**9
        stone_set = set(compressed)  # 压缩后的石头位置
        dp = [INF] * (L_comp + 1)
        dp[0] = 0  # 起点没有石子

        for i in range(1, L_comp + 1):
            for step in range(s, t + 1):
                prev_pos = i - step
                if prev_pos < 0:
                    continue
                cost = dp[prev_pos] + (1 if i in stone_set else 0)
                if cost < dp[i]:
                    dp[i] = cost

        # 青蛙可以跳到或跳过 L，所以答案是 min(dp[L..L+T-1])
        # 由于压缩后 L_comp 是"可达的终点"，取 dp[L_comp] 即可（因为 L_comp 已被压缩到紧贴最后石头之后）
        # 但青蛙可以跳过 L，所以答案可能是更后面
        ans = INF
        for i in range(L_comp - t + 1, L_comp + 1):
            if i >= 0 and dp[i] < ans:
                ans = dp[i]
        return ans
