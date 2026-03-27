"""
描述
给定长度为
n
n 的整数序列
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
 。
定义序列
b
b 初始为空。
∙

∙ 对每个
i
i 从
1
1 到
n
n：
⋄

⋄ 若
a
i
a
i
​
  在
a
1
,
…
,
a
i
−
1
a
1
​
 ,…,a
i−1
​
  中未出现，则将
a
i
a
i
​
  追加到
b
b 中；
⋄

⋄ 否则忽略。
求最终序列
b
b。
输入描述：
第一行包含整数
T

(
1
≤
T
≤
50
)
T (1≤T≤50)，表示测试数据组数；
接下来
T
T 组数据，每组数据格式如下：
1.

1.
​
 第一行包含整数
n

(
1
≤
n
≤
5
×
1
0
4
)
n (1≤n≤5×10
4
 )；
2.

2.
​
 第二行包含
n
n 个整数
a
i
a
i
​
 ，满足
−
2
31
≤
a
i
<
2
31
−2
31
 ≤a
i
​
 <2
31
 。
输出描述：
对每组数据，输出一行，依次输出序列
b
b 中的所有元素，元素间以一个空格分隔。
示例1
输入：
3
6
1 2 1 3 2 4
5
5 5 5 5 5
4
10 20 10 20
复制
输出：
1 2 3 4
5
10 20
复制
备注：
"""

T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a.insert(0, None)
    se = set()
    b = []
    for i in range(1, n + 1):
        if a[i] not in se:
            b.append(a[i])
            se.add(a[i])
    print(*b)
