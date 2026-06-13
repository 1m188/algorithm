#
# @lc app=leetcode.cn id=2349 lang=python3
# @lcpr version=30204
#
# [2349] 设计数字容器系统
#
# https://leetcode.cn/problems/design-a-number-container-system/description/
#
# algorithms
# Medium (49.58%)
# Likes:    62
# Dislikes: 0
# Total Accepted:    22.6K
# Total Submissions: 45.5K
# Testcase Example:  '["NumberContainers","find","change","change","change","change","find","change","find"]\n' +
#  '[[],[10],[2,10],[1,10],[3,10],[5,10],[10],[1,20],[10]]'
#
# 设计一个数字容器系统，可以实现以下功能：
#
#
# 在系统中给定下标处 插入 或者 替换 一个数字。
# 返回 系统中给定数字的最小下标。
#
#
# 请你实现一个 NumberContainers 类：
#
#
# NumberContainers() 初始化数字容器系统。
# void change(int index, int number) 在下标 index 处填入 number 。如果该下标 index
# 处已经有数字了，那么用 number 替换该数字。
# int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。
#
#
#
#
# 示例：
#
# 输入：
# ["NumberContainers", "find", "change", "change", "change", "change", "find",
# "change", "find"]
# [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
# 输出：
# [null, -1, null, null, null, null, 1, null, 2]
#
# 解释：
# NumberContainers nc = new NumberContainers();
# nc.find(10); // 没有数字 10 ，所以返回 -1 。
# nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
# nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
# nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
# nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
# nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
# nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
# nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
#
#
#
#
# 提示：
#
#
# 1 <= index, number <= 10^9
# 调用 change 和 find 的 总次数 不超过 10^5 次。
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
import heapq


class NumberContainers:

    def __init__(self):
        # index -> number 映射
        self.idx_num: dict[int, int] = {}
        # number -> 最小堆（存放该 number 的所有下标），使用惰性删除
        self.num_heap: dict[int, list[int]] = {}

    def change(self, index: int, number: int) -> None:
        self.idx_num[index] = number
        if number not in self.num_heap:
            self.num_heap[number] = []
        heapq.heappush(self.num_heap[number], index)

    def find(self, number: int) -> int:
        if number not in self.num_heap:
            return -1

        heap = self.num_heap[number]
        # 惰性删除：弹出堆顶直到它确实属于当前 number
        while heap:
            idx = heap[0]
            if self.idx_num.get(idx) == number:
                return idx
            heapq.heappop(heap)

        # 堆中所有 index 都已过期，删除该 number 的记录
        del self.num_heap[number]
        return -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
# @lc code=end


#
# @lcpr case=start
# ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"][[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]\n
# @lcpr case=end

#
