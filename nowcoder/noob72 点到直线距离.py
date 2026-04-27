"""
描述
你需要实现一个函数，给定平面上的点
(
a
,
b
)
(a,b)，以及一条由另外两个点
(
x
1
,
y
1
)
(x
1
​
 ,y
1
​
 ) 和
(
x
2
,
y
2
)
(x
2
​
 ,y
2
​
 ) 确定的直线
L
L，求点
(
a
,
b
)
(a,b) 到直线
L
L 的距离。
输入描述：
共
2
2 行。
第一行是两个空格隔开的整数
a
,
b
a,b。
第二行是四个空格隔开的整数
x
1
,
y
1
,
x
2
,
y
2
x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 。
输出描述：
共一行，一个实数，表示点
(
a
,
b
)
(a,b) 到直线
L
L 的距离，保留两位小数。
示例1
输入：
0 0
-1 1 1 1
复制
输出：
1.00
复制
备注：

1
≤
a
,
b
,
x
1
,
y
1
,
x
2
,
y
2
<
2
31
1≤a,b,x
1
​
 ,y
1
​
 ,x
2
​
 ,y
2
​
 <2
31
 。
"""

import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Line:
    def __init__(self, point_a, point_b):
        self.point_a = point_a
        self.point_b = point_b


def get_distance(P: Point, L: Line):
    # TODO: 计算点P到直线L的距离

    A = L.point_a.y - L.point_b.y
    B = L.point_b.x - L.point_a.x
    C = L.point_a.x * L.point_b.y - L.point_b.x * L.point_a.y
    d = math.fabs(A * P.x + B * P.y + C) / math.sqrt(A * A + B * B)
    return d


def main():
    a, b = map(int, input().split())
    sx, sy, tx, ty = map(int, input().split())

    point_a = Point(sx, sy)
    point_b = Point(tx, ty)
    point_c = Point(a, b)
    line = Line(point_a, point_b)

    print("{:.2f}".format(get_distance(point_c, line)))


if __name__ == "__main__":
    main()
