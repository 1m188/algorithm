#
# @lc app=leetcode.cn id=57 lang=python3
#
# [57] 插入区间
#
# https://leetcode-cn.com/problems/insert-interval/description/
#
# algorithms
# Medium (41.43%)
# Likes:    567
# Dislikes: 0
# Total Accepted:    103.5K
# Total Submissions: 249.9K
# Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
#
# 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
#
# 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
#
#
#
# 示例 1：
#
#
# 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
# 输出：[[1,5],[6,9]]
#
#
# 示例 2：
#
#
# 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# 输出：[[1,2],[3,10],[12,16]]
# 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
#
# 示例 3：
#
#
# 输入：intervals = [], newInterval = [5,7]
# 输出：[[5,7]]
#
#
# 示例 4：
#
#
# 输入：intervals = [[1,5]], newInterval = [2,3]
# 输出：[[1,5]]
#
#
# 示例 5：
#
#
# 输入：intervals = [[1,5]], newInterval = [2,7]
# 输出：[[1,7]]
#
#
#
#
# 提示：
#
#
# 0 <= intervals.length <= 10^4
# intervals[i].length == 2
# 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
# intervals 根据 intervals[i][0] 按 升序 排列
# newInterval.length == 2
# 0 <= newInterval[0] <= newInterval[1] <= 10^5
#
#
#

from typing import List


# @lc code=start
class Solution:

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        if not intervals:
            return [newInterval]

        start, end = 0, len(intervals) - 1
        while start <= end:
            i = int((start + end) / 2)
            if intervals[i][0] == newInterval[0]:
                break
            elif intervals[i][0] > newInterval[0]:
                end = i - 1
            else:
                start = i + 1

        if newInterval[0] >= intervals[i][1] or (newInterval[0] >= intervals[i][0] and newInterval[1] >= intervals[i][1]):
            intervals.insert(i + 1, newInterval)
            i += 1
        elif newInterval[1] <= intervals[i][0] or (newInterval[0] <= intervals[i][0] and newInterval[1] <= intervals[i][1]):
            intervals.insert(i, newInterval)
        elif newInterval[0] <= intervals[i][0] and newInterval[1] >= intervals[i][1]:
            intervals[i] = newInterval
        else:
            return intervals

        self.combine(intervals, i)

        return intervals

    def combine(self, li: List[List[int]], index: int):

        while index - 1 >= 0 and li[index - 1][1] >= li[index][0]:
            li[index][0] = min(li[index - 1][0], li[index][0])
            li[index][1] = max(li[index - 1][1], li[index][1])
            li.pop(index - 1)
            index -= 1

        while index + 1 < len(li) and li[index + 1][0] <= li[index][1]:
            li[index][0] = min(li[index + 1][0], li[index][0])
            li[index][1] = max(li[index + 1][1], li[index][1])
            li.pop(index + 1)


# @lc code=end
