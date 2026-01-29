'''
# 涂国旗

## 题目描述

某国法律规定，只要一个由 $N \times M$ 个小方块组成的旗帜符合如下规则，就是合法的国旗。（毛熊：阿嚏——）

- 从最上方若干行（至少一行）的格子全部是白色的；
- 接下来若干行（至少一行）的格子全部是蓝色的；
- 剩下的行（至少一行）全部是红色的；

现有一个棋盘状的布，分成了 $N$ 行 $M$ 列的格子，每个格子是白色蓝色红色之一，小 a 希望把这个布改成该国国旗，方法是在一些格子上涂颜料，盖住之前的颜色。

小a很懒，希望涂最少的格子，使这块布成为一个合法的国旗。

## 输入格式

第一行是两个整数 $N,M$。

接下来 $N$ 行是一个矩阵，矩阵的每一个小方块是`W`（白），`B`（蓝），`R`（红）中的一个。

## 输出格式

一个整数，表示至少需要涂多少块。

## 样例 #1

### 样例输入 #1

```
4 5
WRWRW
BWRWB
WRWRW
RWBWR
```

### 样例输出 #1

```
11
```

## 提示

### 样例解释

目标状态是：

```plain
WWWWW
BBBBB
RRRRR
RRRRR
```
一共需要改 $11$ 个格子。

### 数据范围

对于 $100\%$ 的数据，$N,M \leq 50$。
'''

n, m = map(int, input().split())
mat: list[list[str]] = []
for _ in range(n):
    mat.append(list(input()))
res = n * m + 1


def calc(wbr: list[int]) -> int:
    '''
    整体计算需要涂的格子数目
    '''
    w, b, r = wbr
    res = 0
    for i in range(w):
        res += m - mat[i].count('W')
    for i in range(w, w + b):
        res += m - mat[i].count('B')
    for i in range(w + b, w + b + r):
        res += m - mat[i].count('R')
    return res


wbr = []


def dfs():
    '''
    递归求取三个部分的不同数目的组合穷举
    '''
    if len(wbr) == 3:
        global res
        if sum(wbr) == n: res = min(res, calc(wbr))
        return
    for i in range(1, n - 1):
        x = sum(wbr) + i
        if x <= n:
            wbr.append(i)
            dfs()
            wbr.pop()
        else:
            break


dfs()
print(res)
