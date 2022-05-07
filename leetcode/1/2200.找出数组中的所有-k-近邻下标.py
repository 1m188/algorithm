#
# @lc app=leetcode.cn id=2200 lang=python3
#
# [2200] 找出数组中的所有 K 近邻下标
#
# https://leetcode-cn.com/problems/find-all-k-distant-indices-in-an-array/description/
#
# algorithms
# Easy (51.51%)
# Likes:    8
# Dislikes: 0
# Total Accepted:    9.7K
# Total Submissions: 18.9K
# Testcase Example:  '[3,4,9,1,3,9,5]\n9\n1'
#
# 给你一个下标从 0 开始的整数数组 nums 和两个整数 key 和 k 。K 近邻下标 是 nums 中的一个下标 i ，并满足至少存在一个下标 j
# 使得 |i - j| <= k 且 nums[j] == key 。
#
# 以列表形式返回按 递增顺序 排序的所有 K 近邻下标。
#
#
#
# 示例 1：
#
#
# 输入：nums = [3,4,9,1,3,9,5], key = 9, k = 1
# 输出：[1,2,3,4,5,6]
# 解释：因此，nums[2] == key 且 nums[5] == key 。
# - 对下标 0 ，|0 - 2| > k 且 |0 - 5| > k ，所以不存在 j 使得 |0 - j| <= k 且 nums[j] == key
# 。所以 0 不是一个 K 近邻下标。
# - 对下标 1 ，|1 - 2| <= k 且 nums[2] == key ，所以 1 是一个 K 近邻下标。
# - 对下标 2 ，|2 - 2| <= k 且 nums[2] == key ，所以 2 是一个 K 近邻下标。
# - 对下标 3 ，|3 - 2| <= k 且 nums[2] == key ，所以 3 是一个 K 近邻下标。
# - 对下标 4 ，|4 - 5| <= k 且 nums[5] == key ，所以 4 是一个 K 近邻下标。
# - 对下标 5 ，|5 - 5| <= k 且 nums[5] == key ，所以 5 是一个 K 近邻下标。
# - 对下标 6 ，|6 - 5| <= k 且 nums[5] == key ，所以 6 是一个 K 近邻下标。
# 因此，按递增顺序返回 [1,2,3,4,5,6] 。
#
#
# 示例 2：
#
#
# 输入：nums = [2,2,2,2,2], key = 2, k = 2
# 输出：[0,1,2,3,4]
# 解释：对 nums 的所有下标 i ，总存在某个下标 j 使得 |i - j| <= k 且 nums[j] == key ，所以每个下标都是一个 K
# 近邻下标。
# 因此，返回 [0,1,2,3,4] 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 1000
# key 是数组 nums 中的一个整数
# 1 <= k <= nums.length
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findKDistantIndices(self, nums: List[int], key: int,
                            k: int) -> List[int]:

        # 对每个找到的key记录其满足要求的索引
        # 最后去重，因为索引范围有重复的
        # 因为去重用的是set，所以最后还要排序
        # 有点慢
        # ans = set()

        # for i in range(len(nums)):
        #     if nums[i] == key:
        #         for j in range(i, min(i + k + 1, len(nums))):
        #             ans.add(j)
        #         for j in range(i - 1, max(i - k - 1, -1), -1):
        #             ans.add(j)

        # return sorted(ans)

        # 更快
        # 保存了bd边界变量，去掉重复的索引范围，这样就可以直接用列表储存结果
        # 不必再去重和排序
        ans = []
        bd = 0

        for i in range(len(nums)):
            if nums[i] == key:
                for j in range(max(i - k, bd), i):
                    ans.append(j)
                for j in range(max(i, bd), min(len(nums), i + k + 1)):
                    ans.append(j)
                bd = i + k + 1

        return ans


# @lc code=end
