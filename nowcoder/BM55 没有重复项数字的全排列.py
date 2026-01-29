'''

描述
给出一组数字，返回该组数字的所有排列
例如：
[1,2,3]的所有排列如下
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], [3,2,1].
（以数字在数组中的位置靠前为优先级，按字典序排列输出。）

数据范围：数字个数 
0
<
�
≤
6
0<n≤6
要求：空间复杂度 
�
(
�
!
)
O(n!) ，时间复杂度 
�
(
�
!
）
O(n!）
示例1
输入：
[1,2,3]
复制
返回值：
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
复制
示例2
输入：
[1]
复制
返回值：
[[1]]

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

    def permute(self, num: List[int]) -> List[List[int]]:
        # write code here

        self.num = num
        self.res = []
        self.flags = [False for _ in range(len(num))]
        self.dfs([])
        return self.res

    def dfs(self, li: list[int]):
        if len(li) == len(self.num):
            self.res.append(li.copy())
            return

        for i, v in enumerate(self.num):
            if not self.flags[i]:
                self.flags[i] = True
                li.append(v)
                self.dfs(li)
                li.pop()
                self.flags[i] = False
