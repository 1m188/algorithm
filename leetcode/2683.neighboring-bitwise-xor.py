#
# @lc app=leetcode.cn id=2683 lang=python3
# @lcpr version=30204
#
# [2683] 相邻值的按位异或
#
# https://leetcode.cn/problems/neighboring-bitwise-xor/description/
#
# algorithms
# Medium (80.40%)
# Likes:    45
# Dislikes: 0
# Total Accepted:    22.2K
# Total Submissions: 27.7K
# Testcase Example:  '[1,1,0]'
#
# 下标从 0 开始、长度为 n 的数组 derived 是由同样长度为 n 的原始 二进制数组 original 通过计算相邻值的
# 按位异或（⊕）派生而来。
#
# 特别地，对于范围 [0, n - 1] 内的每个下标 i ：
#
#
# 如果 i = n - 1 ，那么 derived[i] = original[i] ⊕ original[0]
# 否则 derived[i] = original[i] ⊕ original[i + 1]
#
#
# 给你一个数组 derived ，请判断是否存在一个能够派生得到 derived 的 有效原始二进制数组 original 。
#
# 如果存在满足要求的原始二进制数组，返回 true ；否则，返回 false 。
#
#
# 二进制数组是仅由 0 和 1 组成的数组。
#
#
#
#
# 示例 1：
#
# 输入：derived = [1,1,0]
# 输出：true
# 解释：能够派生得到 [1,1,0] 的有效原始二进制数组是 [0,1,0] ：
# derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1
# derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
# derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
#
#
# 示例 2：
#
# 输入：derived = [1,1]
# 输出：true
# 解释：能够派生得到 [1,1] 的有效原始二进制数组是 [0,1] ：
# derived[0] = original[0] ⊕ original[1] = 1
# derived[1] = original[1] ⊕ original[0] = 1
#
#
# 示例 3：
#
# 输入：derived = [1,0]
# 输出：false
# 解释：不存在能够派生得到 [1,0] 的有效原始二进制数组。
#
#
#
#
# 提示：
#
#
# n == derived.length
# 1 <= n <= 10^5
# derived 中的值不是 0 就是 1 。
#
#
#

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def doesValidArrayExist(self, derived: List[int]) -> bool:

        n = len(derived)
        start1, start2 = 0, 0
        left1, left2 = 0, 0

        if derived[0] == 0:
            start1, left1 = 0, 0
            start2, left2 = 1, 1
        else:
            start1, left1 = 0, 1
            start2, left2 = 1, 0

        for i in range(1, n):
            left1 ^= derived[i]
            left2 ^= derived[i]

        return left1 == start1 or left2 == start2


# @lc code=end

#
# @lcpr case=start
# [1,1,0]\n
# @lcpr case=end

# @lcpr case=start
# [1,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,0]\n
# @lcpr case=end

#
