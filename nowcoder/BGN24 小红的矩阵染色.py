"""
描述
小红拿到了一个矩阵，初始有一些格子被染成了黑色。现在小红希望把最多
k
k个未被染成黑色的格子染成红色，具体的计分方式是：如果一个红色格子下方相邻的格子也是红色，那么这个红色格子可以获得1分。
小红想知道，最多可以得到多少分？
输入描述：
第一行输入三个正整数
n
,
m
,
k
n,m,k，代表矩阵的行数和列数、以及小红最多可以染色的格子数量。
接下来的
n
n行，每行输入一个长度为
m
m的字符串，用来表示矩阵的初始染色情况。'*'字符代表黑色，'o'字符代表白色。
1
≤
n
,
m
≤
1000
1≤n,m≤1000
1
≤
k
≤
n
∗
m
1≤k≤n∗m
输出描述：
一个整数，代表小红可以获得的最大分数。
示例1
输入：
4 4 3
*o*o
oooo
****
oooo
复制
输出：
1
复制
说明：
将矩阵染色成如下样式即可（'r'代表红色）：
*r*o
oroo
****
oooo

示例2
输入：
3 3 3
*o*
*o*
*o*
复制
输出：
2
"""

n, m, k = map(int, input().split())
mat = []
for _ in range(n):
    mat.append(list(input()))
assert len(mat) == n and len(mat[0]) == m

lo = []
for i in range(m):
    r = 0
    while r < n:
        if mat[r][i] == "*":
            r += 1
            continue
        cnt = 1
        r2 = r + 1
        while r2 < n:
            if mat[r2][i] == "o":
                cnt += 1
            else:
                break
            r2 += 1
        lo.append(cnt)
        r = r2

lo.sort(reverse=True)
ans = 0
for i in lo:
    if k - i >= 0:
        ans += i - 1
        k -= i
        if k <= 0:  # 注意可能刚好用完的情况
            break
    else:
        ans += k - 1
        break
print(ans)
