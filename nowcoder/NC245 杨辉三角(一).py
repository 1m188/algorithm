'''

描述
给定一个非负整数 num ，生成杨辉三角的前 num 行。
杨辉三角中，每个数是左上方和右上方的数之和。

数据范围： 
1
≤
�
�
�
≤
30
 
1≤num≤30 

例如当输入为4时，对应的返回值为[[1],[1,1],[1,2,1],[1,3,3,1]]，打印结果如下图所示：

示例1
输入：
1
复制
返回值：
[[1]]
复制
示例2
输入：
4
复制
返回值：
[[1],[1,1],[1,2,1],[1,3,3,1]]

'''

from typing import List
import math


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param num int整型
# @return int整型二维数组
#
class Solution:

    def generate(self, num: int) -> List[List[int]]:
        # write code here

        res = [[1]]

        for i in range(2, num + 1):
            li = []
            half = math.ceil(i / 2)
            prev = res[i - 1 - 1]

            for j in range(half):
                if j == 0: li.append(prev[j])
                else: li.append(prev[j - 1] + prev[j])

            if i % 2 == 0:
                li = li + list(reversed(li))
            else:
                li = li + list(reversed(li[:-1]))

            res.append(li)

        return res
