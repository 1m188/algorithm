#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#
# https://leetcode-cn.com/problems/jump-game/description/
#
# algorithms
# Medium (43.47%)
# Likes:    1748
# Dislikes: 0
# Total Accepted:    452.3K
# Total Submissions: 1M
# Testcase Example:  '[2,3,1,1,4]'
#
# 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
#
# 数组中的每个元素代表你在该位置可以跳跃的最大长度。
#
# 判断你是否能够到达最后一个下标。
#
#
#
# 示例 1：
#
#
# 输入：nums = [2,3,1,1,4]
# 输出：true
# 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
#
#
# 示例 2：
#
#
# 输入：nums = [3,2,1,0,4]
# 输出：false
# 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 3 * 10^4
# 0 <= nums[i] <= 10^5
#
#
#

from typing import List


# @lc code=start
class Solution:

    def canJump(self, nums: List[int]) -> bool:
        '''
        
        从最后一个往前看，看前面的某个位置是否能跳到当前位置，
        如果可以则修改当前位置，并且再次重复，
        直到当前能够达到最开始的位置，
        或者遍历完了之后都没办法到开始的位置
        
        '''

        i = len(nums) - 1

        while i > 0:
            f = True
            for j in range(1, i + 1):
                if nums[i - j] >= j:
                    f = False
                    i = i - j
                    break
            if f:
                break

        return True if i == 0 else False


# @lc code=end
