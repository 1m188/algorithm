'''
描述
给定一些同学的信息（名字，成绩）序列，请你将他们的信息按照成绩从高到低或从低到高的排列,相同成绩

都按先录入排列在前的规则处理。

例示：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

jack      70

Tom       70
peter     96

注：0代表从高到低，1代表从低到高

数据范围：人数：1\le n \le 200\1≤n≤200 
进阶：时间复杂度：O(nlogn)\O(nlogn) ，空间复杂度：O(n)\O(n) 
输入描述：
第一行输入要排序的人的个数n，第二行输入一个整数表示排序的方式，之后n行分别输入他们的名字和成绩，
以一个空格隔开

输出描述：
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

示例1
输入：
3
0
fang 90
yang 50
ning 70
复制
输出：
fang 90
ning 70
yang 50
复制
示例2
输入：
3
1
fang 90
yang 50
ning 70
复制
输出：
yang 50
ning 70
fang 90
'''

import sys

n = int(sys.stdin.readline().strip())
way = int(sys.stdin.readline().strip())

li: list[str, int] = []
for _ in range(n):
    name, score = sys.stdin.readline().strip().split(' ')
    li.append([name, int(score)])

if way == 0: li.sort(key=lambda x: x[1], reverse=True)
else: li.sort(key=lambda x: x[1])

for name, score in li:
    print(f'{name} {score}')
