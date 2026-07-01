#
# @lc app=leetcode.cn id=LCP 03 lang=python3
# @lcpr version=30204
#
# [LCP 03] 机器人大冒险
#
# https://leetcode.cn/problems/programmable-robot/description/
#
# algorithms
# Medium (24.27%)
# Likes:    145
# Dislikes: 0
# Total Accepted:    18K
# Total Submissions: 74.2K
# Testcase Example:  '"URR"\n[]\n3\n2'
#
# 力扣团队买了一个可编程机器人，机器人初始位置在原点(0,
# 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：
#
#
# U: 向y轴正方向移动一格
# R: 向x轴正方向移动一格。
#
#
# 不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。
#
# 给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。
#
#
#
# 示例 1：
#
# 输入：command = "URR", obstacles = [], x = 3, y = 2
# 输出：true
# 解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
#
# 示例 2：
#
# 输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
# 输出：false
# 解释：机器人在到达终点前会碰到(2, 2)的障碍物。
#
# 示例 3：
#
# 输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
# 输出：true
# 解释：到达终点后，再碰到障碍物也不影响返回结果。
#
#
#
# 限制：
#
#
# 2 <= command的长度 <= 1000
# command由U，R构成，且至少有一个U，至少有一个R
# 0 <= x <= 1e9, 0 <= y <= 1e9
# 0 <= obstacles的长度 <= 1000
# obstacles[i]不为原点或者终点
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        """
        周期性 + 前缀轨迹 + 同余校验

        核心思路：
        - 指令 command 无限循环，一次完整指令移动 (dR, dU)
        - 第 i 步前缀位置记为 (r_i, u_i)（0 <= i < m）
        - 到达 (px, py) 等价于存在 i 和 k >= 0 使得:
            px = k * dR + r_i,  py = k * dU + u_i
        - 因此需要 px >= r_i, py >= u_i, 且 k = (px - r_i) / dR = (py - u_i) / dU
        - 对终点和每个障碍物分别计算最少步数，障碍物步数需严格大于终点步数
        """
        m = len(command)

        # 预计算每一步指令后的前缀位置
        prefix: list = [(0, 0)]  # prefix[i] = 执行 i 步后的 (r, u)
        r = u = 0
        for ch in command:
            if ch == "R":
                r += 1
            else:
                u += 1
            prefix.append((r, u))

        dR, dU = r, u  # 一次完整指令的位移

        def min_steps(px: int, py: int) -> int:
            """返回到达 (px, py) 的最少步数，若不可达返回 inf"""
            ans = float("inf")
            for i, (ri, ui) in enumerate(prefix):
                if px < ri or py < ui:
                    continue
                if (px - ri) % dR != 0:
                    continue
                if (py - ui) % dU != 0:
                    continue
                kx = (px - ri) // dR
                ku = (py - ui) // dU
                if kx != ku:
                    continue
                # kx 轮完整指令 + 当前前缀 i 步
                steps = kx * m + i
                if steps < ans:
                    ans = steps
            return ans

        # 计算到达终点的步数
        target_steps = min_steps(x, y)
        if target_steps == float("inf"):
            return False

        # 检查每个障碍物是否会在到达终点前被碰到
        for ox, oy in obstacles:
            obs_steps = min_steps(ox, oy)
            if obs_steps < target_steps:
                return False

        return True


# @lc code=end


#
# @lcpr case=start
# "URR"\n[]\n3\n2\n
# @lcpr case=end

# @lcpr case=start
# "URR"\n[[2, 2]]\n3\n2\n
# @lcpr case=end

# @lcpr case=start
# "URR"\n[[4, 2]]\n3\n2\n
# @lcpr case=end

#
