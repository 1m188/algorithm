#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#
# https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (41.22%)
# Likes:    5251
# Dislikes: 0
# Total Accepted:    663K
# Total Submissions: 1.6M
# Testcase Example:  '[1,3]\n[2]'
#
# 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
#
# 算法的时间复杂度应该为 O(log (m+n)) 。
#
#
#
# 示例 1：
#
#
# 输入：nums1 = [1,3], nums2 = [2]
# 输出：2.00000
# 解释：合并数组 = [1,2,3] ，中位数 2
#
#
# 示例 2：
#
#
# 输入：nums1 = [1,2], nums2 = [3,4]
# 输出：2.50000
# 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
#
#
#
#
#
#
# 提示：
#
#
# nums1.length == m
# nums2.length == n
# 0 <= m <= 1000
# 0 <= n <= 1000
# 1 <= m + n <= 2000
# -10^6 <= nums1[i], nums2[i] <= 10^6
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        m, n = len(nums1), len(nums2)

        MAX = 10**6 + 1
        MIN = -10**6 - 1

        num = int((m + n) / 2)
        n1, n2 = None, None
        while nums1 and nums2 and num:
            if nums1[0] < nums2[0]:
                n1 = nums1.pop(0)
            else:
                n2 = nums2.pop(0)
            num -= 1
        while num and nums1:
            n1 = nums1.pop(0)
            num -= 1
        while num and nums2:
            n2 = nums2.pop(0)
            num -= 1

        if (m + n) % 2:
            if nums1 and nums2:
                return min(nums1[0], nums2[0])
            else:
                return nums1[0] if nums1 else nums2[0]
        else:
            li = []
            li.append(nums1[0] if nums1 else MAX)
            li.append(nums2[0] if nums2 else MAX)
            li.append(n1 if n1 is not None else MIN)
            li.append(n2 if n2 is not None else MIN)
            li.sort()
            return (li[1] + li[2]) / 2


# @lc code=end
