"""
描述
给定长度为
n
n 的入栈序列
pushed
pushed 和长度为
n
n 的出栈序列
popped
popped，两者均为
1
∼
n
1∼n 的排列。初始时栈为空，只允许在栈顶进行插入（入栈）和删除（出栈）操作；若可通过若干操作使出栈顺序等于
popped
popped，则称
popped
popped 为合法出栈序列。

现有
q
q 组测试，每组给定对应序列，判断
popped
popped 是否为合法出栈序列。

【名词解释】
【排列】长度为
n
n 的 排列 是由
1
∼
n
1∼n 的
n
n 个整数按任意顺序组成的序列，其中每个整数恰好出现一次。
输入描述：
第一行输入整数
q

(
1
≦
q
≦
5
)
q (1≦q≦5)，表示测试组数。
接下来对于每组测试，依次输入：
1.
1.
​
 一行整数
n

(
1
≦
n
≦
1
0
5
)
n (1≦n≦10
5
 )，表示序列长度；
2.
2.
​
 一行
n
n 个整数，为入栈序列
pushed
1
,
…
,
pushed
n
pushed
1
​
 ,…,pushed
n
​
 ；
3.
3.
​
 一行
n
n 个整数，为出栈序列
popped
1
,
…
,
popped
n
popped
1
​
 ,…,popped
n
​
 。
输出描述：
对于每组测试，输出一行，如果
popped
popped 为合法出栈序列，则输出
Yes
Yes；否则输出
No
No。
示例1
输入：
2
5
1 2 3 4 5
2 5 4 1 3
5
1 2 3 4 5
2 5 4 3 1
复制
输出：
No
Yes
复制
示例2
输入：
2
3
1 2 3
2 3 1
3
1 2 3
2 1 3
复制
输出：
Yes
Yes
"""


def judge(pushed: list[int], popped: list[int]) -> bool:
    stack = []
    pui = 0
    poi = 0
    while pui < len(pushed) and poi < len(popped):
        if not stack or stack[-1] != popped[poi]:
            stack.append(pushed[pui])
            pui += 1
        else:
            stack.pop()
            poi += 1
    while stack and poi < len(popped) and stack[-1] == popped[poi]:
        stack.pop()
        poi += 1
    return pui == len(pushed) and poi == len(popped)


q = int(input().strip())
for _ in range(q):
    n = int(input().strip())
    pushed = list(map(int, input().strip().split()))
    popped = list(map(int, input().strip().split()))
    print("Yes" if judge(pushed, popped) else "No")
