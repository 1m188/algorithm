"""
描述
定义数列
{
A
n
}
{A
n
​
 } 如下：

A
n
=
{
0
,
n
∈
{
1
}
;
1
,
n
∈
{
2
,
3
}
;
A
n
=
A
n
−
3
+
2
A
n
−
2
+
A
n
−
1
,
n
≧
4.
A
n
​
 =
⎩
⎪
⎨
⎪
⎧
​

0,
1,
A
n
​
 =A
n−3
​
 +2A
n−2
​
 +A
n−1
​
 ,
​

n∈{1};
n∈{2,3};
n≧4.
​


给定正整数
n
n，求
A
n
A
n
​
  的值。
输入描述：
在一行中输入一个整数
n
n，满足
1
≦
n
≦
20
1≦n≦20。
输出描述：
输出一个整数，表示
A
n
A
n
​
  的值。
示例1
输入：
4
复制
输出：
3
复制
说明：
A
4
=
A
1
+
2
A
2
+
A
3
=
0
+
2
×
1
+
1
=
3
A
4
​
 =A
1
​
 +2A
2
​
 +A
3
​
 =0+2×1+1=3。
"""


def calc(n: int) -> int:
    if n == 1:
        return 0
    elif n == 2 or n == 3:
        return 1
    else:
        a, b, c = 0, 1, 1
        for _ in range(4, n + 1):
            d = a + 2 * b + c
            a, b, c = b, c, d
        return d


n = int(input())
print(calc(n))
