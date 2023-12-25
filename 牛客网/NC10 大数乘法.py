'''

描述
以字符串的形式读入两个数字，编写一个函数计算它们的乘积，以字符串形式返回。

数据范围： 读入的数字大小满足 
0
≤
�
≤
1
0
1000
0≤n≤10 
1000
 

要求：空间复杂度 
�
(
�
)
O(m)，时间复杂度 
�
(
�
2
)
O(m 
2
 )（假设m是n的长度）
示例1
输入：
"11","99"
复制
返回值：
"1089"
复制
说明：
11*99=1089 
示例2
输入：
"1","0"
复制
返回值：
"0"

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串 第一个整数
# @param t string字符串 第二个整数
# @return string字符串
#
class Solution:

    def solve(self, s: str, t: str) -> str:
        # write code here

        n = len(s) + len(t)

        li = []
        for i, v in enumerate(t[::-1]):
            x = self.mul_s(s, v)
            x += '0' * i
            l = n - len(x)
            if l > 0: x = '0' * l + x
            li.append(x)

        x = self.add(li)
        while x[0] == '0' and len(x) >= 2:
            x = x[1:]
        return x

    def mul_s(self, s: str, single: str) -> str:
        single = int(single)

        res = []
        op = 0
        for v in s[::-1]:
            x = int(v) * single + op
            res.insert(0, str(x % 10))
            op = x // 10
        if op != 0: res.insert(0, str(op))

        return ''.join(res)

    def add(self, nums: list[str]) -> str:
        lens = [len(x) for x in nums]
        len_max = max(lens)
        for i, v in enumerate(nums):
            if len(v) < len_max: nums[i] = (len_max - len(v)) * '0' + v

        res = []
        op = 0
        for i in range(len_max):
            idx = len_max - i - 1
            x = sum(int(num[idx]) for num in nums) + op
            res.insert(0, str(x % 10))
            op = x // 10
        if op != 0: res.insert(0, str(op))

        return ''.join(res)
