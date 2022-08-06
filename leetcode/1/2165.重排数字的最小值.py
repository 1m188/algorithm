#
# @lc app=leetcode.cn id=2165 lang=python3
#
# [2165] 重排数字的最小值
#
# https://leetcode.cn/problems/smallest-value-of-the-rearranged-number/description/
#
# algorithms
# Medium (54.96%)
# Likes:    7
# Dislikes: 0
# Total Accepted:    6.9K
# Total Submissions: 12.6K
# Testcase Example:  '310'
#
# 给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。
#
# 返回不含前导零且值最小的重排数字。
#
# 注意，重排各位数字后，num 的符号不会改变。
#
#
#
# 示例 1：
#
# 输入：num = 310
# 输出：103
# 解释：310 中各位数字的可行排列有：013、031、103、130、301、310 。
# 不含任何前导零且值最小的重排数字是 103 。
#
#
# 示例 2：
#
# 输入：num = -7605
# 输出：-7650
# 解释：-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
# 不含任何前导零且值最小的重排数字是 -7650 。
#
#
#
# 提示：
#
#
# -10^15 <= num <= 10^15
#
#
#
'''
如果是正数，则取除0外的最小数作为最高位，其他的按照从小到大
的顺序依次往后排；如果是负数，则从大到小排，最后返回的时候
加个负号；如果是0，则直接返回0
'''


# @lc code=start
class Solution:

    def smallestNumber(self, num: int) -> int:

        if num == 0: return 0

        sign = 1
        if num < 0: sign = -1
        num = abs(num)

        li = []
        while num:
            li.append(num % 10)
            num //= 10

        if sign > 0:
            li.sort()
            for i in range(len(li)):
                if li[i] == 0: continue
                else: break
            li.insert(0, li.pop(i))
        else:
            li.sort(reverse=True)

        res = 0
        for i in li:
            res = res * 10 + i
        return res * sign


# @lc code=end
