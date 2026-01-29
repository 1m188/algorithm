'''

描述
如果有一个自然数 a 能被自然数 b 整除，则称 a 为 b 的倍数， b 为 a 的约数。几个自然数公有的约数，叫做这几个自然数的公约数。公约数中最大的一个公约数，称为这几个自然数的最大公约数。

输入 a 和 b , 请返回 a 和 b 的最大公约数。

数据范围：
1
≤
�
,
�
≤
1
0
9
1≤a,b≤10 
9
 
进阶：空间复杂度 
�
(
1
)
O(1)，时间复杂度 
�
(
�
�
�
�
)
O(logn)
示例1
输入：
3,6
复制
返回值：
3
复制
示例2
输入：
8,12
复制
返回值：
4
复制
备注：
a和b的范围是[1-109]

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 求出a、b的最大公约数。
# @param a int整型
# @param b int整型
# @return int整型
#
class Solution:

    def gcd(self, a: int, b: int) -> int:
        # write code here

        if a < b: a, b = b, a
        return a if b == 0 else self.gcd(b, a % b)
