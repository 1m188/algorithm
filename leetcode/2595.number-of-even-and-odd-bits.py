#
# @lc app=leetcode.cn id=2595 lang=python3
# @lcpr version=30204
#
# [2595] 奇偶位数
#
# https://leetcode.cn/problems/number-of-even-and-odd-bits/description/
#
# algorithms
# Easy (75.76%)
# Likes:    29
# Dislikes: 0
# Total Accepted:    28.7K
# Total Submissions: 35.9K
# Testcase Example:  '50'
#
# 给你一个 正 整数 n 。
#
# 用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。
#
# 用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。
#
# 请注意，在数字的二进制表示中，位下标的顺序 从右到左。
#
# 返回整数数组 answer ，其中 answer = [even, odd] 。
#
#
#
# 示例 1：
#
#
# 输入：n = 50
#
# 输出：[1,2]
#
# 解释：
#
# 50 的二进制表示是 110010。
#
# 在下标 1，4，5 对应的值为 1。
#
#
# 示例 2：
#
#
# 输入：n = 2
#
# 输出：[0,1]
#
# 解释：
#
# 2 的二进制表示是 10。
#
# 只有下标 1 对应的值为 1。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 1000
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def evenOddBit(self, n: int) -> List[int]:
        even, odd = 0, 0
        i = 0
        while n:
            even += (n & 0x1 == 1 and i & 0x1 == 0)
            odd += (n & 0x1 == 1 and i & 0x1 == 1)
            i += 1
            n >>= 1
        return [even, odd]


# @lc code=end

#
# @lcpr case=start
# 50\n
# @lcpr case=end

# @lcpr case=start
# 2\n
# @lcpr case=end

#
