#
# @lc app=leetcode.cn id=3769 lang=python3
# @lcpr version=30204
#
# [3769] 二进制反射排序
#
# https://leetcode.cn/problems/sort-integers-by-binary-reflection/description/
#
# algorithms
# Easy (63.18%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    3.4K
# Total Submissions: 5.4K
# Testcase Example:  '[4,5,4]'
#
# 给你一个整数数组 nums。
#
# 二进制反射 是对一个 正整数 的二进制表示按顺序反转（忽略前导零）后，将反转得到的二进制数转为十进制的结果。
#
# 请按每个元素的二进制反射值的 升序 对数组进行排序。如果两个不同的数字具有相同的二进制反射值，则 较小 的原始数字应排在前面。
#
# 返回排序后的数组。
#
#
#
# 示例 1：
#
#
# 输入： nums = [4,5,4]
#
# 输出： [4,4,5]
#
# 解释：
#
# 二进制反射值为：
#
#
# 4 -> (二进制) 100 -> (反转) 001 -> 1
# 5 -> (二进制) 101 -> (反转) 101 -> 5
# 4 -> (二进制) 100 -> (反转) 001 -> 1
#
# 根据反射值排序为 [4, 4, 5]。
#
# 示例 2：
#
#
# 输入： nums = [3,6,5,8]
#
# 输出： [8,3,6,5]
#
# 解释：
#
# 二进制反射值为：
#
#
# 3 -> (二进制) 11 -> (反转) 11 -> 3
# 6 -> (二进制) 110 -> (反转) 011 -> 3
# 5 -> (二进制) 101 -> (反转) 101 -> 5
# 8 -> (二进制) 1000 -> (反转) 0001 -> 1
#
# 根据反射值排序为 [8, 3, 6, 5]。
# 注意，3 和 6 的反射值相同，因此需要按原始值的升序排列。
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 10^9
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def sortByReflection(self, nums: List[int]) -> List[int]:

        def convert(num: int) -> int:
            return int(bin(num)[2:][::-1], 2)

        nums = [(num, convert(num)) for num in nums]
        nums.sort(key=lambda x: (x[1], x[0]))

        return [num for num, _ in nums]


# @lc code=end


#
# @lcpr case=start
# [4,5,4]\n
# @lcpr case=end

# @lcpr case=start
# [3,6,5,8]\n
# @lcpr case=end

#
