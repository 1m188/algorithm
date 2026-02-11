#
# @lc app=leetcode.cn id=面试题 08.05 lang=python3
# @lcpr version=30204
#
# [面试题 08.05] 递归乘法
#
# https://leetcode.cn/problems/recursive-mulitply-lcci/description/
#
# LCCI
# Medium (65.21%)
# Likes:    123
# Dislikes: 0
# Total Accepted:    61.9K
# Total Submissions: 94.9K
# Testcase Example:  '1\n10'
#
# 递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。
#
# 示例 1：
#
# ⁠输入：A = 1, B = 10
# ⁠输出：10
#
#
# 示例 2：
#
# ⁠输入：A = 3, B = 4
# ⁠输出：12
#
#
# 提示：
#
#
# 保证乘法范围不会溢出
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def multiply(self, A: int, B: int) -> int:

        def mul(max_val: int, min_val: int) -> int:
            if min_val == 1:
                return max_val
            return mul(max_val << 1, min_val >> 1) + (
                0 if min_val & 0x1 == 0 else max_val
            )

        return mul(max(A, B), min(A, B))


# @lc code=end


#
# @lcpr case=start
# 1\n10\n
# @lcpr case=end

# @lcpr case=start
# 3\n4\n
# @lcpr case=end

#
