"""
描述
有一个序列
a
1
,
a
2
,
.
.
.
,
a
n
a
1
​
 ,a
2
​
 ,...,a
n
​
  ， 牛牛将对这个序列切割一刀（划分分成两个不相交的非空序列，一个序列为
a
1
,
…
,
a
p
a
1
​
 ,…,a
p
​
 ，另一个序列为
a
p
+
1
,
…
,
a
n
a
p+1
​
 ,…,a
n
​
 ），牛牛切割的代价为两个序列元素和的乘积。牛牛想知道切割代价最小是多少。
输入描述：
第一行输入一个整数
n
n，表示序列的长度
2
≤
n
≤
1
0
6
2≤n≤10
6
 。
第二行输入
n
n 个整数
a
1
,
a
2
,
…
,
a
n
a
1
​
 ,a
2
​
 ,…,a
n
​
 ，表示序列的元素
−
1
0
3
≤
a
i
≤
1
0
3
−10
3
 ≤a
i
​
 ≤10
3
 。
输出描述：
输出一个整数表示切割代价最小是多少。
示例1
输入：
5
1 2 3 4 5
复制
输出：
14
复制
说明：
序列被划分为1 和 2 3 4 5，右边和为 14。
示例2
输入：
4
2 1 3 4
复制
输出：
16
复制
说明：
序列被划分为 2 和 1 3 4。
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    a = [int(data[i + 1]) for i in range(n)]

    total = sum(a)
    left_sum = 0
    ans = None

    for i in range(n - 1):
        left_sum += a[i]
        right_sum = total - left_sum
        cost = left_sum * right_sum
        if ans is None or cost < ans:
            ans = cost

    print(ans)


if __name__ == "__main__":
    solve()
