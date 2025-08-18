#
# @lc app=leetcode.cn id=3591 lang=python3
# @lcpr version=30204
#
# [3591] 检查元素频次是否为质数
#
# https://leetcode.cn/problems/check-if-any-element-has-prime-frequency/description/
#
# algorithms
# Easy (60.79%)
# Likes:    1
# Dislikes: 0
# Total Accepted:    3.8K
# Total Submissions: 6.2K
# Testcase Example:  '[1,2,3,4,5,4]'
#
# 给你一个整数数组 nums。
#
# 如果数组中任一元素的 频次 是 质数，返回 true；否则，返回 false。
#
# 元素 x 的 频次 是它在数组中出现的次数。
#
# 质数是一个大于 1 的自然数，并且只有两个因数：1 和它本身。
#
#
#
# 示例 1：
#
#
# 输入： nums = [1,2,3,4,5,4]
#
# 输出： true
#
# 解释：
#
# 数字 4 的频次是 2，而 2 是质数。
#
#
# 示例 2：
#
#
# 输入： nums = [1,2,3,4,5]
#
# 输出： false
#
# 解释：
#
# 所有元素的频次都是 1。
#
#
# 示例 3：
#
#
# 输入： nums = [2,2,2,4,4]
#
# 输出： true
#
# 解释：
#
# 数字 2 和 4 的频次都是质数。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 100
#
#
#

from typing import List
from collections import Counter

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def checkPrimeFrequency(self, nums: List[int]) -> bool:

        def isPrime(n):
            if n < 2: return False
            if n == 2: return True
            if n & 0x1 == 0: return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0: return False
            return True

        return any(isPrime(v) for v in Counter(nums).values())


# @lc code=end

#
# @lcpr case=start
# [1,2,3,4,5,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,4,4]\n
# @lcpr case=end

#
