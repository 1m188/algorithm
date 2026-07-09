#
# @lc app=leetcode.cn id=930 lang=python3
# @lcpr version=30204
#
# [930] 和相同的二元子数组
#
# https://leetcode.cn/problems/binary-subarrays-with-sum/description/
#
# algorithms
# Medium (60.52%)
# Likes:    386
# Dislikes: 0
# Total Accepted:    80.5K
# Total Submissions: 133K
# Testcase Example:  '[1,0,1,0,1]\n2'
#
# 给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
#
# 子数组 是数组的一段连续部分。
#
#
#
# 示例 1：
#
# 输入：nums = [1,0,1,0,1], goal = 2
# 输出：4
# 解释：
# 有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
#
#
# 示例 2：
#
# 输入：nums = [0,0,0,0,0], goal = 0
# 输出：15
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 3 * 10^4
# nums[i] 不是 0 就是 1
# 0 <= goal <= nums.length
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        """
        前缀和 + 哈希表

        核心思路：
        - 设 prefix[i] = nums[0..i-1] 的和
        - 子数组 [l..r) 的和 = prefix[r] - prefix[l] = goal
        - 即 prefix[l] = prefix[r] - goal
        - 遍历 r，用哈希表统计已出现的前缀和次数，累加匹配数
        """
        from collections import defaultdict

        cnt = defaultdict(int)
        cnt[0] = 1  # 空前缀和为 0

        ans = 0
        prefix = 0
        for x in nums:
            prefix += x
            ans += cnt[prefix - goal]
            cnt[prefix] += 1

        return ans


# @lc code=end


#
# @lcpr case=start
# [1,0,1,0,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0,0,0]\n0\n
# @lcpr case=end

#
