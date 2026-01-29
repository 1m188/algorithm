'''
描述
现在有一个没有重复元素的整数集合S，求S的所有子集
注意：
你给出的子集中的元素必须按升序排列
给出的解集中不能出现重复的元素

数据范围：
1
≤
n
≤
5
1≤n≤5，集合中的任意元素满足 
∣
v
a
l
∣
≤
10
∣val∣≤10
要求：空间复杂度 
O
(
n
!
)
O(n!)，时间复杂度 
O
(
n
!
)
O(n!)
示例1
输入：
[1,2,3]
复制
返回值：
[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
复制
示例2
输入：
[]
复制
返回值：
[]

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param S int整型一维数组
# @return int整型二维数组
#
class Solution:

    def subsets(self, S: List[int]) -> List[List[int]]:
        # write code here

        n = len(S)
        if n == 0: return []

        S.sort()
        res = [[]]
        tmp = []

        def dfs(idx: int = 0):
            for i in range(idx, n):
                tmp.append(S[i])
                res.append(tmp.copy())
                dfs(i + 1)
                tmp.pop()

        dfs()
        return res
