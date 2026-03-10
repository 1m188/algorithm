"""
描述
一群孩子做游戏，现在请你根据游戏得分来发糖果，要求如下：

1. 每个孩子不管得分多少，起码分到一个糖果。
2. 任意两个相邻的孩子之间，得分较多的孩子必须拿多一些糖果。(若相同则无此限制)

给定一个数组
a
r
r
arr 代表得分数组，请返回最少需要多少糖果。

要求: 时间复杂度为
O
(
n
)
O(n) 空间复杂度为
O
(
n
)
O(n)

数据范围：
1
≤
n
≤
100000
1≤n≤100000 ，
1
≤
a
i
≤
1000
1≤a
i
​
 ≤1000

示例1
输入：
[1,1,2]
复制
返回值：
4
复制
说明：
最优分配方案为1,1,2
示例2
输入：
[1,1,1]
复制
返回值：
3
复制
说明：
最优分配方案是1,1,1
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# pick candy
# @param arr int整型一维数组 the array
# @return int整型
#
class Solution:
    def candy(self, arr: List[int]) -> int:
        # write code here

        if not arr:
            return 0
        if len(arr) == 1:
            return 1

        ans = 0
        n = len(arr)
        left = [1] * n
        right = [1] * n

        for i in range(1, n):
            if arr[i] > arr[i - 1]:
                left[i] = left[i - 1] + 1

        for i in range(n - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                right[i] = right[i + 1] + 1

        for i in range(n):
            ans += max(left[i], right[i])

        return ans
