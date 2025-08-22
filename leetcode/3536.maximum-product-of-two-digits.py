#
# @lc app=leetcode.cn id=3536 lang=python3
# @lcpr version=30204
#
# [3536] 两个数字的最大乘积
#
# https://leetcode.cn/problems/maximum-product-of-two-digits/description/
#
# algorithms
# Easy (80.20%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    4K
# Total Submissions: 4.9K
# Testcase Example:  '31'
#
# 给定一个正整数 n。
#
# 返回 任意两位数字 相乘所得的 最大 乘积。
#
# 注意：如果某个数字在 n 中出现多次，你可以多次使用该数字。
#
#
#
# 示例 1：
#
#
# 输入： n = 31
#
# 输出： 3
#
# 解释：
#
#
# n 的数字是 [3, 1]。
# 任意两位数字相乘的结果为：3 * 1 = 3。
# 最大乘积为 3。
#
#
#
# 示例 2：
#
#
# 输入： n = 22
#
# 输出： 4
#
# 解释：
#
#
# n 的数字是 [2, 2]。
# 任意两位数字相乘的结果为：2 * 2 = 4。
# 最大乘积为 4。
#
#
#
# 示例 3：
#
#
# 输入： n = 124
#
# 输出： 8
#
# 解释：
#
#
# n 的数字是 [1, 2, 4]。
# 任意两位数字相乘的结果为：1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8。
# 最大乘积为 8。
#
#
#
#
#
# 提示：
#
#
# 10 <= n <= 10^9
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def maxProduct(self, n: int) -> int:

        a, b = 0, 0
        for i in str(n):
            i = int(i)
            if i > a:
                a, b = i, a
            elif i > b:
                b = i
        return a * b


# @lc code=end

#
# @lcpr case=start
# 31\n
# @lcpr case=end

# @lcpr case=start
# 22\n
# @lcpr case=end

# @lcpr case=start
# 124\n
# @lcpr case=end

#
