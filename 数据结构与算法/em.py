'''
Engineering Mathematics
工程数学里的一些计算方法
教材：数值计算方法（曾金平 主编  湖南大学出版社）
'''

from typing import Optional


def cs(f: function, points: list[float]) -> Optional[float]:
    '''
    递归计算差商
    '''
    if len(points) <= 1: return None
    if len(points) == 2:
        a, b = points
        return (f(a) - f(b)) / (a - b)
    return (cs(f, points[:-1]) - cs(f, points[1:])) / (points[0] - points[-1])
