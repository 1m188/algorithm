'''

描述
一个缓存结构需要实现如下功能。
set(key, value)：将记录(key, value)插入该结构
get(key)：返回key对应的value值
但是缓存结构中最多放K条记录，如果新的第K+1条记录要加入，就需要根据策略删掉一条记录，然后才能把新记录加入。这个策略为：在缓存结构的K条记录中，哪一个key从进入缓存结构的时刻开始，被调用set或者get的次数最少，就删掉这个key的记录；
如果调用次数最少的key有多个，上次调用发生最早的key被删除
这就是LFU缓存替换算法。实现这个结构，K作为参数给出

数据范围：
0
<
�
≤
1
0
5
0<k≤10 
5
 ，
∣
�
�
�
∣
≤
2
×
1
0
9
∣val∣≤2×10 
9
 
要求：get和set的时间复杂度都是 
�
(
�
�
�
�
)
O(logn)，空间复杂度是 
�
(
�
)
O(n)


若opt=1，接下来两个整数x, y，表示set(x, y)
若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1

对于每个操作2，返回一个答案
示例1
输入：
[[1,1,1],[1,2,2],[1,3,2],[1,2,4],[1,3,5],[2,2],[1,4,4],[2,1]],3
复制
返回值：
[4,-1]
复制
说明：
在执行"1 4 4"后，"1 1 1"被删除。因此第二次询问的答案为-1   
备注：
1
≤
�
≤
�
≤
1
0
5
1≤k≤n≤10 
5
 
−
2
×
1
0
9
≤
�
,
�
≤
2
×
1
0
9
−2×10 
9
 ≤x,y≤2×10 
9

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# lfu design
# @param operators int整型二维数组 ops
# @param k int整型 the k
# @return int整型一维数组
#
class Solution:

    def LFU(self, operators: List[List[int]], k: int) -> List[int]:
        # write code here

        LFU: list[int] = []

        def set_(key, value):
            if len(LFU) >= k:
                idx = len(LFU) - 1
                for i in range(len(LFU) - 1, -1, -1):
                    if LFU[i][2] < LFU[idx][2]:
                        idx = i
                LFU.pop(idx)
            LFU.insert(0, [key, value, 1])

        def get_(key) -> int:
            for i in range(len(LFU)):
                if LFU[i][0] == key:
                    x = LFU.pop(i)
                    x[2] += 1
                    LFU.insert(0, x)
                    return x[1]
            return -1

        res = []
        for op in operators:
            opt = op[0]
            if opt == 1:
                set_(op[1], op[2])
            else:
                res.append(get_(op[1]))
        return res
