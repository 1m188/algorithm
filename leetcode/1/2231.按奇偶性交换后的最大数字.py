#
# @lc app=leetcode.cn id=2231 lang=python3
#
# [2231] 按奇偶性交换后的最大数字
#
# https://leetcode-cn.com/problems/largest-number-after-digit-swaps-by-parity/description/
#
# algorithms
# Easy (62.63%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    8.1K
# Total Submissions: 12.9K
# Testcase Example:  '1234'
#
# 给你一个正整数 num 。你可以交换 num 中 奇偶性 相同的任意两位数字（即，都是奇数或者偶数）。
#
# 返回交换 任意 次之后 num 的 最大 可能值。
#
#
#
# 示例 1：
#
# 输入：num = 1234
# 输出：3412
# 解释：交换数字 3 和数字 1 ，结果得到 3214 。
# 交换数字 2 和数字 4 ，结果得到 3412 。
# 注意，可能存在其他交换序列，但是可以证明 3412 是最大可能值。
# 注意，不能交换数字 4 和数字 1 ，因为它们奇偶性不同。
#
#
# 示例 2：
#
# 输入：num = 65875
# 输出：87655
# 解释：交换数字 8 和数字 6 ，结果得到 85675 。
# 交换数字 5 和数字 7 ，结果得到 87655 。
# 注意，可能存在其他交换序列，但是可以证明 87655 是最大可能值。
#
#
#
#
# 提示：
#
#
# 1 <= num <= 10^9
#
#
#


# @lc code=start
class Solution:

    def largestInteger(self, num: int) -> int:

        nl = []
        while num:
            nl.append(num % 10)
            num //= 10
        nl.reverse()

        idxl = []
        li = []
        for i in range(len(nl)):
            if nl[i] % 2:
                idxl.append(i)
                li.append(nl[i])
        li.sort(reverse=True)
        for i in range(len(idxl)):
            nl[idxl[i]] = li[i]

        idxl = []
        li = []
        for i in range(len(nl)):
            if not nl[i] % 2:
                idxl.append(i)
                li.append(nl[i])
        li.sort(reverse=True)
        for i in range(len(idxl)):
            nl[idxl[i]] = li[i]

        ans = 0
        while nl:
            ans = ans * 10 + nl.pop(0)
        return ans


# @lc code=end
