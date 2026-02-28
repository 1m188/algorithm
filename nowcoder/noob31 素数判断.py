"""
描述
给定
T
T 个正整数
n
n，判断每个
n
n 是否为素数。

【名词解释】
素数：大于
1
1 且仅能被
1
1 和自身整除的正整数。
输入描述：
第一行输入一个整数
T
T（
1
≦
T
≦
10
1≦T≦10），表示需要判断的整数个数。

接下来
T
T 行，每行输入一个正整数
n
n（
1
≦
n
≦
1
0
5
1≦n≦10
5
 ）。
输出描述：
输出
T
T 行，每行对应一个测试用例：若
n
n 是素数，输出
Yes
Yes；否则输出
No
No。
示例1
输入：
2
1
2
复制
输出：
No
Yes
复制
说明：
第一个测试用例
n
=
1
n=1，
1
1 不是素数，输出 No；第二个测试用例
n
=
2
n=2，
2
2 是素数，输出 Yes。
"""


def judge(n: int) -> bool:
    if n <= 1:
        return False
    if n == 2:
        return True
    if n & 0x1 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


t = int(input().strip())
for _ in range(t):
    n = int(input().strip())
    print("Yes" if judge(n) else "No")
