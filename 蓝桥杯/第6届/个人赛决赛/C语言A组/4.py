"""

标题：穿越雷区

X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。
某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？

已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。
例如：
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

坦克车只能水平或垂直方向上移动到相邻的区。

数据格式要求：

输入第一行是一个整数n，表示方阵的大小， 4<=n<100
接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。
A，B都只出现一次。

要求输出一个整数，表示坦克从A区到B区的最少移动步数。
如果没有方案，则输出-1

例如：
用户输入：
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

则程序应该输出：
10

资源约定：
峰值内存消耗 < 512M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。





"""

from collections import deque
import sys


def solve():
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1

    grid = []
    start = end = None
    for i in range(n):
        row = []
        for j in range(n):
            row.append(data[idx])
            if data[idx] == "A":
                start = (i, j)
            elif data[idx] == "B":
                end = (i, j)
            idx += 1
        grid.append(row)

    # BFS: 从A出发，交替走+和-
    # 状态：(行, 列, 上一步的符号类型)
    # 上一步符号: '+' 表示下一步必须走 '-', '-' 表示下一步必须走 '+', None 表示从A出发
    visited = [[[False] * 3 for _ in range(n)] for _ in range(n)]
    # 0: 从A出发(下一步可走+或-), 1: 上一步走+(下一步走-), 2: 上一步走-(下一步走+)
    q = deque()
    q.append((start[0], start[1], 0, 0))  # (r, c, last_sign_type, steps)
    visited[start[0]][start[1]][0] = True

    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    while q:
        r, c, last_sign, steps = q.popleft()

        for dr, dc in dirs:
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= n:
                continue

            cell = grid[nr][nc]

            if cell == "B":
                # B是安全区，可以从任意符号到达
                print(steps + 1)
                return

            if last_sign == 0:
                # 从A出发，可以走+或-
                if cell == "+":
                    new_sign = 1
                elif cell == "-":
                    new_sign = 2
                else:
                    continue
            elif last_sign == 1:
                # 上一步走+，下一步必须走-
                if cell != "-":
                    continue
                new_sign = 2
            else:
                # 上一步走-，下一步必须走+
                if cell != "+":
                    continue
                new_sign = 1

            if not visited[nr][nc][new_sign]:
                visited[nr][nc][new_sign] = True
                q.append((nr, nc, new_sign, steps + 1))

    print(-1)


if __name__ == "__main__":
    solve()
