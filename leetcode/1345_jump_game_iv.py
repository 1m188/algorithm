#
# @lc app=leetcode.cn id=1345 lang=python3
# @lcpr version=30204
#
# [1345] 跳跃游戏 IV
#
# https://leetcode.cn/problems/jump-game-iv/description/
#
# algorithms
# Hard (45.54%)
# Likes:    286
# Dislikes: 0
# Total Accepted:    35.3K
# Total Submissions: 76.3K
# Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
#
# 给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。
#
# 每一步，你可以从下标 i 跳到下标 i + 1 、i - 1 或者 j ：
#
#
# i + 1 需满足：i + 1 < arr.length
# i - 1 需满足：i - 1 >= 0
# j 需满足：arr[i] == arr[j] 且 i != j
#
#
# 请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。
#
# 注意：任何时候你都不能跳到数组外面。
#
#
#
# 示例 1：
#
# 输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
# 输出：3
# 解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
#
#
# 示例 2：
#
# 输入：arr = [7]
# 输出：0
# 解释：一开始就在最后一个元素处，所以你不需要跳跃。
#
#
# 示例 3：
#
# 输入：arr = [7,6,9,6,9,6,9,7]
# 输出：1
# 解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
#
#
#
#
# 提示：
#
#
#
# 1 <= arr.length <= 5 * 10^4
# -10^8 <= arr[i] <= 10^8
#
#
#

from typing import List


# @lc code=start
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        from collections import deque, defaultdict

        n = len(arr)
        if n == 1:
            return 0

        # 建立值到下标列表的映射，用于"同值跳跃"
        val_to_indices = defaultdict(list)
        for i, v in enumerate(arr):
            val_to_indices[v].append(i)

        # BFS 求最短路径（最少操作次数）
        q = deque([0])
        dist = [-1] * n
        dist[0] = 0

        while q:
            i = q.popleft()
            d = dist[i]

            # 目标达到
            if i == n - 1:
                return d

            # 邻居 1: i + 1
            if i + 1 < n and dist[i + 1] == -1:
                dist[i + 1] = d + 1
                q.append(i + 1)

            # 邻居 2: i - 1
            if i - 1 >= 0 and dist[i - 1] == -1:
                dist[i - 1] = d + 1
                q.append(i - 1)

            # 邻居 3: 同值跳跃（所有值为 arr[i] 的其他下标）
            if arr[i] in val_to_indices:
                for j in val_to_indices[arr[i]]:
                    if j != i and dist[j] == -1:
                        dist[j] = d + 1
                        q.append(j)
                # 关键优化：同值列表用一次后立即清空，
                # 避免后续重复遍历造成 O(n^2) 复杂度
                del val_to_indices[arr[i]]

        return dist[n - 1]


# @lc code=end


#
# @lcpr case=start
# [100,-23,-23,404,100,23,23,23,3,404]\n
# @lcpr case=end

# @lcpr case=start
# [7]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,9,6,9,6,9,7]\n
# @lcpr case=end

#
