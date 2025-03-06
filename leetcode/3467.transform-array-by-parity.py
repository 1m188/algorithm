#
# @lc app=leetcode.cn id=3467 lang=python3
# @lcpr version=30204
#
# [3467] 将数组按照奇偶性转化
#
# https://leetcode.cn/problems/transform-array-by-parity/description/
#
# algorithms
# Easy (87.14%)
# Likes:    1
# Dislikes: 0
# Total Accepted:    2.3K
# Total Submissions: 2.7K
# Testcase Example:  '[4,3,2,1]'
#
# 给你一个整数数组 nums。请你按照以下顺序 依次 执行操作，转换 nums：
#
#
# 将每个偶数替换为 0。
# 将每个奇数替换为 1。
# 按 非递减 顺序排序修改后的数组。
#
#
# 执行完这些操作后，返回结果数组。
#
#
#
# 示例 1:
#
#
# 输入：nums = [4,3,2,1]
#
# 输出：[0,0,1,1]
#
# 解释：
#
#
# 将偶数（4 和 2）替换为 0，将奇数（3 和 1）替换为 1。现在，nums = [0, 1, 0, 1]。
# 按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1]。
#
#
#
# 示例 2:
#
#
# 输入：nums = [1,5,1,4,2]
#
# 输出：[0,0,1,1,1]
#
# 解释：
#
#
# 将偶数（4 和 2）替换为 0，将奇数（1, 5 和 1）替换为 1。现在，nums = [1, 1, 1, 0, 0]。
# 按非递减顺序排序 nums，得到 nums = [0, 0, 1, 1, 1]。
#
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 1000
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def transformArray(self, nums: List[int]) -> List[int]:
        zeros = 0
        n = len(nums)
        for x in nums:
            zeros += (x & 0x1 == 0)
        res = [0] * zeros + [1] * (n - zeros)
        return res


# @lc code=end

#
# @lcpr case=start
# [4,3,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,5,1,4,2]\n
# @lcpr case=end

#
