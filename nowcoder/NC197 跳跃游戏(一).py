'''

描述
给定一个非负整数数组nums，假定最开始处于下标为0的位置，数组里面的每个元素代表下一跳能够跳跃的最大长度。如果能够跳到数组最后一个位置，则返回true，否则返回false。
数据范围:
1
<
=
�
�
�
�
.
�
�
�
�
�
ℎ
<
=
2
×
1
0
5
1<=nums.length<=2×10 
5
 
0
<
=
�
�
�
�
[
�
]
<
=
1
0
5
0<=nums[i]<=10 
5
 
示例1
输入：
[2,1,3,3,0,0,100]
复制
返回值：
true
复制
说明：
首先位于nums[0]=2，然后可以跳2步，到nums[2]=3的位置，再跳到nums[3]=3的位置，再直接跳到nums[6]=100，可以跳到最后，返回true   
示例2
输入：
[2,1,3,2,0,0,100]
复制
返回值：
false
复制
说明：
无论怎么样，都跳不到nums[6]=100的位置   

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @return bool布尔型
#
class Solution:

    def canJump(self, nums: List[int]) -> bool:
        # write code here

        n = len(nums)
        if n == 1: return True

        maxr = 0 + nums[0]
        for i in range(n - 1):
            if i > maxr: break
            x = i + nums[i]
            maxr = max(maxr, x)
            if maxr >= n - 1: return True
        return False
