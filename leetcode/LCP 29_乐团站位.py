#
# @lc app=leetcode.cn id=LCP 29 lang=python3
# @lcpr version=30204
#
# [LCP 29] 乐团站位
#
# https://leetcode.cn/problems/SNJvJP/description/
#
# algorithms
# Medium (21.63%)
# Likes:    78
# Dislikes: 0
# Total Accepted:    9.3K
# Total Submissions: 43.1K
# Testcase Example:  '3\n0\n2'
#
# 某乐团的演出场地可视作 `num * num` 的二维矩阵 `grid`（左上角坐标为 `[0,0]`)，每个位置站有一位成员。乐团共有 `9`
# 种乐器，乐器编号为 `1~9`，每位成员持有 `1` 个乐器。
#
# 为保证声乐混合效果，成员站位规则为：自 `grid` 左上角开始顺时针螺旋形向内循环以 `1，2，...，9` 循环重复排列。例如当 num = `5`
# 时，站位如图所示
#
# ![image.png](https://pic.leetcode.cn/1616125411-WOblWH-image.png)
#
#
# 请返回位于场地坐标 [`Xpos`,`Ypos`] 的成员所持乐器编号。
#
# **示例 1：**
# >输入：`num = 3, Xpos = 0, Ypos = 2`
# >
# >输出：`3`
# >
# >解释：
# ![image.png](https://pic.leetcode.cn/1616125437-WUOwsu-image.png)
#
#
# **示例 2：**
# >输入：`num = 4, Xpos = 1, Ypos = 2`
# >
# >输出：`5`
# >
# >解释：
# ![image.png](https://pic.leetcode.cn/1616125453-IIDpxg-image.png)
#
#
# **提示：**
# - `1 <= num <= 10^9`
# - `0 <= Xpos, Ypos < num`
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def orchestraLayout(self, num: int, xPos: int, yPos: int) -> int:
        # 确定当前位置所在的圈（从外到内，0 为最外层）
        k = min(xPos, yPos, num - 1 - xPos, num - 1 - yPos)

        # 外层 k 圈共有多少格子：4*k*(num - k)
        total_before = 4 * k * (num - k)

        # 在当前圈内的边长（每个边除去起点的步数）
        side_len = num - 2 * k - 1

        # 中心点单独处理
        if side_len == 0:
            offset = 0
        elif xPos == k:
            # 上边，向右走
            offset = yPos - k
        elif yPos == num - 1 - k:
            # 右边，向下走
            offset = side_len + (xPos - k)
        elif xPos == num - 1 - k:
            # 下边，向左走
            offset = 2 * side_len + (num - 1 - k - yPos)
        else:
            # 左边，向上走
            offset = 3 * side_len + (num - 1 - k - xPos)

        # 在整个螺旋中的位置（从 1 开始）
        position = total_before + offset + 1

        # 乐器编号为 1~9 循环
        return (position - 1) % 9 + 1


# @lc code=end


#
# @lcpr case=start
# 3\n0\n2`>\n
# @lcpr case=end

# @lcpr case=start
# 4\n1\n2`>\n
# @lcpr case=end

#
