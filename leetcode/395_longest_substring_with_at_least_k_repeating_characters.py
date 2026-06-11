#
# @lc app=leetcode.cn id=395 lang=python3
# @lcpr version=30204
#
# [395] 至少有 K 个重复字符的最长子串
#
# https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
#
# algorithms
# Medium (53.17%)
# Likes:    1007
# Dislikes: 0
# Total Accepted:    117K
# Total Submissions: 220K
# Testcase Example:  '"aaabb"\n3'
#
# 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
#
# 如果不存在这样的子字符串，则返回 0。
#
#
#
# 示例 1：
#
# 输入：s = "aaabb", k = 3
# 输出：3
# 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
#
#
# 示例 2：
#
# 输入：s = "ababbc", k = 2
# 输出：5
# 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
#
#
#
# 提示：
#
#
# 1 <= s.length <= 10^4
# s 仅由小写英文字母组成
# 1 <= k <= 10^5
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        # 分治：找到出现次数不足 k 的字符作为分割点，递归处理各段
        def dfs(l: int, r: int) -> int:
            if r - l + 1 < k:
                return 0

            # 统计当前区间内每个字符的出现次数
            freq = [0] * 26
            for i in range(l, r + 1):
                freq[ord(s[i]) - ord("a")] += 1

            # 找到第一个出现次数不足 k 的字符作为分割点
            splitter = -1
            for i in range(l, r + 1):
                if freq[ord(s[i]) - ord("a")] < k:
                    splitter = i
                    break

            if splitter == -1:
                # 所有字符出现次数都 >= k，整个区间合法
                return r - l + 1

            # 以 splitter 为界，递归处理左右两部分，取最大值
            return max(dfs(l, splitter - 1), dfs(splitter + 1, r))

        return dfs(0, len(s) - 1)


# @lc code=end


#
# @lcpr case=start
# "aaabb"\n3\n
# @lcpr case=end

# @lcpr case=start
# "ababbc"\n2\n
# @lcpr case=end

#
