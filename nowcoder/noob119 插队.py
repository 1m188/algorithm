"""
描述
在熙熙攘攘的商业街区，一家人气爆棚的网红奶茶店前总是大排长龙。然而，在这有序的队伍中，偶尔也会出现不和谐的插队行为——插队不仅破坏公平排队的秩序，也引发其他顾客的不满与抱怨。

假设店前有
n
n 位顾客按从前到后依次排队，初始队列为
s
1
,
s
2
,
…
,
s
n
s
1
​
 ,s
2
​
 ,…,s
n
​
 。随后发生
m
m 次插队事件。在第
i
i 次事件中，名为
x
i
x
i
​
  的顾客会移动到名为
y
i
y
i
​
  的顾客前面。

请你模拟所有插队事件，输出最终队列中顾客的排队顺序。
输入描述：
第一行输入两个整数
n
,
m
n,m，用空格隔开，表示顾客人数和插队事件次数，满足

2
≦
n
≦
2
×
1
0
5
,
1
≦
m
≦
2
×
1
0
5
2≦n≦2×10
5
 ,1≦m≦2×10
5
 。
第二行输入
n
n 个字符串
s
1
,
s
2
,
…
,
s
n
s
1
​
 ,s
2
​
 ,…,s
n
​
 ，用空格隔开，表示初始排队顺序。每个字符串长度
1
≦
∣
s
i
∣
≦
10
1≦∣s
i
​
 ∣≦10，仅由小写字母组成；所有字符串两两互不相同。

接下来
m
m 行，每行输入两个字符串
x
i
,
y
i
x
i
​
 ,y
i
​
 ，用空格隔开，表示第
i
i 次插队事件中，名为
x
i
x
i
​
  的顾客插入到名为
y
i
y
i
​
  的顾客前。保证
x
i
,
y
i
x
i
​
 ,y
i
​
  均在初始队列中出现，且
x
i
≠
y
i
x
i
​


​
 =y
i
​
 。
输出描述：
输出一行
n
n 个字符串，用空格隔开，表示所有插队事件结束后队列中顾客的顺序。
示例1
输入：
4 6
alpha bravo charlie delta
bravo alpha
charlie alpha
delta alpha
charlie bravo
delta bravo
charlie delta
复制
输出：
charlie delta bravo alpha
复制
说明：
初始队列：alpha bravo charlie delta
事件 1：bravo alpha charlie delta
事件 2：bravo charlie alpha delta
事件 3：bravo charlie delta alpha
事件 4：charlie bravo delta alpha
事件 5：charlie delta bravo alpha
事件 6：charlie delta bravo alpha
示例2
输入：
3 2
amy bob cath
cath amy
bob amy
复制
输出：
cath bob amy
复制
说明：
初始队列：amy bob cath
事件 1：cath amy bob
事件 2：cath bob amy
"""

import sys


inputs = sys.stdin.read().splitlines()

n, m = map(int, inputs[0].split())

# id 设置为 1, 2, ..., n
name2id = {}
id2name = ["" for _ in range(n + 1)]
prev, post = [0 for _ in range(n + 2)], [0 for _ in range(n + 2)]

prev[n + 1] = n
post[0] = 1
for i, name in enumerate(inputs[1].split()):
    id_ = i + 1
    name2id[name] = id_
    id2name[id_] = name
    prev[id_] = id_ - 1
    post[id_] = id_ + 1

for i in range(2, 2 + m):
    x, y = inputs[i].split()
    id_x = name2id[x]
    id_y = name2id[y]

    post[prev[id_x]] = post[id_x]
    prev[post[id_x]] = prev[id_x]

    post[prev[id_y]] = id_x
    prev[id_x] = prev[id_y]
    post[id_x] = id_y
    prev[id_y] = id_x

ans = []
cur_id = 0
while post[cur_id] != n + 1:
    ans.append(id2name[post[cur_id]])
    cur_id = post[cur_id]
print(" ".join(ans))
