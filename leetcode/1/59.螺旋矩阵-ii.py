#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#
# https://leetcode-cn.com/problems/spiral-matrix-ii/description/
#
# algorithms
# Medium (77.87%)
# Likes:    238
# Dislikes: 0
# Total Accepted:    47.3K
# Total Submissions: 60.5K
# Testcase Example:  '3'
#
# 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
#
# 示例:
#
# 输入: 3
# 输出:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 8, 9, 4 ],
# ⁠[ 7, 6, 5 ]
# ]
#
#

from typing import List


# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        nl = [i for i in range(1, n * n + 1)]
        res = [[0] * n for _ in range(n)]
        dx, dy = 1, 0
        px, py = 0, 0

        while nl:
            if px >= 0 and px < n and py >= 0 and py < n and not res[py][px]:
                res[py][px] = nl.pop(0)
                px += dx
                py += dy
            else:
                px -= dx
                py -= dy
                if dx == 1:
                    dx, dy = 0, 1
                elif dx == -1:
                    dx, dy = 0, -1
                elif dy == 1:
                    dx, dy = -1, 0
                elif dy == -1:
                    dx, dy = 1, 0
                px += dx
                py += dy

        return res


# @lc code=end
