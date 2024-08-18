#
# @lc app=leetcode.cn id=1220 lang=python3
#
# [1220] 统计元音字母序列的数目
#
# https://leetcode-cn.com/problems/count-vowels-permutation/description/
#
# algorithms
# Hard (51.82%)
# Likes:    25
# Dislikes: 0
# Total Accepted:    2.6K
# Total Submissions: 5K
# Testcase Example:  '1'
#
# 给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：
#
#
# 字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
# 每个元音 'a' 后面都只能跟着 'e'
# 每个元音 'e' 后面只能跟着 'a' 或者是 'i'
# 每个元音 'i' 后面 不能 再跟着另一个 'i'
# 每个元音 'o' 后面只能跟着 'i' 或者是 'u'
# 每个元音 'u' 后面只能跟着 'a'
#
#
# 由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。
#
#
#
# 示例 1：
#
# 输入：n = 1
# 输出：5
# 解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
#
#
# 示例 2：
#
# 输入：n = 2
# 输出：10
# 解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
#
#
# 示例 3：
#
# 输入：n = 5
# 输出：68
#
#
#
# 提示：
#
#
# 1 <= n <= 2 * 10^4
#
#
#


# @lc code=start
class Solution:
    def countVowelPermutation(self, n: int) -> int:

        # 动态规划，按照之前的以不同字母结尾的字符串的数目推导下一个按
        # 不同字符结尾的字符串数目，由于有明显的约束条件，因此很容易推导出来

        mod = 10**9 + 7
        a, e, i, o, u = 1, 1, 1, 1, 1
        for _ in range(1, n):
            aa = (e + i + u) % mod
            ee = (a + i) % mod
            ii = (e + o) % mod
            oo = (i) % mod
            uu = (i + o) % mod
            a, e, i, o, u = aa, ee, ii, oo, uu
        return (a + e + i + o + u) % mod


# @lc code=end
