#
# @lc app=leetcode.cn id=1079 lang=python3
#
# [1079] 活字印刷
#
# https://leetcode-cn.com/problems/letter-tile-possibilities/description/
#
# algorithms
# Medium (73.06%)
# Likes:    79
# Dislikes: 0
# Total Accepted:    6.4K
# Total Submissions: 8.7K
# Testcase Example:  '"AAB"'
#
# 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
#
# 注意：本题中，每个活字字模只能使用一次。
#
#
#
# 示例 1：
#
# 输入："AAB"
# 输出：8
# 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
#
#
# 示例 2：
#
# 输入："AAABBC"
# 输出：188
#
#
#
#
# 提示：
#
#
# 1 <= tiles.length <= 7
# tiles 由大写英文字母组成
#
#
#

from typing import List


# @lc code=start
class Solution:
    def arrange(self, tiles: List[str], fl: List[bool], sq: List[str],
                sun: set):
        for i in range(len(fl)):
            if not fl[i]:
                fl[i] = True
                sq.append(tiles[i])
                sun.add("".join(sq))
                self.arrange(tiles, fl, sq, sun)
                sq.pop()
                fl[i] = False

    def numTilePossibilities(self, tiles: str) -> int:
        sun = set()
        self.arrange(list(tiles), [False] * len(tiles), [], sun)
        return len(sun)


# @lc code=end
