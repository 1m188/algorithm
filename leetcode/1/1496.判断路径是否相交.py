#
# @lc app=leetcode.cn id=1496 lang=python3
#
# [1496] 判断路径是否相交
#
# https://leetcode-cn.com/problems/path-crossing/description/
#
# algorithms
# Easy (53.53%)
# Likes:    34
# Dislikes: 0
# Total Accepted:    12.6K
# Total Submissions: 23.5K
# Testcase Example:  '"NES"'
#
# 给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
#
# 你从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。
#
# 如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
#
#
#
# 输入：path = "NES"
# 输出：false
# 解释：该路径没有在任何位置相交。
#
# 示例 2：
#
#
#
#
# 输入：path = "NESWW"
# 输出：true
# 解释：该路径经过原点两次。
#
#
#
# 提示：
#
#
# 1 <= path.length <= 10^4
# path[i] 为 'N'、'S'、'E' 或 'W'
#
#
#


# @lc code=start
class Solution:

    def isPathCrossing(self, path: str) -> bool:
        '''

        保存坐标，互相比对

        '''

        ps = set()
        ps.add((0, 0))
        x, y = 0, 0

        for i in path:
            if i == 'N':
                y += 1
            elif i == 'S':
                y -= 1
            elif i == 'E':
                x += 1
            else:
                x -= 1

            if (x, y) not in ps:
                ps.add((x, y))
            else:
                return True

        return False


# @lc code=end
