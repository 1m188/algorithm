"""
描述
气象意义上，通常以
3
∼
5
3∼5 月为春季 (spring)，
6
∼
8
6∼8 月为夏季 (summer)，
9
∼
11
9∼11 月为秋季 (autumn)，
12
12 月至来年
2
2 月为冬季 (winter)。请根据输入的年月（格式 YYYYMM）输出对应的季节。
输入描述：
在一行中输入一个六位整数 YYYYMM，表示年份和月份，其中 YYYY 为四位年份，MM 为两位月份（01~12）。
输出描述：
输出一个字符串，为对应的季节英文名称（全部小写字母），即 "spring"、"summer"、"autumn" 或 "winter"（均不含双引号）。
示例1
输入：
201901
复制
输出：
winter
复制
说明：
输入 201901 表示 2019 年 1 月，1 月为冬季，输出 winter。
示例2
输入：
202506
复制
输出：
summer
复制
说明：
输入 202506 表示 2025 年 6 月，6 月为夏季，输出 summer。
备注：
本题已于下方时间节点更新，请注意题解时效性：
1. 2025-06-03 优化题面文本与格式。
"""

YYYYMM = input()
m = int(YYYYMM[4:])
print(
    "spring"
    if m in [3, 4, 5]
    else "summer" if m in [6, 7, 8] else "autumn" if m in [9, 10, 11] else "winter"
)
