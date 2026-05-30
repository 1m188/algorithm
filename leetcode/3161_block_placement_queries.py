#
# @lc app=leetcode.cn id=3161 lang=python3
# @lcpr version=30204
#
# [3161] 物块放置查询
#
# https://leetcode.cn/problems/block-placement-queries/description/
#
# algorithms
# Hard (21.48%)
# Likes:    19
# Dislikes: 0
# Total Accepted:    3K
# Total Submissions: 14K
# Testcase Example:  '[[1,2],[2,3,3],[2,3,1],[2,2,2]]'
#
# 有一条无限长的数轴，原点在 0 处，沿着 x 轴 正 方向无限延伸。
#
# 给你一个二维数组 queries ，它包含两种操作：
#
#
# 操作类型 1 ：queries[i] = [1, x] 。在距离原点 x 处建一个障碍物。数据保证当操作执行的时候，位置 x 处 没有
# 任何障碍物。
# 操作类型 2 ：queries[i] = [2, x, sz] 。判断在数轴范围 [0, x] 内是否可以放置一个长度为 sz 的物块，这个物块需要 完全
# 放置在范围 [0, x] 内。如果物块与任何障碍物有重合，那么这个物块 不能 被放置，但物块可以与障碍物刚好接触。注意，你只是进行查询，并 不是
# 真的放置这个物块。每个查询都是相互独立的。
#
#
# 请你返回一个 boolean 数组results ，如果第 i 个操作类型 2 的操作你可以放置物块，那么 results[i] 为 true ，否则为
# false 。
#
#
#
# 示例 1：
#
#
# 输入：queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
#
# 输出：[false,true,true]
#
# 解释：
#
#
#
# 查询 0 ，在 x = 2 处放置一个障碍物。在 x = 3 之前任何大小不超过 2 的物块都可以被放置。
#
#
# 示例 2：
#
#
# 输入：queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]
#
# 输出：[true,true,false]
#
# 解释：
#
#
#
#
# 查询 0 在 x = 7 处放置一个障碍物。在 x = 7 之前任何大小不超过 7 的物块都可以被放置。
# 查询 2 在 x = 2 处放置一个障碍物。现在，在 x = 7 之前任何大小不超过 5 的物块可以被放置，x = 2 之前任何大小不超过 2
# 的物块可以被放置。
#
#
#
#
#
# 提示：
#
#
# 1 <= queries.length <= 15 * 10^4
# 2 <= queries[i].length <= 3
# 1 <= queries[i][0] <= 2
# 1 <= x, sz <= min(5 * 10^4, 3 * queries.length)
# 输入保证操作 1 中，x 处不会有障碍物。
# 输入保证至少有一个操作类型 2 。
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        # 找出最大坐标，用于确定线段树的范围
        max_x = 0
        for q in queries:
            if q[1] > max_x:
                max_x = q[1]

        n = max_x + 1  # 坐标范围 [0, max_x]

        # 线段树：记录每个区间内最左障碍、最右障碍、障碍间最大间距
        size = 4 * n
        left_obs = [-1] * size  # 区间内最左障碍坐标，-1 表示没有
        right_obs = [-1] * size  # 区间内最右障碍坐标
        max_gap = [0] * size  # 区间内相邻障碍的最大间距

        def push_up(node: int) -> None:
            """用左右子节点的信息更新当前节点"""
            lc = node * 2
            rc = node * 2 + 1
            l1, r1, g1 = left_obs[lc], right_obs[lc], max_gap[lc]
            l2, r2, g2 = left_obs[rc], right_obs[rc], max_gap[rc]

            if l1 == -1:
                left_obs[node] = l2
                right_obs[node] = r2
                max_gap[node] = g2
            elif l2 == -1:
                left_obs[node] = l1
                right_obs[node] = r1
                max_gap[node] = g1
            else:
                left_obs[node] = l1
                right_obs[node] = r2
                max_gap[node] = max(g1, g2, l2 - r1)

        def update(node: int, l: int, r: int, pos: int) -> None:
            """在坐标 pos 处放置障碍物"""
            if l == r:
                left_obs[node] = pos
                right_obs[node] = pos
                max_gap[node] = 0
                return
            mid = (l + r) // 2
            if pos <= mid:
                update(node * 2, l, mid, pos)
            else:
                update(node * 2 + 1, mid + 1, r, pos)
            push_up(node)

        def query(node: int, l: int, r: int, ql: int, qr: int):
            """查询区间 [ql, qr] 内障碍物的信息
            返回 (最左障碍, 最右障碍, 最大相邻间距)
            """
            if ql > r or qr < l:
                return (-1, -1, 0)
            if ql <= l and r <= qr:
                return (left_obs[node], right_obs[node], max_gap[node])
            mid = (l + r) // 2
            left_res = query(node * 2, l, mid, ql, qr)
            right_res = query(node * 2 + 1, mid + 1, r, ql, qr)

            l1, r1, g1 = left_res
            l2, r2, g2 = right_res

            if l1 == -1:
                return (l2, r2, g2)
            if l2 == -1:
                return (l1, r1, g1)
            return (l1, r2, max(g1, g2, l2 - r1))

        results: List[bool] = []
        for q in queries:
            if q[0] == 1:
                _, x = q
                update(1, 0, n - 1, x)
            else:
                _, x, sz = q
                first, last, gap_between = query(1, 0, n - 1, 0, x)

                max_free = gap_between
                if first != -1:
                    max_free = max(max_free, first)  # 0 到第一个障碍的距离
                if last != -1:
                    max_free = max(max_free, x - last)  # 最后一个障碍到 x 的距离
                else:
                    max_free = max(max_free, x)  # 没有障碍，整个 [0, x] 都是空的

                results.append(max_free >= sz)

        return results


# @lc code=end


#
# @lcpr case=start
# [[1,2],[2,3,3],[2,3,1],[2,2,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]\n
# @lcpr case=end

#
