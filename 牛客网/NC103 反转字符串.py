'''
描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

数据范围： 0 \le n \le 10000≤n≤1000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
"abcd"
复制
返回值：
"dcba"
复制
示例2
输入：
""
复制
返回值：
""
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 反转字符串
# @param str string字符串
# @return string字符串
#
class Solution:

    def solve(self, str: str) -> str:
        # write code here
        return ''.join(reversed(list(str)))