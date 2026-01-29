'''

描述
给出一组可能包含重复项的数字，返回该组数字的所有排列。结果以字典序升序排列。

数据范围： 
0
<
�
≤
8
0<n≤8 ，数组中的值满足 
−
1
≤
�
�
�
≤
5
−1≤val≤5
要求：空间复杂度 
�
(
�
!
)
O(n!)，时间复杂度 
�
(
�
!
)
O(n!)
示例1
输入：
[1,1,2]
复制
返回值：
[[1,1,2],[1,2,1],[2,1,1]]
复制
示例2
输入：
[0,1]
复制
返回值：
[[0,1],[1,0]]

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param num int整型一维数组
# @return int整型二维数组
#
class Solution:

    def permuteUnique(self, num: List[int]) -> List[List[int]]:
        # write code here

        res = []
        flags = [False for _ in range(len(num))]

        def dfs(li: list[int] = []):
            if len(li) == len(num):
                res.append(li.copy())
                return

            for i, v in enumerate(num):
                if not flags[i]:
                    flags[i] = True
                    li.append(v)
                    dfs(li)
                    li.pop()
                    flags[i] = False

        dfs()

        res.sort()
        i = 0
        while i + 1 < len(res):
            if res[i] == res[i + 1]: del res[i + 1]
            else: i += 1

        return res
