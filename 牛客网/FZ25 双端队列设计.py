'''

描述
牛牛正在设计一个双端队列的实现。双端队列是一种线性数据结构，它允许从队列的两端插入和删除元素。

你的实现应该支持以下操作：

MyDeque(int k)：构造函数，设置队列的最大长度为 k。
bool insertFront(int value)：将元素插入双端队列的前端。如果插入成功，则返回0，否则返回-1。操作编号为1.
bool insertLast(int value)：将元素插入双端队列的后端。如果插入成功，则返回0，否则返回-1。操作编号为2.
bool deleteFront()：从双端队列的前端删除一个元素。如果删除成功，则返回0，否则返回-1。操作编号为3.
bool deleteLast()：从双端队列的后端删除一个元素。如果删除成功，则返回0，否则返回-1。操作编号为4.
int getFront()：获取双端队列的前端元素。如果双端队列为空，则返回 -1。操作编号为5.
int getRear()：获取双端队列的后端元素。如果双端队列为空，则返回 -1。操作编号为6.
bool isEmpty()：检查双端队列是否为空。
bool isFull()：检查双端队列是否已满。
函数签名：

vector<int> performOperations(vector<vector<int>>& operations, int k); 
函数参数：

operations：一个二维整数数组，表示要执行的操作。每个操作由一个整数和可能的参数组成，操作类型和参数的含义如上所述。
k：表示队列最大长度。
返回值：

返回一个整数数组，表示每个操作的输出结果。
示例1
输入：
[[1,1],[2,2],[1,3],[2,4],[5],[6],[3],[4],[5]],4
复制
返回值：
[0,0,0,0,3,4,0,0,1]
复制
示例2
输入：
[[1,1],[1,2],[1,3],[2,4],[2,5],[2,6],[5],[6],[4],[6],[1,8],[5]],5
复制
返回值：
[0,0,0,0,0,-1,3,5,0,4,0,8]
复制
备注：
所有的值都在 1 至 1000 的范围内。
操作数将在 1 至 1000 的范围内。
请不要使用内置的队列库。

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param operations int整型二维数组
# @param k int整型
# @return int整型一维数组
#
class Solution:

    def performOperations(self, operations: List[List[int]], k: int) -> List[int]:
        # write code here

        class MyDeque:

            def __init__(self, k: int):
                self.length = k
                self.que = []

            def insertFront(self, value: int) -> bool:
                if len(self.que) < self.length:
                    self.que.insert(0, value)
                    return 0
                else:
                    return -1

            def insertLast(self, value: int) -> bool:
                if len(self.que) < self.length:
                    self.que.append(value)
                    return 0
                else:
                    return -1

            def deleteFront(self) -> bool:
                if self.que:
                    self.que.pop(0)
                    return 0
                else:
                    return -1

            def deleteLast(self) -> bool:
                if self.que:
                    self.que.pop()
                    return 0
                else:
                    return -1

            def getFront(self) -> int:
                if self.que: return self.que[0]
                else: return -1

            def getRear(self) -> int:
                if self.que: return self.que[-1]
                else: return -1

            def isEmpty(self) -> bool:
                return len(self.que) == 0

            def isFull(self) -> bool:
                return len(self.que) == self.length

        que = MyDeque(k)
        res = []
        for op in operations:
            a = op[0]
            if a == 1: res.append(que.insertFront(op[1]))
            elif a == 2: res.append(que.insertLast(op[1]))
            elif a == 3: res.append(que.deleteFront())
            elif a == 4: res.append(que.deleteLast())
            elif a == 5: res.append(que.getFront())
            elif a == 6: res.append(que.getRear())
        return res
