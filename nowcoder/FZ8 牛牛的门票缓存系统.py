'''

描述
动物园的门票售卖处需要一个缓存系统来管理门票信息。请你设计并实现一个满足 LFU（最不经常使用）缓存约束的数据结构。

你需要实现一个类 TicketCache，其中包含以下方法：

TicketCache(int capacity)：构造方法初始化 LFU 缓存，其中 capacity 是缓存的容量。
int getTicket(int ticketId)：如果门票编号 ticketId 存在于缓存中，则返回门票的信息 ticketInfo，否则返回 -1。
void putTicket(int ticketId, int ticketInfo)：如果门票编号 ticketId 已经存在于缓存中，则更新门票的信息为 ticketInfo；如果不存在，则向缓存中插入该门票编号和信息。如果插入操作导致缓存中门票数量超过容量 capacity，则应该逐出最不经常使用的门票。
函数 getTicket 和 putTicket 必须以平均时间复杂度 O(1) 运行。
示例1
输入：
["putTicket","putTicket","getTicket","putTicket","getTicket","putTicket","getTicket","getTicket","getTicket"],[[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]],2
复制
返回值：
[1,-1,1,-1,4]
复制
说明：
TicketCache ticketCache = new TicketCache(2);ticketCache.putTicket(1, 1);   // 缓存是 {1=1}ticketCache.putTicket(2, 2);   // 缓存是 {1=1, 2=2}ticketCache.getTicket(1);      // 返回 1ticketCache.putTicket(3, 3);   // 该操作会使得门票 2 作废，缓存是 {1=1, 3=3}ticketCache.getTicket(2);      // 返回 -1 (未找到)ticketCache.putTicket(4, 4);   // 该操作会使得门票 3 作废，缓存是 {4=4, 1=1}ticketCache.getTicket(1);      // 返回 1 (未找到)ticketCache.getTicket(3);      // 返回 -1
ticketCache.getTicket(4);      // 返回 4
备注：
1 <= capacity <= 3000
0 <= ticketId <= 10000
0 <= ticketInfo <= 10^5
最多调用 2 * 10^5 次 getTicket 和 putTicket 方法
operations为操作数组，包含两种操作字符串
data为数据数组，put操作时，有门票编号 ticketId 和门票的信息 ticketInfo两个元素，get操作时只有门票编号 ticketId 一个元素

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param operations string字符串一维数组
# @param data int整型二维数组
# @param capacity int整型
# @return int整型一维数组
#
class Solution:

    def performOperation(self, operations: List[str], data: List[List[int]], capacity: int) -> List[int]:
        # write code here

        class TicketCache:

            def __init__(self, capacity: int):
                self.lfu = {}
                self.capacity = capacity
                self.cap = 0

            def putTicket(self, ticketId: int, ticketInfo: int):
                if self.capacity == 0: return

                if ticketId in self.lfu:
                    self.lfu[ticketId][0] = ticketInfo
                    self.lfu[ticketId][1] += 1
                    return

                if self.cap >= self.capacity:
                    x = min(self.lfu.items(), key=lambda x: x[1][1])[0]
                    self.lfu.pop(x)
                    self.cap -= 1
                self.lfu[ticketId] = [ticketInfo, 1]
                self.cap += 1

            def getTicket(self, ticketId: int):
                if ticketId in self.lfu:
                    self.lfu[ticketId][1] += 1
                    return self.lfu[ticketId][0]
                else:
                    return -1

        res = []
        ticketCache = TicketCache(capacity)
        for i, v in enumerate(operations):
            op = data[i]
            if len(op) == 2: ticketCache.putTicket(op[0], op[1])
            else: res.append(ticketCache.getTicket(op[0]))
        return res
