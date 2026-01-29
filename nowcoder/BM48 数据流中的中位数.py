'''

描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

数据范围：数据流中数个数满足 
1
≤
�
≤
1000
 
1≤n≤1000  ，大小满足 
1
≤
�
�
�
≤
1000
 
1≤val≤1000 

进阶： 空间复杂度 
�
(
�
)
 
O(n)  ， 时间复杂度 
�
(
�
�
�
�
�
)
 
O(nlogn) 
示例1
输入：
[5,2,3,4,1,6,7,0,8]
复制
返回值：
"5.00 3.50 3.00 3.50 3.00 3.50 4.00 3.50 4.00 "
复制
说明：
数据流里面不断吐出的是5,2,3...,则得到的平均数分别为5,(5+2)/2,3...   
示例2
输入：
[1,1,1]
复制
返回值：
"1.00 1.00 1.00 "

'''


# -*- coding:utf-8 -*-
class Solution:

    def __init__(self):
        self.li = []

    def Insert(self, num):
        # write code here

        n = len(self.li)
        if n == 0:
            self.li.append(num)
            return
        a, b = 0, n - 1
        while a <= b:
            idx = (a + b) // 2
            if self.li[idx] == num: break
            elif self.li[idx] < num: a = idx + 1
            else: b = idx - 1
        if self.li[idx] >= num: self.li.insert(idx, num)
        else: self.li.insert(idx + 1, num)

    def GetMedian(self):
        # write code here

        n = len(self.li)
        if n % 2 == 1:
            return self.li[n // 2]
        else:
            return (self.li[n // 2] + self.li[n // 2 - 1]) / 2
