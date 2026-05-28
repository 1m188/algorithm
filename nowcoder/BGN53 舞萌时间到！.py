"""
描述
在舞萌 DX 中，对应判定 `P`,`p`,`G`,`g`,`m` 的 dx 分分别为
3
,
2
,
1
,
0
,
0
3,2,1,0,0。给定旺仔哥哥一次玩舞萌的判定序列字符串
s
s，长度为
∣
s
∣
∣s∣，其中第
i
i 个字符表示旺仔哥哥第
i
i 次敲击音符时得到的判定结果。

现有
q
q 次询问，每次给出区间
[
l
,
r
]
[l,r]，求此区间内的 dx 分总和。
输入描述：
第一行输入一个字符串
s

(
1
≤
∣
s
∣
≤
1
0
6
)
s (1≤∣s∣≤10
6
 )，仅由 `P`,`p`,`G`,`g`,`m`这五种字符构成；
第二行输入一个整数
q

(
1
≤
q
≤
1
0
4
)
q (1≤q≤10
4
 )；
接下来的
q
q 行，每行输入两个整数
l
,
r

(
1
≤
l
≤
r
≤
∣
s
∣
)
l,r (1≤l≤r≤∣s∣)。
输出描述：
按询问顺序输出
q
q 行，每行一个整数，表示对应区间的 dx 分总和。
示例1
输入：
GPPmGmGGGp
10
2 4
3 7
2 7
3 5
3 7
7 9
6 7
2 5
6 6
2 8
复制
输出：
6
5
8
4
5
3
1
7
0
9
"""

import sys

SCORE = {"P": 3, "p": 2, "G": 1, "g": 0, "m": 0}


def solve():
    data = sys.stdin.buffer.read().split()
    s = data[0].decode()
    q = int(data[1])

    n = len(s)
    # 前缀和，prefix[i]表示前i个字符的dx分总和（1-indexed）
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + SCORE[s[i]]

    out = []
    idx = 2
    for _ in range(q):
        l = int(data[idx])
        r = int(data[idx + 1])
        idx += 2
        out.append(str(prefix[r] - prefix[l - 1]))

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    solve()
