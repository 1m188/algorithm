#
# @lc app=leetcode.cn id=1387 lang=python3
#
# [1387] 将整数按权重排序
#
# https://leetcode-cn.com/problems/sort-integers-by-the-power-value/description/
#
# algorithms
# Medium (68.33%)
# Likes:    20
# Dislikes: 0
# Total Accepted:    5.1K
# Total Submissions: 7.4K
# Testcase Example:  '12\n15\n2'
#
# 我们将整数 x 的 权重 定义为按照下述规则将 x 变成 1 所需要的步数：
#
#
# 如果 x 是偶数，那么 x = x / 2
# 如果 x 是奇数，那么 x = 3 * x + 1
#
#
# 比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 -->
# 1）。
#
# 给你三个整数 lo， hi 和 k 。你的任务是将区间 [lo, hi] 之间的整数按照它们的权重 升序排序 ，如果大于等于 2 个整数有 相同
# 的权重，那么按照数字自身的数值 升序排序 。
#
# 请你返回区间 [lo, hi] 之间的整数按权重排序后的第 k 个数。
#
# 注意，题目保证对于任意整数 x （lo <= x <= hi） ，它变成 1 所需要的步数是一个 32 位有符号整数。
#
#
#
# 示例 1：
#
# 输入：lo = 12, hi = 15, k = 2
# 输出：13
# 解释：12 的权重为 9（12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）
# 13 的权重为 9
# 14 的权重为 17
# 15 的权重为 17
# 区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
# 注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。
#
#
# 示例 2：
#
# 输入：lo = 1, hi = 1, k = 1
# 输出：1
#
#
# 示例 3：
#
# 输入：lo = 7, hi = 11, k = 4
# 输出：7
# 解释：区间内整数 [7, 8, 9, 10, 11] 对应的权重为 [16, 3, 19, 6, 14] 。
# 按权重排序后得到的结果为 [8, 10, 11, 7, 9] 。
# 排序后数组中第 4 个数字为 7 。
#
#
# 示例 4：
#
# 输入：lo = 10, hi = 20, k = 5
# 输出：13
#
#
# 示例 5：
#
# 输入：lo = 1, hi = 1000, k = 777
# 输出：570
#
#
#
#
# 提示：
#
#
# 1 <= lo <= hi <= 1000
# 1 <= k <= hi - lo + 1
#
#
#


# @lc code=start
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def weight(num):
            res = 0
            while num != 1:
                num = num / 2 if not num % 2 else 3 * num + 1
                res += 1
            return res

        def cmp(a, b):
            return (1 if a[1] > b[1] else -1) if a[1] != b[1] else \
                (1 if a[0] > b[0] else -1 if a[0] < b[0] else 0)

        def adjust_heap(li, left, right):
            tmp = li[left]
            m = left * 2 + 1
            while m <= right:
                if m + 1 <= right and cmp(li[m + 1], li[m]) == -1:
                    m += 1
                if cmp(tmp, li[m]) == 1:
                    li[left] = li[m]
                    left = m
                    m = left * 2 + 1
                else:
                    break
            li[left] = tmp

        def build_heap(li):
            for i in range(int((len(li) - 2) / 2), -1, -1):
                adjust_heap(li, i, len(li) - 1)

        li = [(i, weight(i)) for i in range(lo, hi + 1)]
        build_heap(li)
        for _ in range(k):
            li[-1], li[0] = li[0], li[-1]
            res = li.pop()
            if len(li) >= 1:
                adjust_heap(li, 0, len(li) - 1)
        return res[0]


# @lc code=end
