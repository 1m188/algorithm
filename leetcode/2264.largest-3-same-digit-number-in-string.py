#
# @lc app=leetcode.cn id=2264 lang=python3
# @lcpr version=30204
#
# [2264] 字符串中最大的 3 位相同数字
#
# https://leetcode.cn/problems/largest-3-same-digit-number-in-string/description/
#
# algorithms
# Easy (62.82%)
# Likes:    35
# Dislikes: 0
# Total Accepted:    26.1K
# Total Submissions: 37.9K
# Testcase Example:  '"6777133339"'
#
# 给你一个字符串 num ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 优质整数 ：
#
#
# 该整数是 num 的一个长度为 3 的 子字符串 。
# 该整数由唯一一个数字重复 3 次组成。
#
#
# 以字符串形式返回 最大的优质整数 。如果不存在满足要求的整数，则返回一个空字符串 "" 。
#
# 注意：
#
#
# 子字符串 是字符串中的一个连续字符序列。
# num 或优质整数中可能存在 前导零 。
#
#
#
#
# 示例 1：
#
# 输入：num = "6777133339"
# 输出："777"
# 解释：num 中存在两个优质整数："777" 和 "333" 。
# "777" 是最大的那个，所以返回 "777" 。
#
#
# 示例 2：
#
# 输入：num = "2300019"
# 输出："000"
# 解释："000" 是唯一一个优质整数。
#
#
# 示例 3：
#
# 输入：num = "42352338"
# 输出：""
# 解释：不存在长度为 3 且仅由一个唯一数字组成的整数。因此，不存在优质整数。
#
#
#
#
# 提示：
#
#
# 3 <= num.length <= 1000
# num 仅由数字（0 - 9）组成
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def largestGoodInteger(self, num: str) -> str:

        res = ''
        for i in range(len(num) - 2):
            if not num[i] == num[i + 1] == num[i + 2]: continue
            if not res or int(res[0]) < int(num[i]): res = num[i:i + 3]
        return res


# @lc code=end

#
# @lcpr case=start
# "6777133339"\n
# @lcpr case=end

# @lcpr case=start
# "2300019"\n
# @lcpr case=end

# @lcpr case=start
# "42352338"\n
# @lcpr case=end

#
