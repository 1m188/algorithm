"""
描述
本题为问题的简单版本，两题的唯一区别在于询问的次数及询问的数据范围。

Poi 发明了一种新的加法：二进制只进位加法（下文用
f
(
x
,
y
)
f(x,y) 指代）。在这种加法下（为了便于理解，本表中数字使用二进制表达）：
x
x
y
y
f
(
x
,
y
)
f(x,y)
00
00
00
00
00
00
00
00
01
01
00
00
01
01
00
00
00
00
01
01
01
01
10
10

需要注意的是，我们只考虑一次进位，即不考虑进位造成的其他位的变动导致的再次进位，比如
f
(
11
,
01
)
=
10
f(11,01)=10。
简而言之，
f
(
x
,
y
)
=
x
+
y
−
(
x
⊕
y
)
f(x,y)=x+y−(x⊕y)，其中
⊕
⊕ 代表二进制按位异或运算。
现在，给定一个长度为
n
n 的序列
{
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
}
{a
1
​
 ,a
2
​
 ,…,a
n
​
 }。你需要处理
q
q 个查询，每个查询会给定
l
l 和
r
r，求解：

f
(
f
(
f
(
⋯
f
(
f
(
a
l
,
a
l
+
1
)
,
a
l
+
2
)
,
⋯
)
,
a
r
−
1
)
,
a
r
)
f(f(f(⋯f(f(a
l
​
 ,a
l+1
​
 ),a
l+2
​
 ),⋯),a
r−1
​
 ),a
r
​
 )

输入描述：
每个测试文件均包含多组测试数据。第一行输入一个整数
T
(
1
≤
T
≤
1
0
6
)
T(1≤T≤10
6
 ) 代表数据组数，每组测试数据描述如下：
第一行输入两个整数
n
,
q
(
1
≤
n
≤
1
0
6
;

q
=
1
)
n,q(1≤n≤10
6
 ; q=1)，代表序列中的元素个数、查询次数。
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
(
0
≤
a
i
<
2
60
)
a
1
​
 ,a
2
​
 ,…,a
n
​
 (0≤a
i
​
 <2
60
 )，代表序列中的元素。
此后
q
q 行，第
i
i 行输入两个整数
l
i
,
r
i
(
l
i
=
1
;

r
i
=
n
)
l
i
​
 ,r
i
​
 (l
i
​
 =1; r
i
​
 =n)，代表第
i
i 次询问的区间。

除此之外，保证单个测试文件的
n
n 之和不超过
1
0
6
10
6
 ，
q
q 之和不超过
1
0
6
10
6
 。
输出描述：
对于每个查询，新起一行。输出一个整数，代表该次查询的结果。
示例1
输入：
3
2 1
1 1
1 2
3 1
2 3 3
1 3
5 1
31 31 31 31 31
1 5
复制
输出：
2
0
48
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx])
        q = int(data[idx + 1])
        idx += 2
        a = [int(data[idx + i]) for i in range(n)]
        idx += n
        for _ in range(q):
            l = int(data[idx])
            r = int(data[idx + 1])
            idx += 2
        # f(x,y) = x+y-(x^y) = 2*(x&y)
        # Easy Version: l=1, r=n
        result = a[0]
        for i in range(1, n):
            result = 2 * (result & a[i])
        out.append(str(result))
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    solve()
