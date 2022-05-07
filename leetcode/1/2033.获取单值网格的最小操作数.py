#
# @lc app=leetcode.cn id=2033 lang=python3
#
# [2033] 获取单值网格的最小操作数
#
# https://leetcode-cn.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
#
# algorithms
# Medium (40.69%)
# Likes:    23
# Dislikes: 0
# Total Accepted:    5.1K
# Total Submissions: 12.5K
# Testcase Example:  '[[2,4],[6,8]]\n2'
#
# 给你一个大小为 m x n 的二维整数网格 grid 和一个整数 x 。每一次操作，你可以对 grid 中的任一元素 加 x 或 减 x 。
#
# 单值网格 是全部元素都相等的网格。
#
# 返回使网格化为单值网格所需的 最小 操作数。如果不能，返回 -1 。
#
#
#
# 示例 1：
#
#
#
#
# 输入：grid = [[2,4],[6,8]], x = 2
# 输出：4
# 解释：可以执行下述操作使所有元素都等于 4 ：
# - 2 加 x 一次。
# - 6 减 x 一次。
# - 8 减 x 两次。
# 共计 4 次操作。
#
#
# 示例 2：
#
#
#
#
# 输入：grid = [[1,5],[2,3]], x = 1
# 输出：5
# 解释：可以使所有元素都等于 3 。
#
#
# 示例 3：
#
#
#
#
# 输入：grid = [[1,2],[3,4]], x = 2
# 输出：-1
# 解释：无法使所有元素相等。
#
#
#
#
# 提示：
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 10^5
# 1 <= m * n <= 10^5
# 1 <= x, grid[i][j] <= 10^4
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''
    1. 判断能不能实现  即判断所有数是否能和数组中的某个数的差为x的倍数

    2. 要使操作数最小 则需要使所有数向中位数对齐

    3. 如果中位数为小数  也就是偶数长度的数组  则找到离中位数最近的数

    4. 让每个数都通过+x或-x达到中位数  记录其中的操作步骤数作为结果返回
    '''

    def minOperations(self, grid: List[List[int]], x: int) -> int:

        if not self.judge(grid, x): return -1

        mid = self.findMidNum(grid)

        ans = 0
        for i in grid:
            for j in i:
                ans += abs(j - mid) // x
        return ans

    def judge(self, grid: List[List[int]], x: int) -> bool:
        '''
        判断能不能够实现

        即判断能不能让每个数都通过+x或者-x达到一致

        通过判断对某个数而言是否其他所有的数能够和它的差(距离,绝对值)为x的倍数
        '''

        for i in grid:
            for j in i:
                if abs(grid[0][0] - j) % x:
                    return False

        return True

    def findMidNum(self, grid: List[List[int]]) -> int:
        '''
        找到中位数

        如果是奇数长度的数组则直接返回中间的那个数

        如果是偶数的话  返回中间两个数中最靠近中位数的那个数
        '''

        li = []
        for i in grid:
            li.extend(i)
        li.sort()

        if len(li) % 2: return li[len(li) // 2]
        else:
            a, b = li[len(li) // 2], li[len(li) // 2 - 1]
            c = (a + b) / 2
            return a if abs(a - c) < abs(b - c) else b


# @lc code=end
