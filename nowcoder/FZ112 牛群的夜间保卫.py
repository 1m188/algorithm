'''
描述
农场里有一群牛，每头牛都有一个编号。农场主每晚都会选择一些牛进行夜间巡逻，以防止野生动物入侵。每头牛的警戒值表示为一个非负整数，代表它在巡逻时的警觉程度。由于牛群围成了一个圈，农场主不能同时选择相邻的两头牛进行巡逻，以免出现警戒盲区。

给定一个代表每头牛警戒值的非负整数数组，计算农场主在不选择相邻牛的情况下，能够得到的最大警戒值。

示例1
输入：
[1, 2, 3]
复制
返回值：
4
复制
示例2
输入：
[1, 2, 4, 1]
复制
返回值：
5
复制
备注：
1 <= values.length <= 500
0 <= values[i] <= 2000
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param values int整型一维数组
# @return int整型
#
class Solution:

    def maxPatrolValue(self, values: List[int]) -> int:
        # write code here

        n = len(values)

        dp = [0 for _ in range(n)]
        dp[0] = values[0]
        dp[1] = max(dp[0], values[1])

        for i in range(2, n):
            if dp[i - 2] == dp[i - 1]: dp[i] = dp[i - 1] + values[i]
            else: dp[i] = max(dp[i - 1], dp[i - 2] + values[i])

        return max(dp)
