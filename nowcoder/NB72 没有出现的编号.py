'''

描述
在一个农场里，有n头牛，每头牛都有一个唯一的编号，编号是一个整数，可能是正数，也可能是负数。农场的主人想知道，如果把所有牛的编号都看作是一个大的整数数组，那么这个数组中没有出现的最小的正整数是多少。同时，农场主人还想知道，这个数组中的最大负数是多少。如果数组中没有负数，那么最大负数就是0。

由于牛群数量较多，农场主人难以计算，他需要你的帮忙。

示例1
输入：
[1,2,0]
复制
返回值：
[3,0]
复制
示例2
输入：
[3,4,-1,1]
复制
返回值：
[2,-1]
复制
备注：
1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1

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

    def findMissingAndMaxNegative(self, nums: List[int]) -> List[int]:
        # write code here

        max_neg = 0
        for i in nums:
            if i >= 0: continue
            if max_neg == 0: max_neg = i
            else: max_neg = max(max_neg, i)

        nums = [i for i in nums if i > 0]
        if not nums: return [1, max_neg]
        ma = max(nums)

        flags = [False for _ in range(ma + 1)]
        for i in nums:
            flags[i] = True

        res = None
        for i, v in enumerate(flags):
            if i == 0: continue
            if not v:
                res = i
                break
        if res == None:
            res = i + 1

        return [res, max_neg]
