#
# @lc app=leetcode.cn id=352 lang=python3
# @lcpr version=30204
#
# [352] 将数据流变为多个不相交区间
#
# https://leetcode.cn/problems/data-stream-as-disjoint-intervals/description/
#
# algorithms
# Hard (66.54%)
# Likes:    210
# Dislikes: 0
# Total Accepted:    28.8K
# Total Submissions: 43.2K
# Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
#  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
#
# 给你一个由非负整数组成的数据流输入 a1, a2, ..., an，请你将目前为止看到的数字汇总为一组不相交的区间列表。
#
# 实现 SummaryRanges 类：
#
#
# SummaryRanges() 初始化一个空的数据流对象。
# void addNum(int value) 将整数 value 添加到数据流中。
# int[][] getIntervals() 返回当前数据流中的整数汇总为一组不相交的区间列表 [starti, endi]。答案应按 starti
# 升序排序。
#
#
#
#
# 示例 1：
#
# 输入
# ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
# "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
# [[], [1], [], [3], [], [7], [], [2], [], [6], []]
# 输出
# [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
# 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
#
# 解释
# SummaryRanges summaryRanges = new SummaryRanges();
# summaryRanges.addNum(1);      // arr = [1]
# summaryRanges.getIntervals(); // 返回 [[1, 1]]
# summaryRanges.addNum(3);      // arr = [1, 3]
# summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
# summaryRanges.addNum(7);      // arr = [1, 3, 7]
# summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
# summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
# summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
# summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
# summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
#
#
#
#
# 提示：
#
#
# 0 <= value <= 10^4
# 最多会调用 addNum 和 getIntervals 方法 3 * 10^4 次。
# 最多会调用 getIntervals 方法 10^2 次。
#
#
#
#
# 进阶：如果存在大量合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class SummaryRanges:
    """
    维护一组不相交的有序区间

    方案：维护有序的区间列表 intervals（每个区间为 [start, end]）。
    addNum 时二分查找插入位置，分情况处理：
    - 值已在某区间内：无操作
    - 值与前后区间相邻：扩展区间或合并两个区间
    - 值孤立：插入新区间 [value, value]
    """

    def __init__(self):
        """初始化空的数据流对象"""
        self.intervals: List[List[int]] = []

    def addNum(self, value: int) -> None:
        """
        将整数 value 添加到数据流中，维护不相交的区间列表
        使用二分查找定位插入位置 O(log n)，合并操作 O(1)
        """
        from bisect import bisect_left

        intervals = self.intervals
        n = len(intervals)

        # 二分查找：找到 value 在 starts 中的插入位置 idx
        starts = [it[0] for it in intervals]
        idx = bisect_left(starts, value)

        # 情况1：value 已经落在某个已有区间内
        # 检查前一个区间（value 在 start 之后，可能落在内部）
        if idx > 0 and intervals[idx - 1][0] <= value <= intervals[idx - 1][1]:
            return
        # 检查当前区间（value 恰好等于某区间 start 时，idx 指向该区间）
        if idx < n and intervals[idx][0] <= value <= intervals[idx][1]:
            return

        # 判断 value 是否与前后区间相邻（相差为 1 即可合并）
        left_adj = idx > 0 and intervals[idx - 1][1] + 1 == value
        right_adj = idx < n and intervals[idx][0] - 1 == value

        if left_adj and right_adj:
            # 连接左右两个区间，将它们合并
            intervals[idx - 1][1] = intervals[idx][1]
            intervals.pop(idx)
        elif left_adj:
            # 扩展前一个区间的右端点
            intervals[idx - 1][1] = value
        elif right_adj:
            # 扩展后一个区间的左端点
            intervals[idx][0] = value
        else:
            # 孤立值，插入新区间
            intervals.insert(idx, [value, value])

    def getIntervals(self) -> List[List[int]]:
        """返回当前所有不相交的区间列表（已按 start 升序排列）"""
        return self.intervals


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()
# @lc code=end
