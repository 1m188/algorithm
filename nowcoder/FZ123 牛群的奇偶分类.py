'''

描述
农场主在观察他的牛群时，发现牛群的数量具有奇偶性规律。为了方便管理，农场主想要把偶数数量的牛群放在前半部分，把奇数数量的牛群放在后半部分，同时保持各个元素的相对位置不变。现在给你一个整数数组 nums，表示农场中每个牛群的数量。请实现一个函数，调整数组中数字的顺序，使得所有偶数在数组的前半部分，所有奇数在数组的后半部分。
示例1
输入：
[1,2,3,4]
复制
返回值：
[2,4,1,3]
复制
示例2
输入：
[1,5,3,7,9,2,4,6,8,10]
复制
返回值：
[2,4,6,8,10,1,5,3,7,9]
复制
备注：
0 <= nums.length <= 20,000
0 <= nums[i] <= 10,000

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @return int整型一维数组
#
class Solution:

    def reorderCows(self, nums: List[int]) -> List[int]:
        # write code here

        a, b = [], []
        for i in nums:
            if i % 2 == 0: a.append(i)
            else: b.append(i)
        return a + b
