#
# @lc app=leetcode.cn id=3527 lang=python3
# @lcpr version=30204
#
# [3527] 找到最常见的回答
#
# https://leetcode.cn/problems/find-the-most-common-response/description/
#
# algorithms
# Medium (71.24%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    2.6K
# Total Submissions: 3.6K
# Testcase Example:  '[["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]'
#
# 给你一个二维字符串数组 responses，其中每个 responses[i] 是一个字符串数组，表示第 i 天调查的回答结果。
#
# 请返回在对每个 responses[i] 中的回答 去重 后，所有天数中 最常见 的回答。如果有多个回答出现频率相同，则返回 字典序最小
# 的那个回答。
#
#
#
# 示例 1：
#
#
# 输入： responses =
# [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]
#
# 输出： "good"
#
# 解释：
#
#
# 每个列表去重后，得到 responses = [["good", "ok"], ["ok", "bad", "good"], ["good"],
# ["bad"]]。
# "good" 出现了 3 次，"ok" 出现了 2 次，"bad" 也出现了 2 次。
# 返回 "good"，因为它出现的频率最高。
#
#
#
# 示例 2：
#
#
# 输入： responses =
# [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]
#
# 输出： "bad"
#
# 解释：
#
#
# 每个列表去重后，responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"],
# ["great", "good"]]。
# "bad"、"good" 和 "ok" 都出现了 2 次。
# 返回 "bad"，因为它在这些最高频率的词中字典序最小。
#
#
#
#
#
# 提示：
#
#
# 1 <= responses.length <= 1000
# 1 <= responses[i].length <= 1000
# 1 <= responses[i][j].length <= 10
# responses[i][j] 仅由小写英文字母组成
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:
        m = {}
        for r in responses:
            for i in set(r):
                m[i] = m.get(i, 0) + 1
        return sorted(m.items(), key=lambda x: (-x[1], x[0]))[0][0]


# @lc code=end


#
# @lcpr case=start
# [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]\n
# @lcpr case=end

# @lcpr case=start
# [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]\n
# @lcpr case=end

#
