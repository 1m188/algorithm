#
# @lc app=leetcode.cn id=1743 lang=python3
# @lcpr version=30204
#
# [1743] 从相邻元素对还原数组
#
# https://leetcode.cn/problems/restore-the-array-from-adjacent-pairs/description/
#
# algorithms
# Medium (69.80%)
# Likes:    133
# Dislikes: 0
# Total Accepted:    26.8K
# Total Submissions: 38.4K
# Testcase Example:  '[[2,1],[3,4],[3,2]]'
#
# 存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
#
# 给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui
# 和 vi 在 nums 中相邻。
#
# 题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是
# [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。
#
# 返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
#
#
#
# 示例 1：
#
# 输入：adjacentPairs = [[2,1],[3,4],[3,2]]
# 输出：[1,2,3,4]
# 解释：数组的所有相邻元素对都在 adjacentPairs 中。
# 特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
#
#
# 示例 2：
#
# 输入：adjacentPairs = [[4,-2],[1,4],[-3,1]]
# 输出：[-2,4,1,-3]
# 解释：数组中可能存在负数。
# 另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
#
#
# 示例 3：
#
# 输入：adjacentPairs = [[100000,-100000]]
# 输出：[100000,-100000]
#
#
#
#
# 提示：
#
#
# nums.length == n
# adjacentPairs.length == n - 1
# adjacentPairs[i].length == 2
# 2 <= n <= 10^5
# -10^5 <= nums[i], ui, vi <= 10^5
# 题目数据保证存在一些以 adjacentPairs 作为元素对的数组 nums
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        """
        图遍历还原序列

        核心思路：
        - 将相邻对视为无向图的边，构建邻接表
        - 数组两端元素在图中度数为 1，中间元素度数为 2
        - 从任意度为 1 的节点出发，沿邻接边依次遍历即可还原数组
        """
        from collections import defaultdict

        adj = defaultdict(list)
        for u, v in adjacentPairs:
            adj[u].append(v)
            adj[v].append(u)

        # 找起点：度数为 1 的节点（数组端点）
        start = next(node for node, neighbors in adj.items() if len(neighbors) == 1)

        n = len(adjacentPairs) + 1
        result = [0] * n
        result[0] = start
        # 第二个位置是起点唯一的邻居
        result[1] = adj[start][0]

        for i in range(2, n):
            # 当前位置的前一个节点的邻居中，排除已经填入的前两个位置
            prev = result[i - 1]
            for neighbor in adj[prev]:
                if neighbor != result[i - 2]:
                    result[i] = neighbor
                    break

        return result


# @lc code=end


#
# @lcpr case=start
# [[2,1],[3,4],[3,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[4,-2],[1,4],[-3,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[100000,-100000]]\n
# @lcpr case=end

#
