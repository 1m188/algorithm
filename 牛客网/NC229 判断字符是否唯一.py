'''

描述
给定一个字符串，请你判断其中每个字符是否全都不同。

数据范围：字符串长度满足 
1
≤
�
≤
100
 
1≤n≤100 
示例1
输入：
"nowcoder"
复制
返回值：
false
复制
说明：
 "nowcoder" 中 'o' 出现了两次，因此返回 false 
示例2
输入：
"nowcOder"
复制
返回值：
true
复制
说明：
每个字符都只出现了一次 

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param str string字符串
# @return bool布尔型
#
class Solution:

    def isUnique(self, str: str) -> bool:
        # write code here

        return len(str) == len(set(str))
