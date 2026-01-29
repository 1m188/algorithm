'''
描述
计算一个浮点数的立方根，不使用库函数。
保留一位小数。

数据范围：|val| \le 20 \∣val∣≤20 

输入描述：
待求解参数，为double类型（一个实数）

输出描述：
输出参数的立方根。保留一位小数。

示例1
输入：
19.9
复制
输出：
2.7
复制
示例2
输入：
2.7
复制
输出：
1.4
'''

val = float(input())

if val == 0:
    print('0.0')
else:
    FLOAT = 0.000001
    sign = 1 if val > 0 else -1
    val = abs(val)

    left = 0
    right = 20
    while True:
        x = (left + right) / 2
        if abs(x**3 - val) <= FLOAT: break
        if x**3 > val: right = x
        else: left = x
    x *= sign
    print('%.1f' % x)
