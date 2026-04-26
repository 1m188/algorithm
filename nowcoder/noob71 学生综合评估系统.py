"""
描述
牛客大学正在开发一套新的学生综合评估系统，旨在更全面地反映学生的学业水平和实践能力。
系统对每位学生记录唯一学号
i
d
id、学业成绩
A
A（满分
100
100 分）和社会实践得分
B
B（满分
100
100 分）。

综合分数按以下权重计算：
∙

∙学业成绩占
70
%
70%；
∙

∙社会实践得分占
30
%
30%；

定义

S
=
A
×
70
%
+
B
×
30
%
S=A×70%+B×30%

若学生同时满足：
∙

∙学业成绩与社会实践得分之和
A
+
B
>
140
A+B>140；
∙

∙综合分数
S
≧
80
S≧80；
则评定为 Excellent，否则为 Not excellent。

你需要实现一个函数，接受的参数为学生类型的类，返回值为这个学生是否会被评定为 Excellent 的布尔值。
输入描述：
输入数据仅用于主函数获取数据后调用你实现的函数，你其实可以不用管。

第一行输入整数
N
N，表示学生人数 (
1
≦
N
≦
1
0
3
1≦N≦10
3
 )。

接下来
N
N 行，每行输入三个整数
i
d
,
A
,
B
id,A,B，分别表示学号、学业成绩和社会实践得分，满足：

1
≦
i
d
≦
1
0
4
1≦id≦10
4
 ；
0
≦
A
,
B
≦
100
0≦A,B≦100。
输出描述：
输出数据仅用于主函数获取返回值后于评测机交互，你其实可以不用管。
输出
N
N 行，第
i
i 行对应第
i
i 位学生：若评定为优秀，输出 `Excellent`；否则输出 `Not excellent`。
示例1
输入：
4
1223 95 59
1224 50 7
1473 32 45
1556 86 99
复制
输出：
Excellent
Not excellent
Not excellent
Excellent
复制
备注：
"""


class Student:
    def __init__(self, student_id, academic_score, activity_score):
        self.id = student_id
        self.academic_score = academic_score
        self.activity_score = activity_score

    @property
    def S(self) -> float:
        return self.academic_score * 0.7 + self.activity_score * 0.3


def is_excellent(student: Student):
    # TODO: 实现优秀标准的判断逻辑
    return student.S >= 80 and student.academic_score + student.activity_score > 140


def main():
    n = int(input())

    for _ in range(n):
        student_id, academic, activity = map(int, input().split())

        student = Student(student_id, academic, activity)
        if is_excellent(student):
            print("Excellent")
        else:
            print("Not excellent")


if __name__ == "__main__":
    main()
