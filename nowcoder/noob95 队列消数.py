"""
描述
给定正整数序列
t
i
c
k
e
t
s
=
{
t
i
c
k
e
t
s
0
,
t
i
c
k
e
t
s
1
,
…
,
t
i
c
k
e
t
s
n
−
1
}
tickets={tickets
0
​
 ,tickets
1
​
 ,…,tickets
n−1
​
 }
(
1
≦
a
i
≦
100
)
(1≦a
i
​
 ≦100) 及索引
k

(
0
≦
k
<
n
≦
100
)
k(0≦k<n≦100)，定义初始队列为元素下标序列
{
0
,
1
,
…
,
n
−
1
}
{0,1,…,n−1}。
重复以下过程直至索引
k
k 对应元素被移除：
∙

∙取出队首下标
i
i，耗时
1
1 秒，若
a
i
>
1
a
i
​
 >1，令
a
i
←
a
i
−
1
a
i
​
 ←a
i
​
 −1 并将
i
i 加入队尾；否则，将其从队列中移除。
返回目标元素
t
i
c
k
e
t
s
k
tickets
k
​
  被移除时，所经过的总时间。
示例1
输入：
[1,1,4,5,1,4],2
复制
返回值：
13
复制
说明：

备注：
本题已于下方时间节点更新，请注意题解时效性：
1. 2025-11-28 修复题面下标描述矛盾的问题（统一为0-idx）。
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param tickets int整型一维数组
# @param k int整型
# @return int整型
#
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        # write code here

        que = [i for i in range(len(tickets))]
        ans = 0
        while True:
            ans += 1
            i = que.pop(0)
            if tickets[i] > 1:
                tickets[i] -= 1
                que.append(i)
            else:
                if i == k:
                    break
        return ans
