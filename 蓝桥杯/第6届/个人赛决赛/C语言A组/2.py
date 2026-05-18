"""

标题：四阶幻方

把1~16的数字填入4x4的方格中，使得行、列以及两个对角线的和都相等，满足这样的特征时称为：四阶幻方。

四阶幻方可能有很多方案。如果固定左上角为1，请计算一共有多少种方案。
比如：
  1  2 15 16
 12 14  3  5
 13  7 10  4
  8 11  6  9

以及：
  1 12 13  8
  2 14  7 11
 15  3 10  6
 16  5  4  9

就可以算为两种不同的方案。

请提交左上角固定为1时的所有方案数字，不要填写任何多余内容或说明文字。

"""

MAGIC = 34


def solve():
    grid = [0] * 16
    used = [False] * 17
    grid[0] = 1
    used[1] = True
    count = 0

    def dfs(pos):
        nonlocal count
        if pos == 16:
            count += 1
            return
        if pos == 0:
            dfs(1)
            return
        r, c = pos // 4, pos % 4

        if c > 0:
            row_sum = sum(grid[r * 4 + j] for j in range(c))
            if row_sum > MAGIC:
                return

        for v in range(2, 17):
            if used[v]:
                continue
            grid[pos] = v
            used[v] = True

            if c == 3:
                s = grid[r * 4] + grid[r * 4 + 1] + grid[r * 4 + 2] + grid[r * 4 + 3]
                if s != MAGIC:
                    used[v] = False
                    grid[pos] = 0
                    continue
            if r == 3:
                s = grid[c] + grid[4 + c] + grid[8 + c] + grid[12 + c]
                if s != MAGIC:
                    used[v] = False
                    grid[pos] = 0
                    continue
            if r == 3 and c == 3:
                s = grid[0] + grid[5] + grid[10] + grid[15]
                if s != MAGIC:
                    used[v] = False
                    grid[pos] = 0
                    continue
            if r == 3 and c == 0:
                s = grid[3] + grid[6] + grid[9] + grid[12]
                if s != MAGIC:
                    used[v] = False
                    grid[pos] = 0
                    continue

            dfs(pos + 1)
            used[v] = False
            grid[pos] = 0

    dfs(0)
    print(count)


if __name__ == "__main__":
    solve()
