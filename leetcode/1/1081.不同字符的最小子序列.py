#
# @lc app=leetcode.cn id=1081 lang=python3
#
# [1081] 不同字符的最小子序列
#
# https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/description/
#
# algorithms
# Medium (58.29%)
# Likes:    174
# Dislikes: 0
# Total Accepted:    23.9K
# Total Submissions: 41.1K
# Testcase Example:  '"bcabc"'
#
# 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
#
# 注意：该题与 316 https://leetcode.com/problems/remove-duplicate-letters/ 相同
#
#
#
# 示例 1：
#
#
# 输入：s = "bcabc"
# 输出："abc"
#
#
# 示例 2：
#
#
# 输入：s = "cbacdcbc"
# 输出："acdb"
#
#
#
# 提示：
#
#
# 1 <= s.length <= 1000
# s 由小写英文字母组成
#
#
#


# @lc code=start
class Solution:

    def smallestSubsequence(self, s: str) -> str:

        isin = [False for _ in range(26)]  # 字符是否已经在栈中
        nums = [0 for _ in range(26)]  # 每个字符的剩余数量
        for c in s:
            nums[ord(c) - ord('a')] += 1
        stack = []  # 单调栈

        for c in s:
            ci = ord(c) - ord('a')
            if isin[ci]:
                nums[ci] -= 1  # 跳过这个字符注意数量-1
                continue
            if stack:
                while stack and stack[-1] > c:
                    j = ord(stack[-1]) - ord('a')
                    if nums[j] > 0:
                        isin[ord(stack.pop()) - ord('a')] = False
                    else:
                        break
            stack.append(c)
            nums[ci] -= 1
            isin[ci] = True

        return ''.join(stack)


# @lc code=end
