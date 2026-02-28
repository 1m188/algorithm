"""
描述
给定数组arr，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
如果无解，请返回-1.

数据范围：数组大小满足
0
≤
n
≤
10000
0≤n≤10000 ， 数组中每个数字都满足
0
<
v
a
l
≤
10000
0<val≤10000，
0
≤
a
i
m
≤
5000
0≤aim≤5000

要求：时间复杂度
O
(
n
×
a
i
m
)
O(n×aim) ，空间复杂度
O
(
a
i
m
)
O(aim)。

示例1
输入：
[5,2,3],20
复制
返回值：
4
复制
示例2
输入：
[5,2,3],0
复制
返回值：
0
复制
示例3
输入：
[3,5],2
复制
返回值：
-1
复制
备注：
0
≤
n
≤
10

000
0≤n≤10000
0
≤
a
i
m
≤
5

000
0≤aim≤5000
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 最少货币数
# @param arr int整型一维数组 the array
# @param aim int整型 the target
# @return int整型
#
class Solution:
    def minMoney(self, arr: List[int], aim: int) -> int:

        if not arr:
            return -1

        dp = [aim + 1 for _ in range(aim + 1)]
        dp[0] = 0
        for i in arr:
            if i <= aim:
                dp[i] = 1

        # 这题的关键在于有可能部分面值之间的值可能可以用已有面值表示
        for i in range(1, aim + 1):
            li = [dp[i - j] for j in arr if i - j >= 0]
            dp[i] = min(li) + 1 if li else dp[i]

        return dp[aim] if dp[aim] <= aim else -1
