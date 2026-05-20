#
# @lc app=leetcode.cn id=2515 lang=python3
# @lcpr version=30204
#
# [2515] 到目标字符串的最短距离
#
# https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/description/
#
# algorithms
# Easy (56.05%)
# Likes:    25
# Dislikes: 0
# Total Accepted:    14.8K
# Total Submissions: 24.6K
# Testcase Example:  '["hello","i","am","leetcode","hello"]\n"hello"\n1'
#
# 给你一个下标从 0 开始的 环形 字符串数组 words 和一个字符串 target 。环形数组 意味着数组首尾相连。
#
#
# 形式上， words[i] 的下一个元素是 words[(i + 1) % n] ，而 words[i] 的前一个元素是 words[(i - 1 +
# n) % n] ，其中 n 是 words 的长度。
#
#
# 从 startIndex 开始，你一次可以用 1 步移动到下一个或者前一个单词。
#
# 返回到达目标字符串 target 所需的最短距离。如果 words 中不存在字符串 target ，返回 -1 。
#
#
#
# 示例 1：
#
# 输入：words = ["hello","i","am","leetcode","hello"], target = "hello",
# startIndex = 1
# 输出：1
# 解释：从下标 1 开始，可以经由以下步骤到达 "hello" ：
# - 向右移动 3 个单位，到达下标 4 。
# - 向左移动 2 个单位，到达下标 4 。
# - 向右移动 4 个单位，到达下标 0 。
# - 向左移动 1 个单位，到达下标 0 。
# 到达 "hello" 的最短距离是 1 。
#
#
# 示例 2：
#
# 输入：words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
# 输出：1
# 解释：从下标 0 开始，可以经由以下步骤到达 "leetcode" ：
# - 向右移动 2 个单位，到达下标 2 。
# - 向左移动 1 个单位，到达下标 2 。
# 到达 "leetcode" 的最短距离是 1 。
#
# 示例 3：
#
# 输入：words = ["i","eat","leetcode"], target = "ate", startIndex = 0
# 输出：-1
# 解释：因为 words 中不存在字符串 "ate" ，所以返回 -1 。
#
#
#
#
# 提示：
#
#
# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] 和 target 仅由小写英文字母组成
# 0 <= startIndex < words.length
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:

        if target == words[startIndex]:
            return 0

        n = len(words)

        targetIndex1, targetIndex2 = -1, -1
        len1, len2 = 1, 1
        index = (startIndex + 1) % n
        while index != startIndex:
            if target == words[index]:
                targetIndex1 = index
                break
            index = (index + 1) % n
            len1 += 1
        index = (startIndex - 1 + n) % n
        while index != startIndex:
            if target == words[index]:
                targetIndex2 = index
                break
            index = (index - 1 + n) % n
            len2 += 1

        if targetIndex1 == targetIndex2 == -1:
            return -1
        elif targetIndex1 == -1:
            return len2
        elif targetIndex2 == -1:
            return len1
        else:
            return min(len1, len2)


# @lc code=end


#
# @lcpr case=start
# ["hello","i","am","leetcode","hello"]\n"hello"\n1\n
# @lcpr case=end

# @lcpr case=start
# ["a","b","leetcode"]\n"leetcode"\n0\n
# @lcpr case=end

# @lcpr case=start
# ["i","eat","leetcode"]\n"ate"\n0\n
# @lcpr case=end

#
