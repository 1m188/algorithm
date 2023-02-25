'''
Engineering Mathematics
工程数学里的一些计算方法
教材：数值计算方法（曾金平 主编  湖南大学出版社）
'''

from typing import Optional, Union


def cs(f: function, points: list[float]) -> Optional[float]:
    '''
    递归计算差商

    @param f: 待计算的函数
    @param points: 点
    @param return: 差商结果（一个点的时候无法计算差商）
    '''
    if len(points) <= 1: return None
    if len(points) == 2:
        a, b = points
        return (f(a) - f(b)) / (a - b)
    return (cs(f, points[:-1]) - cs(f, points[1:])) / (points[0] - points[-1])


def trapezoidal_f(f: function, a: float, b: float) -> float:
    '''
    梯形公式
    
    用于计算定积分近似值

    两点（两个端点）

    @param f: 待积分的函数
    @param a, b: 积分区间
    @param return: 积分近似值
    '''
    return (f(a) + f(b)) * (b - a) / 2


def compound_trapezoidal_f(f: function, points: list[float]) -> float:
    '''
    复合梯形求积公式

    对每两个点之间的小区间用梯形公式累积求积分

    @param f: 待积分的函数
    @param points: 在积分区间上的等距取点，至少要有两个点以上，且两个端点应该是积分端点
    @param return: 积分近似值
    '''
    res = 0.0
    for i in range(1, len(points)):
        res += (points[i] - points[i - 1]) * (f(points[i - 1]) +
                                              f(points[i])) / 2
    return res


def simpson_f(f: function, a: float, b: float) -> float:
    '''
    Simpson公式
    
    用于计算定积分近似值

    三点（抛物线近似）

    @param f: 待积分的函数
    @param a, b: 积分区间
    @param return: 积分近似值
    '''
    return (b - a) / 6 * (f(a) + 4 * f((a + b) / 2) + f(b))
