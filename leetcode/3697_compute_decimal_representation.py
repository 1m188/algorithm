#
# @lc app=leetcode.cn id=3697 lang=python3
# @lcpr version=30204
#
# [3697] 计算十进制表示
#
# https://leetcode.cn/problems/compute-decimal-representation/description/
#
# algorithms
# Easy (62.60%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3.2K
# Total Submissions: 5.1K
# Testcase Example:  '537'
#
# 给你一个 正整数 n。
#
# 如果一个正整数可以表示为 1 到 9 的单个数字和 10 的非负整数次幂的乘积，则称这个整数是一个 10 进制分量。例如，500、30 和 7 是 10
# 进制分量 ，而 537、102 和 11 则不是。
#
# 请将 n 表示为若干 仅由 10 进制分量组成的和，且使用的 10 进制分量个数 最少 。
#
# 返回一个包含这些 10 进制分量 的数组，并按分量大小 降序 排列。
#
#
#
# 示例 1：
#
#
# 输入：n = 537
#
# 输出：[500,30,7]
#
# 解释：
#
# 我们可以将 537 表示为500 + 30 + 7。无法用少于 3 个 10 进制分量表示 537。
#
#
# 示例 2：
#
#
# 输入：n = 102
#
# 输出：[100,2]
#
# 解释：
#
# 我们可以将 102 表示为100 + 2。102 不是一个 10 进制分量，因此需要 2 个 10 进制分量。
#
#
# 示例 3：
#
#
# 输入：n = 6
#
# 输出：[6]
#
# 解释：
#
# 6 是一个 10 进制分量。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 10^9
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        res = []
        index = 0
        while n:
            x = n % 10 * 10**index
            if x:
                res.append(x)
            n //= 10
            index += 1
        res.reverse()
        return res


# @lc code=end


#
# @lcpr case=start
# 537\n
# @lcpr case=end

# @lcpr case=start
# 102\n
# @lcpr case=end

# @lcpr case=start
# 6\n
# @lcpr case=end

#
