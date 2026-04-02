"""
描述
给定一个正整数，请你判断这个数是不是快乐数。
快乐数：对于一个正整数，每次把他替换为他每个位置上的数字的平方和，如果这个数能变为 1 则是快乐数，如果不可能变成 1 则不是快乐数。
例如：正整数 19
转换过程为 1*1+9*9=82 , 8*8+2*2=68，6*6+8*8=100，1*1+0*0+0*0=1 ，所以他是快乐数。

数据范围：输入的正整数满足
1
≤
n
≤
1
0
9

1≤n≤10
9

示例1
输入：
19
复制
返回值：
true
复制
示例2
输入：
111
复制
返回值：
false
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param n int整型
# @return bool布尔型
#
class Solution:
    def happynum(self, n: int) -> bool:
        # write code here

        def get_next(n: int) -> int:
            ans = 0
            while n:
                ans += (n % 10) ** 2
                n //= 10
            return ans

        set_ = set()
        while n != 1:
            if n in set_:
                return False
            set_.add(n)
            n = get_next(n)
        return True
