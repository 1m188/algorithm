#
# @lc app=leetcode.cn id=1202 lang=python3
#
# [1202] 交换字符串中的元素
#
# https://leetcode.cn/problems/smallest-string-with-swaps/description/
#
# algorithms
# Medium (50.73%)
# Likes:    277
# Dislikes: 0
# Total Accepted:    29.8K
# Total Submissions: 58.6K
# Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
#
# 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0
# 开始）。
#
# 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
#
# 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
#
#
#
# 示例 1:
#
# 输入：s = "dcab", pairs = [[0,3],[1,2]]
# 输出："bacd"
# 解释：
# 交换 s[0] 和 s[3], s = "bcad"
# 交换 s[1] 和 s[2], s = "bacd"
#
#
# 示例 2：
#
# 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
# 输出："abcd"
# 解释：
# 交换 s[0] 和 s[3], s = "bcad"
# 交换 s[0] 和 s[2], s = "acbd"
# 交换 s[1] 和 s[2], s = "abcd"
#
# 示例 3：
#
# 输入：s = "cba", pairs = [[0,1],[1,2]]
# 输出："abc"
# 解释：
# 交换 s[0] 和 s[1], s = "bca"
# 交换 s[1] 和 s[2], s = "bac"
# 交换 s[0] 和 s[1], s = "abc"
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 10^5
# 0 <= pairs.length <= 10^5
# 0 <= pairs[i][0], pairs[i][1] < s.length
# s 中只含有小写英文字母
#
#
#

from typing import Dict, List, NoReturn


# @lc code=start
class Solution:

    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:

        n = len(s)
        ufset = [0 for _ in range(n)]
        for i in range(n):
            ufset[i] = i

        def uf_find(x: int) -> int:
            if ufset[x] == x: return x
            ufset[x] = uf_find(ufset[x])
            return ufset[x]

        def uf_union(x: int, y: int) -> NoReturn:
            rx, ry = uf_find(x), uf_find(y)
            if rx < ry: ufset[ry] = rx
            else: ufset[rx] = ry

        for i, j in pairs:
            uf_union(i, j)

        di: Dict[int, List[int]] = {}
        for i in range(n):
            r = uf_find(i)
            if r not in di: di[r] = [i]
            else: di[r].append(i)

        sli = list(s)
        for v in di.values():
            li = [sli[i] for i in v]
            li.sort()
            for i in v:
                sli[i] = li.pop(0)

        return ''.join(sli)


# @lc code=end
