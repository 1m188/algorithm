'''
描述
给你一个大小为 n 的字符串数组 strs ，其中包含n个字符串 , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。

数据范围： 
0
≤
n
≤
5000
0≤n≤5000， 
0
≤
l
e
n
(
s
t
r
s
i
)
≤
5000
0≤len(strs 
i
​
 )≤5000
进阶：空间复杂度 
O
(
1
)
O(1)，时间复杂度 
O
(
n
∗
l
e
n
)
O(n∗len)
示例1
输入：
["abca","abc","abca","abc","abcc"]
复制
返回值：
"abc"
复制
示例2
输入：
["abc"]
复制
返回值：
"abc"
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param strs string字符串一维数组
# @return string字符串
#
class Solution:

    def longestCommonPrefix(self, strs: List[str]) -> str:
        # write code here

        if len(strs) == 0: return ''

        res = strs[0]
        for i in range(1, len(strs)):
            tar = strs[i]
            index = 0
            while index < len(res) and index < len(tar):
                if res[index] != tar[index]: break
                index += 1
            if index < len(res): res = res[:index]
        return res
