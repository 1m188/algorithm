#
# @lc app=leetcode.cn id=1812 lang=python3
#
# [1812] 判断国际象棋棋盘中一个格子的颜色
#
# https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square/description/
#
# algorithms
# Easy (78.80%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    10.4K
# Total Submissions: 13.2K
# Testcase Example:  '"a1"'
#
# 给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。
#
#
#
# 如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。
#
# 给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。
#
#
#
# 示例 1：
#
#
# 输入：coordinates = "a1"
# 输出：false
# 解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
#
#
# 示例 2：
#
#
# 输入：coordinates = "h3"
# 输出：true
# 解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
#
#
# 示例 3：
#
#
# 输入：coordinates = "c7"
# 输出：false
#
#
#
#
# 提示：
#
#
# coordinates.length == 2
# 'a' <= coordinates[0] <= 'h'
# '1' <= coordinates[1] <= '8'
#
#
#


# @lc code=start
class Solution:

    def squareIsWhite(self, coordinates: str) -> bool:

        li1 = [False, True, False, True, False, True, False, True]

        x, y = coordinates[0], int(coordinates[1])

        if x not in ['a', 'c', 'e', 'g']:
            for i in range(8):
                li1[i] = not li1[i]

        return li1[y - 1]


# @lc code=end
