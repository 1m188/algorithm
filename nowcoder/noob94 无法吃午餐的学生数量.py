"""
描述
定义长度为
n
n
(
1
≦
n
≦
100
)
(1≦n≦100) 的序列
s
t
u
d
e
n
t
s
=
[
s
1
,
…
,
s
n
]
students=[s
1
​
 ,…,s
n
​
 ]
(
s
i
∈
{
0
,
1
}
)
(s
i
​
 ∈{0,1})表示队列中第
i
i 名学生的偏好，序列
s
a
n
d
w
i
c
h
e
s
=
[
t
1
,
…
,
t
n
]
sandwiches=[t
1
​
 ,…,t
n
​
 ]
(
t
i
∈
{
0
,
1
}
)
(t
i
​
 ∈{0,1}) 表示栈顶至栈底的三明治类型（
t
1
t
1
​
  为栈顶）。初始时，队列与栈均包含
n
n 名学生与
n
n 个三明治。每步操作如下：

∙

∙若
s
1
=
t
1
s
1
​
 =t
1
​
 ，则该学生取走该三明治并移出队列，三明治出栈；
∙

∙否则，将队首学生移至队尾；

重复上述操作直至所有剩余学生均不满足栈顶三明治偏好。

你需要补全一个函数求无法拿到三明治的学生人数，接受的参数为：

∙

∙整数序列
s
t
u
d
e
n
t
s
students，长度为
n
n；
∙

∙整数序列
s
a
n
d
w
i
c
h
e
s
sandwiches，长度为
n
n。

函数的返回值为一个正整数，表示无法拿到三明治的学生人数。
示例1
输入：
[1,1,0,1],[1,0,0,1]
复制
返回值：
2
复制
备注：
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param students int整型一维数组
# @param sandwiches int整型一维数组
# @return int整型
#
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        # write code here

        f = True
        while f and students:
            f = False
            n = len(students)
            for _ in range(n):
                if students[0] == sandwiches[0]:
                    f = True
                    students.pop(0)
                    sandwiches.pop(0)
                    break
                else:
                    students.append(students.pop(0))
        return len(students)
