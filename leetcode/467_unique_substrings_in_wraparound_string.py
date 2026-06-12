#
# @lc app=leetcode.cn id=467 lang=python3
# @lcpr version=30204
#
# [467] 环绕字符串中唯一的子字符串
#
# https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/
#
# algorithms
# Medium (53.02%)
# Likes:    463
# Dislikes: 0
# Total Accepted:    52K
# Total Submissions: 98.1K
# Testcase Example:  '"a"'
#
# 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：
#
#
# "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
#
#
# 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。
#
#
#
# 示例 1：
#
# 输入：s = "a"
# 输出：1
# 解释：字符串 s 的子字符串 "a" 在 base 中出现。
#
#
# 示例 2：
#
# 输入：s = "cac"
# 输出：2
# 解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
#
#
# 示例 3：
#
# 输入：s = "zab"
# 输出：6
# 解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 10^5
# s 由小写英文字母组成
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        # max_len[c] 表示以字符 c 结尾的、在 base 中出现的子串的最大长度
        max_len = [0] * 26
        cur_len = 0  # 当前连续符合环绕顺序的子串长度

        for i, ch in enumerate(s):
            idx = ord(ch) - ord("a")
            if i > 0 and (ord(ch) - ord(s[i - 1])) % 26 == 1:
                # 当前字符紧跟前一个字符（z->a 也满足），连续段延长
                cur_len += 1
            else:
                cur_len = 1

            if cur_len > max_len[idx]:
                max_len[idx] = cur_len

        # 每个 max_len[c] 表示以 c 结尾的不同子串数量，求和即为答案
        return sum(max_len)


# @lc code=end


#
# @lcpr case=start
# "a"\n
# @lcpr case=end

# @lcpr case=start
# "cac"\n
# @lcpr case=end

# @lcpr case=start
# "zab"\n
# @lcpr case=end

#
