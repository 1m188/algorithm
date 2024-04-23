'''
描述
农场里有一群牛，每头牛都有一个编号。农场主每晚都会选择一些牛进行夜间巡逻，以防止野生动物入侵。每头牛的警戒值表示为一个非负整数，代表它在巡逻时的警觉程度。由于牛群围成了一个圈，农场主不能同时选择相邻的两头牛进行巡逻，以免出现警戒盲区。

给定一个代表每头牛警戒值的非负整数数组，计算农场主在不选择相邻牛的情况下，能够得到的最大警戒值。

示例1
输入：
[2, 3, 2]
复制
返回值：
3
复制
说明：
你不能选择 1 号牛（警戒值 = 2）和 3 号牛（警戒值 = 2），因为它们是相邻的。所以可以选择警戒值最高的 2 号牛（警戒值 = 3）。
示例2
输入：
[1, 2, 3, 1]
复制
返回值：
4
复制
说明：
你可以选择 1 号牛（警戒值 = 1）和 3 号牛（警戒值 = 3），得到的最大警戒值 = 1 + 3 = 4。

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
        if n == 1 or n == 2 or n == 3: return max(values)

        dp1 = [0 for _ in range(n)]
        dp1[0] = values[0]
        dp1[1] = max(dp1[0], values[1])
        for i in range(2, n - 1):
            if dp1[i - 2] == dp1[i - 1]: dp1[i] = dp1[i - 1] + values[i]
            else: dp1[i] = max(dp1[i - 1], dp1[i - 2] + values[i])

        dp2 = [0 for _ in range(n)]
        dp2[1] = values[1]
        dp2[2] = max(dp2[1], values[2])
        for i in range(3, n):
            if dp2[i - 2] == dp2[i - 1]: dp2[i] = dp2[i - 1] + values[i]
            else: dp2[i] = max(dp2[i - 1], dp2[i - 2] + values[i])

        return max(max(dp1[:-1]), max(dp2[1:]))
