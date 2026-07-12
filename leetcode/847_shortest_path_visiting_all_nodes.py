#
# @lc app=leetcode.cn id=847 lang=python3
# @lcpr version=30204
#
# [847] 访问所有节点的最短路径
#
# https://leetcode.cn/problems/shortest-path-visiting-all-nodes/description/
#
# algorithms
# Hard (67.63%)
# Likes:    435
# Dislikes: 0
# Total Accepted:    32.4K
# Total Submissions: 47.8K
# Testcase Example:  '[[1,2,3],[0],[0],[0]]'
#
# 存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。
#
# 给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。
#
# 返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。
#
#
#
#
#
#
# 示例 1：
#
# 输入：graph = [[1,2,3],[0],[0],[0]]
# 输出：4
# 解释：一种可能的路径为 [1,0,2,0,3]
#
# 示例 2：
#
#
#
# 输入：graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
# 输出：4
# 解释：一种可能的路径为 [0,1,4,2,3]
#
#
#
#
# 提示：
#
#
# n == graph.length
# 1 <= n <= 12
# 0 <= graph[i].length < n
# graph[i] 不包含 i
# 如果 graph[a] 包含 b ，那么 graph[b] 也包含 a
# 输入的图总是连通图
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        """
        BFS + 状态压缩（位掩码）

        核心思路：
        - n ≤ 12，用位掩码 mask 表示已访问节点集合
        - 状态为 (node, mask)，表示当前在 node 且已访问集合为 mask
        - BFS 从所有 (i, 1<<i) 出发，求最短到达 mask == (1<<n)-1 的距离
        """
        from collections import deque

        n = len(graph)
        full_mask = (1 << n) - 1

        # 所有初始状态：每个节点单独出发
        q = deque()
        # visited[node][mask] 记录是否访问过
        visited = [[False] * (1 << n) for _ in range(n)]

        for i in range(n):
            q.append((i, 1 << i, 0))
            visited[i][1 << i] = True

        while q:
            node, mask, dist = q.popleft()

            if mask == full_mask:
                return dist

            for nxt in graph[node]:
                new_mask = mask | (1 << nxt)
                if not visited[nxt][new_mask]:
                    visited[nxt][new_mask] = True
                    q.append((nxt, new_mask, dist + 1))

        return 0  # n == 1 的情况


# @lc code=end


#
# @lcpr case=start
# [[1,2,3],[0],[0],[0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1],[0,2,4],[1,3,4],[2],[1,2]]\n
# @lcpr case=end

#
