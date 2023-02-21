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


def trapezoidal_f(f: function, \
    a: Union[int, float], \
    b: Union[int,float]) -> float:
    '''
    梯形公式
    
    用于计算定积分近似值

    @param f: 待积分的函数
    @param a, b: 积分区间
    @param return: 积分近似值
    '''
    return (f(a) + f(b)) * (b - a) / 2
