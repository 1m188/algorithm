#
# @lc app=leetcode.cn id=2946 lang=python3
#
# [2946] 循环移位后的矩阵相似检查
#
# https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/description/
#
# algorithms
# Easy (60.20%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    4.9K
# Total Submissions: 8K
# Testcase Example:  '[[1,2,1,2],[5,5,5,5],[6,3,6,3]]\n2'
#
# 给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。请你将矩阵中的 奇数 行循环 右 移 k 次，偶数 行循环 左 移 k
# 次。
#
# 如果初始矩阵和最终矩阵完全相同，则返回 true ，否则返回 false 。
#
#
#
# 示例 1：
#
#
# 输入：mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
# 输出：true
# 解释：
#
#
# 初始矩阵如图一所示。
# 图二表示对奇数行右移一次且对偶数行左移一次后的矩阵状态。
# 图三是经过两次循环移位后的最终矩阵状态，与初始矩阵相同。
# 因此，返回 true 。
#
#
# 示例 2：
#
#
# 输入：mat = [[2,2],[2,2]], k = 3
# 输出：true
# 解释：由于矩阵中的所有值都相等，即使进行循环移位，矩阵仍然保持不变。因此，返回 true 。
#
#
# 示例 3：
#
#
# 输入：mat = [[1,2]], k = 1
# 输出：false
# 解释：循环移位一次后，mat = [[2,1]]，与初始矩阵不相等。因此，返回 false 。
#
#
#
#
# 提示：
#
#
# 1 <= mat.length <= 25
# 1 <= mat[i].length <= 25
# 1 <= mat[i][j] <= 25
# 1 <= k <= 50
#
#
#

from typing import List


# @lc code=start
class Solution:

    def areSimilar(self, mat: List[List[int]], k: int) -> bool:

        if k == len(mat[0]): return True  # 移位长度和数组长度一致，无论怎么移动都会回到原位

        def judge(row: list[int], left: bool, k: int):
            length = len(row)
            k = int(k % length)
            if left: row_new = row[k:] + row[:k]
            else: row_new = row[length - k:] + row[:length - k]
            return row_new == row

        for i, v in enumerate(mat):
            if len(set(v)) == 1: continue  # 如果行内只有一种元素，则无论怎么移动都和原来一样
            if not judge(v, (i + 1) % 2 != 1, k): return False
        return True


# @lc code=end
