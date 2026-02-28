"""
描述
你需要实现一个函数，接受的参数为两条直线
A
B
、
C
D
AB、CD，返回值为点类型的两条直线的交点。

函数接收的参数为：
1.

1.
​
 由点
A
A 和点
B
B 构成的直线
A
B
AB。
2.

2.
​
 由点
C
C 和点
D
D 构成的直线
C
D
CD。

你需要实现的函数的返回值为：
∙

∙由直线
A
B
AB 和直线
C
D
CD 相交而得到的交点
P
P。若两直线交点不唯一，则返回点
(
−
1
,
−
1
)
(−1,−1)。
输入描述：
提供输入格式只是方便您在代码出错时进行调试，你只需要按照题目描述实现函数即可，并不需要关心数据的实际输入格式。

输入包含两行：
∙

∙第一行包含四个正整数，分别为点
A
A 的横纵坐标的点
B
B 的横纵坐标。
∙

∙第二行包含四个正整数，分别为点
C
C 的横纵坐标的点
D
D 的横纵坐标。
数据保证点
A
A 和点
B
B 不重合，点
C
C 和点
D
D 不重合，且若交点
P
P 存在则其横纵坐标的绝对值均在
1
0
4
10
4
  以内。
输出描述：
提供输出格式只是方便您在代码出错时进行调试，你只需要按照题目描述实现函数即可，并不需要关心数据的实际输出格式。

输出一行两个实数，分别为直线
A
B
AB 和直线
C
D
CD 的交点
P
P 的横纵坐标。特别的，如果两直线交点不唯一，则输出
-1 -1
-1 -1。
注意，只要您的答案与标准答案之差在
1
0
−
6
10
−6
  以内，就会被认为是正确的。
示例1
输入：
0 0 1 1
0 2 2 0
复制
输出：
1.000000 1.000000
复制
说明：


按照输入格式，点
A
A 为
(
0
,
0
)
(0,0)，点
B
B 为
(
1
,
1
)
(1,1)，点
C
C 为
(
0
,
2
)
(0,2)，点
D
D 为
(
2
,
0
)
(2,0)。
图中绿线表示直线
A
B
AB，红线表示直线
C
D
CD，两直线交于点
P
(
1
,
1
)
P(1,1)，此时点
P
P 与点
B
B 重合。
"""

from typing import Optional
import math


class Point:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y


class Line:
    def __init__(
        self,
        point_a: Optional[Point] = None,
        point_b: Optional[Point] = None,
    ):
        self.point_A = point_a if point_a is not None else Point()
        self.point_B = point_b if point_b is not None else Point()


def find_meeting_point(line_A: Line, line_B: Line) -> Point:
    xa = line_A.point_A.x
    xb = line_A.point_B.x
    ya = line_A.point_A.y
    yb = line_A.point_B.y
    xc = line_B.point_A.x
    xd = line_B.point_B.x
    yc = line_B.point_A.y
    yd = line_B.point_B.y

    if (math.isclose(xa, xb) and math.isclose(xc, xd)) or (
        not math.isclose(xa, xb)
        and not math.isclose(xc, xd)
        and math.isclose((ya - yb) / (xa - xb), (yc - yd) / (xc - xd))
    ):  # 平行
        return Point(-1, -1)
    elif math.isclose(xa, xb) or math.isclose(xc, xd):  # 有一条垂直线
        if math.isclose(xa, xb):  # A垂直
            x = xa
            y = (yc - yd) / (xc - xd) * (x - xc) + yc
        else:  # C垂直
            x = xc
            y = (ya - yb) / (xa - xb) * (x - xa) + ya
        return Point(x, y)
    else:  # 无垂直线
        kA = (ya - yb) / (xa - xb)
        kB = (yc - yd) / (xc - xd)
        x = (kA * xa - kB * xc + yc - ya) / (kA - kB)
        y = kA * (x - xa) + ya
        return Point(x, y)


def main():
    data = list(map(float, input().split()))
    data.extend(list(map(float, input().split())))
    A = Point(data[0], data[1])
    B = Point(data[2], data[3])
    C = Point(data[4], data[5])
    D = Point(data[6], data[7])
    AB = Line(A, B)
    CD = Line(C, D)
    ans = find_meeting_point(AB, CD)
    print(f"{ans.x} {ans.y}")


if __name__ == "__main__":
    main()
