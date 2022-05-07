#
# @lc app=leetcode.cn id=2124 lang=python3
#
# [2124] 检查是否所有 A 都在 B 之前
#
# https://leetcode-cn.com/problems/check-if-all-as-appears-before-all-bs/description/
#
# algorithms
# Easy (70.78%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    8.3K
# Total Submissions: 11.8K
# Testcase Example:  '"aaabbb"'
#
# 给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个  'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回
# false 。
#
#
#
# 示例 1：
#
# 输入：s = "aaabbb"
# 输出：true
# 解释：
# 'a' 位于下标 0、1 和 2 ；而 'b' 位于下标 3、4 和 5 。
# 因此，每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
#
#
# 示例 2：
#
# 输入：s = "abab"
# 输出：false
# 解释：
# 存在一个 'a' 位于下标 2 ，而一个 'b' 位于下标 1 。
# 因此，不能满足每个 'a' 都出现在每个 'b' 之前，所以返回 false 。
#
#
# 示例 3：
#
# 输入：s = "bbb"
# 输出：true
# 解释：
# 不存在 'a' ，因此可以视作每个 'a' 都出现在每个 'b' 之前，所以返回 true 。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 100
# s[i] 为 'a' 或 'b'
#
#
#


# @lc code=start
class Solution:

    def checkString(self, s: str) -> bool:

        i = 0

        while i < len(s) and s[i] != 'b':  # 找到第一个b
            i += 1

        if i >= len(s): return True  # 如果找不到，说明只有a，成立

        while i < len(s) and s[i] != 'a':  # 找到之后，找第一个a
            i += 1

        if i >= len(s): return True  # 如果找不到，说明从b开始没有a，只有b，即所有a都在b之前

        return False  # 不然找到了，不满足


# @lc code=end
