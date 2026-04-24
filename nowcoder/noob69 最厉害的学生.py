"""
描述
给定
N
N 名学生及其信息，包含：
∙

∙ 姓名
s
s，仅含小写字母，长度不超过
8
8；
∙

∙ 语文、数学、英语成绩
c
1
,
c
2
,
c
3
c
1
​
 ,c
2
​
 ,c
3
​
 ，整数且
0
≦
c
i
≦
150
0≦c
i
​
 ≦150。
定义总分
T
=
c
1
+
c
2
+
c
3
T=c
1
​
 +c
2
​
 +c
3
​
 ，求总分最大的学生信息；若存在多名，取输入顺序最小者。
输入描述：
第一行包含整数
N
N，
(
1
≦
N
≦
1000
)
(1≦N≦1000)；
接下来
N
N 行，每行包含字符串
s
s 和三个整数
c
1
,
c
2
,
c
3
c
1
​
 ,c
2
​
 ,c
3
​
 ，依次表示学生姓名及三门成绩。
输出描述：
输出姓名
s
s 及对应成绩
c
1
,
c
2
,
c
3
c
1
​
 ,c
2
​
 ,c
3
​
 ，以空格分隔。
示例1
输入：
4
alice 100 90 80
david 90 100 80
mary 80 80 100
bob 100 90 80
复制
输出：
alice 100 90 80
复制
说明：
样例中，alice 与 bob 总分均为
270
270，顺序提前者 alice 为答案。
"""

import functools


@functools.total_ordering
class Student:
    def __init__(self, index: int, name: str, c1: int, c2: int, c3: int):
        self.index = index
        self.name = name
        self.c1 = c1
        self.c2 = c2
        self.c3 = c3

    @property
    def T(self):
        return self.c1 + self.c2 + self.c3

    def __eq__(self, other: "Student") -> bool:
        return False

    def __lt__(self, other: "Student") -> bool:
        return self.T < other.T or (self.T == other.T and self.index > other.index)


ans = None
N = int(input())
for i in range(N):
    s, c1, c2, c3 = input().split()
    c1, c2, c3 = int(c1), int(c2), int(c3)
    student = Student(i, s, c1, c2, c3)
    if ans == None:
        ans = student
    elif student > ans:
        ans = student

print(ans.name, ans.c1, ans.c2, ans.c3)
