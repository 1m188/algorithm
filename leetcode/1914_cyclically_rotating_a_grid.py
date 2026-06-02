#
# @lc app=leetcode.cn id=1914 lang=python3
# @lcpr version=30204
#
# [1914] 循环轮转矩阵
#
# https://leetcode.cn/problems/cyclically-rotating-a-grid/description/
#
# algorithms
# Medium (48.96%)
# Likes:    33
# Dislikes: 0
# Total Accepted:    6.3K
# Total Submissions: 12.2K
# Testcase Example:  '[[40,10],[30,20]]\n1'
#
# 给你一个大小为 m x n 的整数矩阵 grid​​​ ，其中 m 和 n 都是 偶数 ；另给你一个整数 k 。
#
# 矩阵由若干层组成，如下图所示，每种颜色代表一层：
#
#
#
# 矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 逆时针
# 方向的相邻元素。轮转示例如下：
#
# 返回执行 k 次循环轮转操作后的矩阵。
#
#
#
# 示例 1：
#
# 输入：grid = [[40,10],[30,20]], k = 1
# 输出：[[10,20],[40,30]]
# 解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。
#
# 示例 2：
# ⁠
#
# 输入：grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
# 输出：[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
# 解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。
#
#
#
#
# 提示：
#
#
# m == grid.length
# n == grid[i].length
# 2 <= m, n <= 50
# m 和 n 都是 偶数
# 1 <= grid[i][j] <=^ 5000
# 1 <= k <= 10^9
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        layers = min(m, n) // 2

        for l in range(layers):
            # 按顺时针方向提取当前层的所有元素
            layer = []
            # 上边：从左到右
            for j in range(l, n - l):
                layer.append(grid[l][j])
            # 右边：从上到下（跳过左上角，因为已在上边末尾取过）
            for i in range(l + 1, m - l):
                layer.append(grid[i][n - 1 - l])
            # 下边：从右到左（跳过右下角）
            for j in range(n - 2 - l, l - 1, -1):
                layer.append(grid[m - 1 - l][j])
            # 左边：从下到上（跳过左下角和左上角）
            for i in range(m - 2 - l, l, -1):
                layer.append(grid[i][l])

            # 计算有效旋转次数：逆时针 k 次 = 顺时针列表左移 k 位
            if not layer:
                continue
            length = len(layer)
            k_eff = k % length
            rotated = layer[k_eff:] + layer[:k_eff]

            # 按同样顺序写回
            idx = 0
            # 上边
            for j in range(l, n - l):
                grid[l][j] = rotated[idx]
                idx += 1
            # 右边
            for i in range(l + 1, m - l):
                grid[i][n - 1 - l] = rotated[idx]
                idx += 1
            # 下边
            for j in range(n - 2 - l, l - 1, -1):
                grid[m - 1 - l][j] = rotated[idx]
                idx += 1
            # 左边
            for i in range(m - 2 - l, l, -1):
                grid[i][l] = rotated[idx]
                idx += 1

        return grid


# @lc code=end


#
# @lcpr case=start
# [[40,10],[30,20]]\n1\n
# @lcpr case=end

# @lcpr case=start
# [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n2\n
# @lcpr case=end

#
