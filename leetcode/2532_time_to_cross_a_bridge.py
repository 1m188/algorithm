#
# @lc app=leetcode.cn id=2532 lang=python3
# @lcpr version=30204
#
# [2532] 过桥的时间
#
# https://leetcode.cn/problems/time-to-cross-a-bridge/description/
#
# algorithms
# Hard (67.45%)
# Likes:    95
# Dislikes: 0
# Total Accepted:    11.1K
# Total Submissions: 16.4K
# Testcase Example:  '1\n3\n[[1,1,2,1],[1,1,3,1],[1,1,4,1]]'
#
# 共有 k 位工人计划将 n 个箱子从右侧的（旧）仓库移动到左侧的（新）仓库。给你两个整数 n 和 k，以及一个二维整数数组 time ，数组的大小为 k
# x 4 ，其中 time[i] = [righti, picki, lefti, puti] 。
#
# 一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 k 位工人都在桥的左侧等待。为了移动这些箱子，第 i
# 位工人（下标从 0 开始）可以：
#
#
# 从左岸（新仓库）跨过桥到右岸（旧仓库），用时 righti 分钟。
# 从旧仓库选择一个箱子，并返回到桥边，用时 picki 分钟。不同工人可以同时搬起所选的箱子。
# 从右岸（旧仓库）跨过桥到左岸（新仓库），用时 lefti 分钟。
# 将箱子放入新仓库，并返回到桥边，用时 puti 分钟。不同工人可以同时放下所选的箱子。
#
#
# 如果满足下面任一条件，则认为工人 i 的 效率低于 工人 j ：
#
#
# lefti + righti > leftj + rightj
# lefti + righti == leftj + rightj 且 i > j
#
#
# 工人通过桥时需要遵循以下规则：
#
#
# 同时只能有一名工人过桥。
# 当桥梁未被使用时，优先让右侧 效率最低 的工人（已经拿起盒子的工人）过桥。如果不是，优先让左侧 效率最低 的工人通过。
# 如果左侧已经派出足够的工人来拾取所有剩余的箱子，则 不会 再从左侧派出工人。
#
#
# 请你返回最后一个箱子 到达桥左侧 的时间。
#
#
#
# 示例 1：
#
#
# 输入：n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
#
# 输出：6
#
# 解释：
#
# 从 0 到 1 分钟：工人 2 通过桥到达右侧。
# 从 1 到 2 分钟：工人 2 从右侧仓库拿起箱子。
# 从 2 到 6 分钟：工人 2 通过桥到达左侧。
# 从 6 到 7 分钟：工人 2 向左侧仓库放下箱子。
# 整个过程在 7 分钟后结束。我们返回 6 因为该问题要求的是最后一名工人到达桥梁左侧的时间。
#
#
#
# 示例 2：
#
#
# 输入：n = 3, k = 2, time = [[1,5,1,8],[10,10,10,10]]
#
# 输出：37
#
# 解释：
#
#
#
#
# 最后一个盒子在37秒时到达左侧。请注意，我们并 没有 放下最后一个箱子，因为那样会花费更多时间，而且它们已经和工人们一起在左边。
#
#
#
#
# 提示：
#
#
# 1 <= n, k <= 10^4
# time.length == k
# time[i].length == 4
# 1 <= lefti, picki, righti, puti <= 1000
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def findCrossingTime(self, n: int, k: int, time: List[List[int]]) -> int:
        # 将每位工人的四个耗时分别提取到独立数组中，方便按索引访问
        R = [t[0] for t in time]  # right: 从左岸过桥到右岸的耗时
        P = [t[1] for t in time]  # pick:  在右岸旧仓库搬起箱子的耗时
        L = [t[2] for t in time]  # left:  从右岸过桥回左岸的耗时
        U = [t[3] for t in time]  # put:   在左岸新仓库放下箱子的耗时

        # 效率定义：left_i + right_i 越大效率越低；相等时下标越大效率越低
        # Python 堆是最小堆，需要将"最优先"的元素放在堆顶
        # key = (-(left+right), -index, index)，元组按字典序比较
        # -(left+right) 越"小"（即 left+right 越大）的越先出堆
        # -(index) 越"小"（即 index 越大）的越先出堆（效率相同时的 tie-break）
        left_wait = [(-(L[i] + R[i]), -i, i) for i in range(k)]
        import heapq

        heapq.heapify(left_wait)  # 初始所有工人都在左岸等待
        right_wait = []  # 右岸等待过桥的工人（已搬起箱子）

        # 事件队列：记录工人完成非过桥任务（搬起/放下）的时间点
        pick_done = []  # (完成时刻, 工人编号) — 在右岸完成搬起，可加入 right_wait
        put_done = []  # (完成时刻, 工人编号) — 在左岸完成放下，可加入 left_wait

        cur = 0  # 当前模拟时刻
        sent_right = 0  # 已从左岸派往右岸的工人次数（即已分配的箱子数）
        arrived = 0  # 已到达左岸的箱子数
        last_arrival = 0  # 最后一个箱子到达左岸的时刻

        while arrived < n:
            # 1. 处理当前时刻之前（含）已完成搬起任务的工人 → 加入 right_wait
            while pick_done and pick_done[0][0] <= cur:
                t, i = heapq.heappop(pick_done)
                heapq.heappush(right_wait, (-(L[i] + R[i]), -i, i))

            # 2. 处理当前时刻之前（含）已完成放下任务的工人 → 加入 left_wait
            while put_done and put_done[0][0] <= cur:
                t, i = heapq.heappop(put_done)
                heapq.heappush(left_wait, (-(L[i] + R[i]), -i, i))

            # 3. 桥梁调度：右侧优先；右侧空则左侧（且还需搬箱子）
            if right_wait:
                # 右侧工人过桥回左岸（携带箱子）
                _, _, i = heapq.heappop(right_wait)
                cur += L[i]  # 过桥耗时
                heapq.heappush(put_done, (cur + U[i], i))  # 规划放下完成事件
                arrived += 1
                last_arrival = cur  # 箱子到达左岸的时刻
            elif left_wait and sent_right < n:
                # 左侧工人过桥去右岸（去搬箱子）
                _, _, i = heapq.heappop(left_wait)
                cur += R[i]  # 过桥耗时
                sent_right += 1
                heapq.heappush(pick_done, (cur + P[i], i))  # 规划搬起完成事件
            else:
                # 无人可用桥：快进到下一个最早事件的发生时刻
                next_t = float("inf")
                if pick_done:
                    next_t = min(next_t, pick_done[0][0])
                if put_done:
                    next_t = min(next_t, put_done[0][0])
                cur = next_t

        return last_arrival


# @lc code=end


#
# @lcpr case=start
# 1\n3\n[[1,1,2,1],[1,1,3,1],[1,1,4,1]]\n
# @lcpr case=end

# @lcpr case=start
# 3\n2\n[[1,5,1,8],[10,10,10,10]]\n
# @lcpr case=end

#
