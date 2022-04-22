#
# @lc app=leetcode.cn id=477 lang=python3
#
# [477] 汉明距离总和
#
# https://leetcode-cn.com/problems/total-hamming-distance/description/
#
# algorithms
# Medium (60.43%)
# Likes:    251
# Dislikes: 0
# Total Accepted:    41.4K
# Total Submissions: 68.5K
# Testcase Example:  '[4,14,2]'
#
# 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
#
# 给你一个整数数组 nums，请你计算并返回 nums 中任意两个数之间 汉明距离的总和 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [4,14,2]
# 输出：6
# 解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
# 所以答案为：
# HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 +
# 2 + 2 = 6
#
#
# 示例 2：
#
#
# 输入：nums = [4,14,4]
# 输出：4
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^4
# 0 <= nums[i] <= 10^9
# 给定输入的对应答案符合 32-bit 整数范围
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''
    对于每一位考虑

    数组中的数有上限 不妨考虑每个数0-29位的情况

    假设数组中有n个数 其中有c个数在当前位是1 另外n-c个数在当前位就是0

    对于这c个数其和另外的位上为0的数的汉明距离之和为c*(n-c)

    而这个距离同样也是另外位上为0的数和这些位上为1的数的汉明距离之和
    
    事实上 这里把数分为两种 一种是当前位是0的 一种是当前位是1的
    
    计算这两种数的汉明距离之和

    遍历整个数组  其时间复杂度应该为O(30*n)

    比两重遍历的O(n^2)要好多了
    '''

    def totalHammingDistance(self, nums: List[int]) -> int:

        res = 0
        for i in range(30):
            c = 0
            for n in nums:
                c += (n >> i) & 1  # 将当前位的数目取出来，加到结果中去
            res += c * (len(nums) - c)

        return res


# @lc code=end
