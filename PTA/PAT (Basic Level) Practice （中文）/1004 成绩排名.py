'''
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：
每个测试输入包含 1 个测试用例，格式为

第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
  ... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''

import sys

n = int(sys.stdin.readline().strip())

high, low = ['', '', -1], ['', '', 101]

for _ in range(n):
    name, number, grade = sys.stdin.readline().strip().split(' ')
    grade = int(grade)
    if grade > high[2]:
        high = [name, number, grade]
    if grade < low[2]:
        low = [name, number, grade]

print(f'{high[0]} {high[1]}\n{low[0]} {low[1]}')
