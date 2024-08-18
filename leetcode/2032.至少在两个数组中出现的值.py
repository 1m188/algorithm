#
# @lc app=leetcode.cn id=2032 lang=python3
#
# [2032] 至少在两个数组中出现的值
#
# https://leetcode.cn/problems/two-out-of-three/description/
#
# algorithms
# Easy (72.95%)
# Likes:    84
# Dislikes: 0
# Total Accepted:    33.5K
# Total Submissions: 46K
# Testcase Example:  '[1,1,3,2]\n[2,3]\n[3]'
#
# 给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个
# 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
#
#
# 示例 1：
#
#
# 输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
# 输出：[3,2]
# 解释：至少在两个数组中出现的所有值为：
# - 3 ，在全部三个数组中都出现过。
# - 2 ，在数组 nums1 和 nums2 中出现过。
#
#
# 示例 2：
#
#
# 输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
# 输出：[2,3,1]
# 解释：至少在两个数组中出现的所有值为：
# - 2 ，在数组 nums2 和 nums3 中出现过。
# - 3 ，在数组 nums1 和 nums2 中出现过。
# - 1 ，在数组 nums1 和 nums3 中出现过。
#
#
# 示例 3：
#
#
# 输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
# 输出：[]
# 解释：不存在至少在两个数组中出现的值。
#
#
#
#
# 提示：
#
#
# 1 <= nums1.length, nums2.length, nums3.length <= 100
# 1 <= nums1[i], nums2[j], nums3[k] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:

    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:

        se1 = set(nums1)
        se2 = set(nums2)
        se3 = set(nums3)

        se = set()
        for i in se1:
            if i in se2: se.add(i)
        for i in se2:
            if i in se3: se.add(i)
        for i in se3:
            if i in se1: se.add(i)

        return list(se)


# @lc code=end
