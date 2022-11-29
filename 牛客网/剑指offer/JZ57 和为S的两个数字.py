'''
描述
输入一个升序数组 array 和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，
返回任意一组即可，如果无法找出这样的数字，返回一个空数组即可。

数据范围: 0 \le len(array) \le 10^5 ​​\0≤len(array)≤10 
5
 ​​ ， 1 \le array[i] \le 10^6 \1≤array[i]≤10 
6
  
示例1
输入：
[1,2,4,7,11,15],15
复制
返回值：
[4,11]
复制
说明：
返回[4,11]或者[11,4]都是可以的       
示例2
输入：
[1,5,11],10
复制
返回值：
[]
复制
说明：
不存在，返回空数组     
示例3
输入：
[1,2,3,4],5
复制
返回值：
[1,4]
复制
说明：
返回[1,4],[4,1],[2,3],[3,2]都是可以的   
示例4
输入：
[1,2,2,4],4
复制
返回值：
[2,2]
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param array int整型一维数组
# @param sum int整型
# @return int整型一维数组
#
class Solution:

    def FindNumbersWithSum(self, array: List[int], sum: int) -> List[int]:
        # write code here

        i1, i2 = 0, len(array) - 1
        while i1 < i2:
            x = array[i1] + array[i2]
            if x == sum: return [array[i1], array[i2]]
            elif x > sum: i2 -= 1
            else: i1 += 1
        return []
