'''

描述
给定一个长度为 n 的字符串，请编写一个函数判断该字符串是否回文。如果是回文请返回true，否则返回false。

字符串回文指该字符串正序与其逆序逐字符一致。

数据范围：
0
<
�
≤
1000000
0<n≤1000000
要求：空间复杂度 
�
(
1
)
O(1)，时间复杂度 
�
(
�
)
O(n)
示例1
输入：
"absba"
复制
返回值：
true
复制
示例2
输入：
"ranko"
复制
返回值：
false
复制
示例3
输入：
"yamatomaya"
复制
返回值：
false
复制
示例4
输入：
"a"
复制
返回值：
true
复制
备注：
字符串长度不大于1000000，且仅由小写字母组成

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param str string字符串 待判断的字符串
# @return bool布尔型
#
class Solution:

    def judge(self, str: str) -> bool:
        # write code here

        n = len(str)
        left, right = 0, n - 1
        while left < right:
            if str[left] != str[right]: return False
            left += 1
            right -= 1
        return True
