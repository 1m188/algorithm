"""
描述
期末考试结束了，老师开始忙着给每个同学登记成绩。这次考试共有语文、数学和外语三门科目。登记过程中有如下三种操作：
∙

∙操作 `1 x y z`：登记一位同学的成绩，语文
x
x 分、数学
y
y 分、外语
z
z 分；
∙

∙操作 `2`：输出当前成绩最好的同学的三门成绩；
∙

∙操作 `3`：删除成绩最好的同学的记录（若有并列，则只删除一人）。

“成绩最好” 的判定规则为：首先比较总成绩
x
+
y
+
z
x+y+z，总成绩高者更好；若相同，则比较语文成绩
x
x；若仍相同，则比较数学成绩
y
y；再相同时比较外语成绩
z
z。
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
n 行，每行是一次操作：
∙

∙若操作类型为 `1`，则形式为 `1 x y z`，其中
1
≦
x
,
y
,
z
<
100
1≦x,y,z<100；
∙

∙若操作类型为 `2` 或 `3`，则形式为单个整数 `2` 或 `3`。
输出描述：
对于每次操作 `2`，在一行中输出 `x y z`，表示该次查询时成绩最好的同学的语文、数学和外语成绩。
示例1
输入：
10
1 93 27 6
2
3
1 31 46 2
1 100 85 84
2
2
1 2 40 3
2
2
复制
输出：
93 27 6
100 85 84
100 85 84
100 85 84
100 85 84
复制
说明：
∙

∙操作 1 登记
(
93
,
27
,
6
)
(93,27,6)，操作 2 输出当前最优
(
93
,
27
,
6
)
(93,27,6)；
∙

∙操作 3 删除该记录；
∙

∙接着操作 1 登记
(
31
,
46
,
2
)
(31,46,2)，操作 1 登记
(
100
,
85
,
84
)
(100,85,84)；
∙

∙连续两次操作 2 均输出
(
100
,
85
,
84
)
(100,85,84)；
∙

∙操作 1 登记
(
2
,
40
,
3
)
(2,40,3) 后的两次操作 2 仍输出
(
100
,
85
,
84
)
(100,85,84)，因为它仍是最优。
备注：
"""

import heapq
import functools


@functools.total_ordering
class Student:
    def __init__(self, chinese, math, english):
        self.chinese = chinese
        self.math = math
        self.english = english
        self.sum = chinese + math + english

    def __eq__(self, other: "Student") -> bool:
        return (
            self.chinese == other.chinese
            and self.math == other.math
            and self.english == other.english
        )

    def __lt__(self, other: "Student") -> bool:
        # 实现比较逻辑，按照总分、语文、数学、英语的优先级排序
        # 为适应最小堆的特点，这里比较取反
        if self.sum != other.sum:
            return self.sum > other.sum
        if self.chinese != other.chinese:
            return self.chinese > other.chinese
        if self.math != other.math:
            return self.math > other.math
        return self.english > other.english


# 使用Python的heapq模块实现优先队列
s = []


def insertValue(chinese, math, english):
    # 实现插入操作

    heapq.heappush(s, Student(chinese, math, english))


def deleteValue():
    # 实现删除操作

    heapq.heappop(s)


def getTop():
    # 返回成绩最好的学生

    return s[0]


if __name__ == "__main__":
    q = int(input())
    for _ in range(q):
        line = input().split()
        op = int(line[0])
        if op == 1:
            chinese = int(line[1])
            math = int(line[2])
            english = int(line[3])
            insertValue(chinese, math, english)
        elif op == 2:
            top = getTop()
            print(f"{top.chinese} {top.math} {top.english}")
        elif op == 3:
            deleteValue()
