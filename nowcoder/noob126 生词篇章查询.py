"""
描述
现有
N
N 篇文档，每篇文档由若干小写字母单词组成。记第
i
i 篇文档的单词集合为
S
i
S
i
​
 。现给定
M
M 个查询单词
w
1
,
w
2
,
…
,
w
M
w
1
​
 ,w
2
​
 ,…,w
M
​
 ，请分别求出每个
w
j
w
j
​
  所在的文档编号集合。
输入描述：
第一行包含两个整数
N

(
1
≦
N
≦
1
0
3
)
N (1≦N≦10
3
 )。
接下来
N
N 行，第
i
i 行首先给出整数
L
i

(
1
≦
L
i
,

∑
i
=
1
N
L
i
≦
5
×
1
0
5
)
L
i
​
  (1≦L
i
​
 , ∑
i=1
N
​
 L
i
​
 ≦5×10
5
 )，随后给出
L
i
L
i
​
  个由小写字母组成的单词，单词间以空格分隔。
接着一行一个整数
M

(

1
≦
M
≦
1
0
4
)
M ( 1≦M≦10
4
 )。
随后
M
M 行，每行包含一个由小写字母组成的查询单词
w
j
w
j
​
 。
输出描述：
对于每个查询单词
w
j
w
j
​
 ，输出一行，按升序列出所有满足
w
j
∈
S
i
w
j
​
 ∈S
i
​
  的文档编号
i
i，编号间以空格分隔；若对应集合为空，则输出空行。
示例1
输入：
3
5 hello world this is test
4 sample test case data
3 test world data
4
test
data
hello
missing
复制
输出：
1 2 3
2 3
1
复制
示例2
输入：
2
3 a b a
2 x y
2
b
z
复制
输出：
1
复制
备注：
"""

n = int(input())
li = []
for _ in range(n):
    line = input().split()
    l = int(line[0])
    words = line[1 : l + 1]
    li.append(set(words))

m = int(input())
for _ in range(m):
    w = input()
    for i, s in enumerate(li):
        if w in s:
            print(i + 1, end=" ")
    print()
