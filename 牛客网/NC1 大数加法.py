'''
描述
以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。

数据范围：s.length,t.length \le 100000s.length,t.length≤100000，字符串仅由'0'~‘9’构成
要求：时间复杂度 O(n)O(n)
示例1
输入：
"1","99"
复制
返回值：
"100"
复制
说明：
1+99=100       
示例2
输入：
"114514",""
复制
返回值：
"114514"
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 计算两个数之和
# @param s string字符串 表示第一个整数
# @param t string字符串 表示第二个整数
# @return string字符串
#
class Solution:

    def solve(self, s: str, t: str) -> str:
        # write code here

        if not s and not t: return '0'
        if not s: return t
        if not t: return s

        res = ''
        p = 0
        i = len(s) - 1
        j = len(t) - 1
        while i >= 0 and j >= 0:
            x = int(s[i]) + int(t[j]) + p
            res = str(x % 10) + res
            p = x // 10
            i -= 1
            j -= 1
        while i >= 0:
            x = int(s[i]) + p
            res = str(x % 10) + res
            p = x // 10
            i -= 1
        while j >= 0:
            x = int(t[j]) + p
            res = str(x % 10) + res
            p = x // 10
            j -= 1
        if p: res = str(p) + res
        return res
