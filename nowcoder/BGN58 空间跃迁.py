"""
描述
有
n
n 个城市排成一列，城市
i
i 与
i
+
1
i+1 之间行走耗时
a
i
a
i
​
 。旺仔哥哥想要从
1
1 号城市出发到
n
n 号城市，可在任意时刻使用一次空间跃迁，半径为
k
k，即可以从第
i
i 个城市无时间消耗地传送至第
max
⁡
{
0
,
i
−
k
}
max{0,i−k} 或第
min
⁡
{
n
,
i
+
k
}
min{n,i+k} 个城市。求旺仔哥哥从
1
1 号城市出发到
n
n 号城市的最小总耗时。
输入描述：
一行整数
n
,
k
n,k
(
2
≦
n
≦
1
0
5
,

0
≦
k
<
n
)
(2≦n≦10
5
 , 0≦k<n).
一行
n
−
1
n−1 个整数
a
i
a
i
​

(
1
≦
a
i
≦
1
0
9
)
(1≦a
i
​
 ≦10
9
 )。
输出描述：
输出一个整数，表示最小总耗时。
示例1
输入：
7 0
1 1 4 5 1 4
复制
输出：
16
复制
示例2
输入：
7 1
1 1 4 5 1 4
复制
输出：
11
复制
说明：
使用空间跃迁从第
4
4 个城市跃迁到
5
5 个城市。
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    k = int(data[1])
    a = [int(data[i + 2]) for i in range(n - 1)]

    total = sum(a)

    if k == 0:
        print(total)
        return

    if k >= n - 1:
        print(0)
        return

    # 从城市i向前跃迁到城市i+k，跳过的代价为a[i]+a[i+1]+...+a[i+k-1]
    # 枚举所有长度为k的滑动窗口，找到最大跳过代价
    window = sum(a[:k])
    max_skip = window
    for i in range(k, n - 1):
        window += a[i] - a[i - k]
        if window > max_skip:
            max_skip = window

    print(total - max_skip)


if __name__ == "__main__":
    solve()
