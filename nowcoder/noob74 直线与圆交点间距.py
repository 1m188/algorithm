"""
描述


圆心为
O
O，半径为
r
r 的圆与直线
A
B
AB 交于两点
A
A、
B
B（
A
A、
B
B 两点可能重合），求
A
A、
B
B 两点之间的间距
∣
A
B
∣
∣AB∣。

具体而言，你需要实现一个函数，接受两个参数：
∙

∙ 圆
O
O;
∙

∙ 直线
A
B
AB。

你需要计算出
A
A、
B
B 两点之间的间距
∣
A
B
∣
∣AB∣，并将其作为该函数的返回值。
输入描述：
你只需要实现核心函数即可，不需要关注输入格式。
输出描述：
你只需要实现核心函数即可，不需要关注输出格式。
示例1
输入：
0 0 1
0 0 0 1
复制
输出：
2.000000
复制
备注：
数据保证直线与圆不相离。

特别的，当直线与圆相切时，间距
∣
A
B
∣
∣AB∣ 的值为
0
0。

注意，由于浮点数存在误差，只要你的返回值和真实值之间的误差在
1
0
−
5
10
−5
  以内，你的答案就会被认为是正确的。
"""

import math


class Point:
    def __init__(self, A: float, B: float):
        self.x = A
        self.y = B


class Line:
    def __init__(self, A: Point, B: Point):
        self.point_A = A
        self.point_B = B


class Circle:
    def __init__(self, A: Point, B: float):
        self.O = A
        self.r = B


def getDistance(circle: Circle, l: Line) -> float:
    # 请在这里实现你的代码

    A = l.point_A.y - l.point_B.y
    B = l.point_B.x - l.point_A.x
    C = l.point_A.x * l.point_B.y - l.point_B.x * l.point_A.y
    x0, y0, r = circle.O.x, circle.O.y, circle.r
    d = math.fabs(A * x0 + B * y0 + C) / math.sqrt(A**2 + B**2)
    if r**2 - d**2 >= 0:
        L = 2 * math.sqrt(r**2 - d**2)
    else:
        L = 0.0
    return L


def main():
    ox, oy, r = map(float, input().split())
    x1, y1, x2, y2 = map(float, input().split())

    center = Point(ox, oy)
    circle = Circle(center, int(r))

    p1 = Point(x1, y1)
    p2 = Point(x2, y2)
    l = Line(p1, p2)

    result = getDistance(circle, l)
    print("{:.6f}".format(result))


if __name__ == "__main__":
    main()
