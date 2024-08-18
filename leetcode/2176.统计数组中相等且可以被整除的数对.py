#
# @lc app=leetcode.cn id=2176 lang=python3
#
# [2176] 统计数组中相等且可以被整除的数对
#
# https://leetcode-cn.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
#
# algorithms
# Easy (80.92%)
# Likes:    6
# Dislikes: 0
# Total Accepted:    6.5K
# Total Submissions: 8.1K
# Testcase Example:  '[3,1,2,2,2,1,3]\n2'
#
# 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k ，请你返回满足 0 <= i < j < n ，nums[i] ==
# nums[j] 且 (i * j) 能被 k 整除的数对 (i, j) 的 数目 。
#
#
#
# 示例 1：
#
# 输入：nums = [3,1,2,2,2,1,3], k = 2
# 输出：4
# 解释：
# 总共有 4 对数符合所有要求：
# - nums[0] == nums[6] 且 0 * 6 == 0 ，能被 2 整除。
# - nums[2] == nums[3] 且 2 * 3 == 6 ，能被 2 整除。
# - nums[2] == nums[4] 且 2 * 4 == 8 ，能被 2 整除。
# - nums[3] == nums[4] 且 3 * 4 == 12 ，能被 2 整除。
#
#
# 示例 2：
#
# 输入：nums = [1,2,3,4], k = 1
# 输出：0
# 解释：由于数组中没有重复数值，所以没有数对 (i,j) 符合所有要求。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i], k <= 100
#
#
#

from typing import Dict, List


# @lc code=start
class Solution:

    def countPairs(self, nums: List[int], k: int) -> int:

        # 暴力
        # if len(set(nums)) == len(nums): return 0

        # ans = 0

        # for i in range(len(nums)):
        #     for j in range(i + 1, len(nums)):
        #         ans += int(nums[i] == nums[j] and i * j % k == 0)

        # return ans

        # 快很多
        # 先把所有相同元素的索引记录下来
        # 然后对于所有索引数目>1的部分，找出索引列表中 i * j % k == 0 的数目
        di: Dict[int, List[int]] = {}
        for i in range(len(nums)):
            if nums[i] in di: di[nums[i]].append(i)
            else: di[nums[i]] = [i]

        di = [v for _, v in di.items() if len(v) > 1]

        ans = 0
        # 这里虽然有三重循环，但由于数据量比上面暴力的少很多，所以反而更快
        for li in di:
            for i in range(len(li)):
                for j in range(i + 1, len(li)):
                    ans += int(li[i] * li[j] % k == 0)
        return ans


# @lc code=end
