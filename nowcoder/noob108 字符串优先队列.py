"""
描述
给定一个字符串序列，初始为空，请支持下面三种操作：

∙

∙操作 1：给定一个字符串
s
s，将
s
s 加入到序列中；

∙

∙操作 2：输出序列中字典序最小的字符串；

∙

∙操作 3：删除序列中字典序最小的字符串（若有多个字典序最小的，只删除 1 个）。
输入描述：
第一行输入一个整数
n
n（
1
≦
n
≦
1
0
6
1≦n≦10
6
 ），表示操作次数。

接下来
n
n 行，每行表示一次操作。每行首先有一个整数
o
p
op 表示操作类型：

- 若
o
p
=
1
op=1，则后接一个字符串
s
s，表示将
s
s 加入序列；

- 若
o
p
=
2
op=2，则表示输出序列中字典序最小的字符串；

- 若
o
p
=
3
op=3，则表示删除序列中字典序最小的字符串。

保证
o
p
∈
{
1
,
2
,
3
}
op∈{1,2,3}，且所有加入字符串的长度之和不超过
1
0
6
10
6
 。
输出描述：
对于每个操作 2，在一行中输出一个字符串，表示操作时序列中字典序最小的字符串。
示例1
输入：
5
1 2
1 5
2
3
2
复制
输出：
2
5
复制
说明：
操作顺序：

1. 加入 "abc"，序列 = ["abc"]；

2. 加入 "cda"，序列 = ["abc","cda"]；

3. 输出最小 = "abc"；

4. 删除最小（"abc"），序列 = ["cda"]；

5. 输出最小 = "cda"。
备注：

"""

import heapq

# 使用Python的heapq模块实现字典序最小的字符串堆
s = []


def insertValue(x):
    # 实现插入操作

    heapq.heappush(s, x)


def deleteValue():
    # 实现删除操作

    heapq.heappop(s)


def getTop():
    # 返回字典序最小的字符串

    return s[0]


if __name__ == "__main__":
    q = int(input())
    for _ in range(q):
        line = input().split()
        op = int(line[0])
        if op == 1:
            x = line[1]
            insertValue(x)
        elif op == 2:
            print(getTop())
        elif op == 3:
            deleteValue()
