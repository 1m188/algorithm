"""
描述
小红拥有一个长度为
n
n 的整数数组
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
 }，初始得分为
0
0。
她可以多次执行如下操作，顺序不限、次数不限，直到无法继续：
∙

∙ 任选两个尚未被选过的下标
i
≠
j
i

​
 =j；
∙

∙ 若满足
∣
a
i
−
a
j
∣
≦
k
∣a
i
​
 −a
j
​
 ∣≦k，则将这两个数配成一对，并获得分数
a
i
×
a
j
a
i
​
 ×a
j
​
 ；否则该对无法选取；
∙

∙ 被配对的两个数随即从数组中移除，之后不可再次使用。

请你帮助小红最大化最终得分，并输出这个最大分数。
输入描述：
在一行上输入两个整数
n
,
k
(
1
≦
n
,
k
≦
1
0
5
)
n,k(1≦n,k≦10
5
 )。
在第二行输入
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
1
≦
a
i
≦
1
0
5
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
 (1≦a
i
​
 ≦10
5
 )。
输出描述：
输出一个整数，表示通过最优配对操作后小红能够获得的最大得分。
示例1
输入：
6 2
1 1 4 5 1 4
复制
输出：
21
复制
说明：
一种可行的最优方案如下：
∙

∙ 选择
1
1 与
1
1，得分
1
×
1
=
1
1×1=1；
∙

∙ 选择
4
4 与
5
5，得分
4
×
5
=
20
4×5=20；
最终总得分为
1
+
20
=
21
1+20=21。
"""

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
f = True
flags = [False for _ in range(n)]
ans = 0
while f:
    f = False
    for i in range(n - 1):
        if flags[i]:
            continue
        for j in range(i + 1, n):
            if flags[j]:
                continue
            if abs(a[i] - a[j]) <= k:
                ans += a[i] * a[j]
                f = True
                flags[i], flags[j] = True, True
                break
print(ans)
