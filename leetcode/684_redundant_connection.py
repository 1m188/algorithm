#
# @lc app=leetcode.cn id=684 lang=python3
# @lcpr version=30204
#
# [684] 冗余连接
#
# https://leetcode.cn/problems/redundant-connection/description/
#
# algorithms
# Medium (68.80%)
# Likes:    736
# Dislikes: 0
# Total Accepted:    150K
# Total Submissions: 218K
# Testcase Example:  '[[1,2],[1,3],[2,3]]'
#
# 树可以看成是一个连通且 无环 的 无向 图。
#
# 给定一个图，该图从一棵 n 个节点 (节点值 1～n) 的树中添加一条边后获得。添加的边的两个不同顶点编号在 1 到 n
# 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和
# bi 之间存在一条边。
#
# 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
#
#
#
# 示例 1：
#
#
#
# 输入: edges = [[1,2], [1,3], [2,3]]
# 输出: [2,3]
#
#
# 示例 2：
#
#
#
# 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
# 输出: [1,4]
#
#
#
#
# 提示:
#
#
# n == edges.length
# 3 <= n <= 1000
# edges[i].length == 2
# 1 <= ai < bi <= edges.length
# ai != bi
# edges 中无重复元素
# 给定的图是连通的
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))  # 节点编号 1~n

        def find(x: int) -> int:
            """带路径压缩的查找"""
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            """合并两个集合"""
            root_x = find(x)
            root_y = find(y)
            if root_x != root_y:
                parent[root_x] = root_y

        result = None
        for u, v in edges:
            if find(u) == find(v):
                # u 和 v 已连通，当前边即为冗余边
                result = [u, v]
            else:
                union(u, v)

        return result


# @lc code=end


#
# @lcpr case=start
# [[1,2], [1,3], [2,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
# @lcpr case=end

#
