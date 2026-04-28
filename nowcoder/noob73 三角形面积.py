"""
描述
给定平面上不共线的三个整数点，求这三个点构成的三角形的面积。
输入描述：
共
3
3 行。每行两个整数
x
i
,
y
i
x
i
​
 ,y
i
​
 ，表示一个点的坐标。
保证输入的三个点不共线。
输出描述：
共一行，一个实数，表示构成的三角形的面积，保留两位小数。
示例1
输入：
0 0
0 2
1 1
复制
输出：
1.00
复制
备注：
1
≤
x
i
,
y
i
<
2
31
1≤x
i
​
 ,y
i
​
 <2
31
 。
"""

import math


class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


class Triangle:
    def __init__(self, a: Point, b: Point, c: Point):
        self.a = a
        self.b = b
        self.c = c


def get_area(T: Triangle):
    # TODO: 计算三角形T的面积

    def distance(a: Point, b: Point) -> float:
        return math.sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)

    a = distance(T.a, T.b)
    b = distance(T.b, T.c)
    c = distance(T.c, T.a)
    s = (a + b + c) / 2
    S = math.sqrt(s * (s - a) * (s - b) * (s - c))
    return S


def main():
    x, y = map(int, input().split())
    a = Point(x, y)

    x, y = map(int, input().split())
    b = Point(x, y)

    x, y = map(int, input().split())
    c = Point(x, y)

    T = Triangle(a, b, c)
    print("{:.2f}".format(get_area(T)))


if __name__ == "__main__":
    main()
