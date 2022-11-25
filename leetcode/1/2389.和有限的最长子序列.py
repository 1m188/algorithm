#
# @lc app=leetcode.cn id=2389 lang=python3
#
# [2389] 和有限的最长子序列
#
# https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
#
# algorithms
# Easy (66.42%)
# Likes:    16
# Dislikes: 0
# Total Accepted:    9.6K
# Total Submissions: 14.5K
# Testcase Example:  '[4,5,2,1]\n[3,10,21]'
#
# 给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
#
# 返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大
# 长度  。
#
# 子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
#
#
#
# 示例 1：
#
#
# 输入：nums = [4,5,2,1], queries = [3,10,21]
# 输出：[2,3,4]
# 解释：queries 对应的 answer 如下：
# - 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
# - 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
# - 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
#
#
# 示例 2：
#
#
# 输入：nums = [2,3,4,5], queries = [1]
# 输出：[0]
# 解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
#
#
#
# 提示：
#
#
# n == nums.length
# m == queries.length
# 1 <= n, m <= 1000
# 1 <= nums[i], queries[i] <= 10^6
#
#
#

from typing import List


# @lc code=start
class Solution:

    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        '''
        子序列不要求顺序，甚至可以删除中间的数，那么可以直接排序，然后利用顺序递增\n
        来求其大小，注意记录queries里的数的索引
        '''

        n, m = len(nums), len(queries)

        nums.sort()
        queries_li = [[i, v] for i, v in enumerate(queries)]
        queries_li.sort(key=lambda x: x[1])
        res = [0 for _ in range(m)]

        nums_sum = 0
        idx = 0
        cnt = 0
        for v in nums:
            nums_sum += v
            while idx < m:
                if nums_sum <= queries_li[idx][1]: break
                else:
                    res[queries_li[idx][0]] = cnt
                    idx += 1
            if idx >= m: break
            cnt += 1
        while idx < m:
            res[queries_li[idx][0]] = cnt
            idx += 1

        return res


# @lc code=end
