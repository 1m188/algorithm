#
# @lc app=leetcode.cn id=1288 lang=python3
#
# [1288] 删除被覆盖区间
#
# https://leetcode-cn.com/problems/remove-covered-intervals/description/
#
# algorithms
# Medium (54.76%)
# Likes:    14
# Dislikes: 0
# Total Accepted:    3.2K
# Total Submissions: 5.8K
# Testcase Example:  '[[1,4],[3,6],[2,8]]'
#
# 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
#
# 只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
#
# 在完成所有删除操作后，请你返回列表中剩余区间的数目。
#
#
#
# 示例：
#
#
# 输入：intervals = [[1,4],[3,6],[2,8]]
# 输出：2
# 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
#
#
#
#
# 提示：​​​​​​
#
#
# 1 <= intervals.length <= 1000
# 0 <= intervals[i][0] < intervals[i][1] <= 10^5
# 对于所有的 i != j：intervals[i] != intervals[j]
#
#
#

from typing import List


# @lc code=start
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        def jud(intval):
            m, n = intval
            if m[0] <= n[0] and m[1] >= n[1]:
                return 1
            elif n[0] <= m[0] and n[1] >= m[1]:
                return 0
            else:
                return -1

        intervals.sort(key=lambda x: x[0])
        idx = 0
        while idx < len(intervals) - 1:
            ridx = jud((intervals[idx], intervals[idx + 1]))
            if ridx == -1:
                idx += 1
            else:
                intervals.pop(idx + ridx)
        return len(intervals)


# @lc code=end
