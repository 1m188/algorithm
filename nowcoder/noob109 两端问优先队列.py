"""
描述
给定一个序列，初始为空，请支持以下五种操作：
∙

∙操作 1：将整数
x
x 插入序列中；
∙

∙操作 2：输出序列中的最小值；
∙

∙操作 3：输出序列中的最大值；
∙

∙操作 4：删除序列中的最小值（若有多个，只删除一个）；
∙

∙操作 5：删除序列中的最大值（若有多个，只删除一个）。
输入描述：
第一行输入一个整数
n
n（
1
≦
n
≦
1
0
5
1≦n≦10
5
 ），表示操作次数。
接下来
n
n 行，每行表示一次操作，格式如下：
若
op
=
1
op=1，则后接一个整数
x
x（
1
≦
x
<
2
31
1≦x<2
31
 ），表示插入
x
x；
若
op
=
2
op=2，表示查询并输出当前序列中的最小值；
若
op
=
3
op=3，表示查询并输出当前序列中的最大值；
若
op
=
4
op=4，表示删除当前序列中的最小值；
若
op
=
5
op=5，表示删除当前序列中的最大值。
输出描述：
对于每次操作 2 和操作 3，输出一行一个整数，表示查询结果。
示例1
输入：
10
1 97
3
5
1 78
3
5
1 68
3
5
1 49
复制
输出：
97
78
68
复制
说明：
操作序列中：初始序列空；插入
97
97；查询最小值
97
97；删除最小值；插入
78
78；查询最小值
78
78；删除最小值；插入
68
68；查询最小值
68
68；删除最小值；插入
49
49。

共
3
3 次查询，结果依次为
97
,
78
,
68
97,78,68。
备注：
"""

# 双堆 + 哈希
# 延迟删除
# 堆中数据同步

import heapq

min_heap, max_heap = [], []
cnts = {}
n = int(input())
for _ in range(n):
    input_ = input()
    if " " in input_:
        op, x = map(int, input_.split())
    else:
        op = int(input_)

    if op == 1:

        heapq.heappush(min_heap, x)
        heapq.heappush(max_heap, -x)
        if x not in cnts:
            cnts[x] = 1
        else:
            cnts[x] += 1

    elif op == 2:

        x = min_heap[0]
        while x not in cnts or cnts[x] == 0:
            heapq.heappop(min_heap)
            x = min_heap[0]
        print(x)

    elif op == 3:

        x = -max_heap[0]
        while x not in cnts or cnts[x] == 0:
            heapq.heappop(max_heap)
            x = -max_heap[0]
        print(x)

    elif op == 4:

        x = min_heap[0]
        while x not in cnts or cnts[x] == 0:
            heapq.heappop(min_heap)
            x = min_heap[0]
        heapq.heappop(min_heap)
        cnts[x] -= 1
        if cnts[x] == 0:
            del cnts[x]

    elif op == 5:

        x = -max_heap[0]
        while x not in cnts or cnts[x] == 0:
            heapq.heappop(max_heap)
            x = -max_heap[0]
        heapq.heappop(max_heap)
        cnts[x] -= 1
        if cnts[x] == 0:
            del cnts[x]
