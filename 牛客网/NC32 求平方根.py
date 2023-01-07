'''
描述
实现函数 int sqrt(int x).
计算并返回 x 的平方根（向下取整）

数据范围： 0 <= x < 2^{31}-10<=x<2 
31
 −1
要求：空间复杂度 O(1)O(1)，时间复杂度 O(logx)O(logx)
示例1
输入：
2
复制
返回值：
1
复制
示例2
输入：
2143195649
复制
返回值：
46294
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param x int整型
# @return int整型
#
class Solution:

    def sqrt(self, x: int) -> int:
        # write code here

        if x == 0 or x == 1: return x

        left, right = 1, x
        while left < right:
            mid = (left + right) // 2
            y = mid * mid - x
            yt = (mid + 1)**2 - x
            if y <= 0 and yt > 0: return mid
            if y < 0: left = mid
            else: right = mid
        return mid
