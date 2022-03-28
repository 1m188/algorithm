#
# @lc app=leetcode.cn id=1550 lang=python3
#
# [1550] 存在连续三个奇数的数组
#
# https://leetcode-cn.com/problems/three-consecutive-odds/description/
#
# algorithms
# Easy (65.59%)
# Likes:    15
# Dislikes: 0
# Total Accepted:    23.5K
# Total Submissions: 35.9K
# Testcase Example:  '[2,6,4,1]'
#
# 给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
# 输入：arr = [2,6,4,1]
# 输出：false
# 解释：不存在连续三个元素都是奇数的情况。
#
#
# 示例 2：
#
# 输入：arr = [1,2,34,3,4,5,7,23,12]
# 输出：true
# 解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。
#
#
#
#
# 提示：
#
#
# 1 <= arr.length <= 1000
# 1 <= arr[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def threeConsecutiveOdds(self, arr: List[int]) -> bool:

        # 最开始想到的连续三个的判断
        #
        # 但是这里的问题是，如果连续三个数不全是奇数，那么在下一次后移一个元素再次计算时，
        # 会有重复计算的情况
        #
        # for i in range(len(arr) - 2):
        #     if arr[i] % 2 and arr[i + 1] % 2 and arr[i + 2] % 2:
        #         return True
        # return False

        # 转化为字符串使用in的判断，python中或许会用kmp做优化？
        for i in range(len(arr)):
            arr[i] = str(arr[i] % 2)
        return '111' in ''.join(arr)


# @lc code=end
