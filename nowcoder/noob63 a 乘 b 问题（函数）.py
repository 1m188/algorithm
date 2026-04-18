"""
描述
你需要编写一个函数，实现整数之间的乘法功能。

具体而言，你的函数会接收两个参数：
a
,
b
(
−
1
0
9
≦
a
,
b
≦
1
0
9
)
a,b(−10
9
 ≦a,b≦10
9
 )，你需要计算出这两个数的乘积，并将这个结果作为函数的返回值。
示例1
输入：
1,8
复制
返回值：
8
复制
示例2
输入：
11,11
复制
返回值：
121
复制
示例3
输入：
1000000000,2000000000
复制
返回值：
2000000000000000000
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 计算两个参数的乘积
# @param Number1 int整型
# @param Number2 int整型
# @return long长整型
#
class Solution:
    def aTimesB(self, Number1: int, Number2: int) -> int:
        # write code here

        return Number1 * Number2
