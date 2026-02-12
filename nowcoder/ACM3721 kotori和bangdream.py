"""
ACM3721 kotori和bangdream

描述
有一天，kotori发现了一个和lovelive相似的游戏：bangdream。令她惊讶的是，这个游戏和lovelive居然是同一个公司出的！
kotori经过一段时间的练习后已经变得非常触，每个音符
x
%
x% 的概率perfect，获得
a

a  分，
(
100
−
x
)
%
(100−x)% 概率great，获得
b

b  分。
已知一首歌有
n

n  个音符。kotori想知道，不考虑连击加成的话，一首歌得分的期望是多少？


输入描述：
一行
4

4 个整数，用空格隔开。分别是
n
,
x
,
a
,
b

n,x,a,b  。
（
0
≤
x
≤
100
，
1
≤
n
,
a
,
b
≤
1000
）

（0≤x≤100，1≤n,a,b≤1000）
输出描述：
一首歌得分的期望，保留两位小数。
示例1
输入：
100 50 500 400
复制
输出：
45000.00
复制
说明：
如果全perfect是50000分，全great是40000分。由于它们的概率都是50%，即perfect和great五五开，所以期望是45000分。
备注：
"""

n, x, a, b = map(int, input().strip().split())
print(f"{(0.01 * x * a + 0.01 * (100 - x) * b)*n:.2f}")
