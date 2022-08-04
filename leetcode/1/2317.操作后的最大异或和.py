#
# @lc app=leetcode.cn id=2317 lang=python3
#
# [2317] 操作后的最大异或和
#
# https://leetcode.cn/problems/maximum-xor-after-operations/description/
#
# algorithms
# Medium (83.75%)
# Likes:    10
# Dislikes: 0
# Total Accepted:    3.6K
# Total Submissions: 4.3K
# Testcase Example:  '[3,2,4,6]'
#
# 给你一个下标从 0 开始的整数数组 nums 。一次操作中，选择 任意 非负整数 x 和一个下标 i ，更新 nums[i] 为 nums[i] AND
# (nums[i] XOR x) 。
#
# 注意，AND 是逐位与运算，XOR 是逐位异或运算。
#
# 请你执行 任意次 更新操作，并返回 nums 中所有元素 最大 逐位异或和。
#
#
#
# 示例 1：
#
# 输入：nums = [3,2,4,6]
# 输出：7
# 解释：选择 x = 4 和 i = 3 进行操作，num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2 。
# 现在，nums = [3, 2, 4, 2] 且所有元素逐位异或得到 3 XOR 2 XOR 4 XOR 2 = 7 。
# 可知 7 是能得到的最大逐位异或和。
# 注意，其他操作可能也能得到逐位异或和 7 。
#
# 示例 2：
#
# 输入：nums = [1,2,3,9,2]
# 输出：11
# 解释：执行 0 次操作。
# 所有元素的逐位异或和为 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11 。
# 可知 11 是能得到的最大逐位异或和。
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# 0 <= nums[i] <= 10^8
#
#
#
'''
提示 1
\textit{nums}[i]nums[i] 逐位异或任意非负整数，相当于把 \textit{nums}[i]nums[i] 修改为任意非负整数。

提示 2
\textit{nums}[i]nums[i] 逐位与任意非负整数，相当于把 \textit{nums}[i]nums[i] 的某些比特位的值，由 11 修改为 00，但是不能由 00 修改为 11。

提示 3
考虑逐位构造出 \textit{nums}nums 的最大逐位异或和。如果 \textit{nums}nums 在某个比特位上有奇数个 11，那么这个比特位异或和的结果就是 11。根据提示 2，只需要保证 \textit{nums}nums 在这个比特位上有至少一个 11 即可，在这个比特位上我们可以只保留一个 11，其余修改为 00。

提示 4
通过逐位或运算可以求出 \textit{nums}nums 在哪些比特位上有 11。

其结果亦是答案。
'''

from typing import List


# @lc code=start
class Solution:

    def maximumXOR(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            res |= i
        return res


# @lc code=end
