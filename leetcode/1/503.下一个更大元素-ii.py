#
# @lc app=leetcode.cn id=503 lang=python3
#
# [503] 下一个更大元素 II
#
# https://leetcode-cn.com/problems/next-greater-element-ii/description/
#
# algorithms
# Medium (56.64%)
# Likes:    181
# Dislikes: 0
# Total Accepted:    28.7K
# Total Submissions: 50.4K
# Testcase Example:  '[1,2,1]'
#
# 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
# 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
#
# 示例 1:
#
#
# 输入: [1,2,1]
# 输出: [2,-1,2]
# 解释: 第一个 1 的下一个更大的数是 2；
# 数字 2 找不到下一个更大的数；
# 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
#
#
# 注意: 输入数组的长度不会超过 10000。
#
#

from typing import List


# @lc code=start
class Solution:
    def travel(self, nums: List[int]) -> List[int]:
        '''
        遍历查询
        '''
        res = []
        for i in range(len(nums)):
            r = None
            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    r = nums[j]
                    break
            if r is None:
                for j in range(i):
                    if nums[j] > nums[i]:
                        r = nums[j]
                        break
            res.append(r if r is not None else -1)
        return res

    def sst(self, nums: List[int]) -> List[int]:
        '''
        单调栈
        '''
        res = [-1] * len(nums)
        st = []
        for _ in range(2):
            for i in range(len(nums)):
                while st and nums[st[-1]] < nums[i]:
                    res[st.pop()] = nums[i]
                st.append(i)
        return res

    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # return self.travel(nums)
        return self.sst(nums)


# @lc code=end
