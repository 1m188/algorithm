#
# @lc app=leetcode.cn id=2148 lang=python3
#
# [2148] 元素计数
#
# https://leetcode-cn.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/
#
# algorithms
# Easy (57.90%)
# Likes:    10
# Dislikes: 0
# Total Accepted:    8.6K
# Total Submissions: 14.9K
# Testcase Example:  '[11,7,2,15]'
#
# 给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。
#
#
#
# 示例 1：
#
#
# 输入：nums = [11,7,2,15]
# 输出：2
# 解释：元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
# 元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
# 总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
#
#
# 示例 2：
#
#
# 输入：nums = [-3,3,3,90]
# 输出：2
# 解释：元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
# 由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# -10^5 <= nums[i] <= 10^5
#
#
#

from typing import List


# @lc code=start
class Solution:

    def countElements(self, nums: List[int]) -> int:

        di = {}
        for i in nums:
            di[i] = di.get(i, 0) + 1

        if len(di) < 3: return 0

        di = list(di.items())
        di.sort(key=lambda x: x[0])
        di.pop()
        di.pop(0)

        ans = 0
        for _, count in di:
            ans += count

        return ans


# @lc code=end
