'''
描述
找出字符串中第一个只出现一次的字符


数据范围：输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 


输入描述：
输入一个非空字符串

输出描述：
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入：
asdfasdfo

复制
输出：
o

'''

import sys

s = input()

set1 = set()
set2 = set()

for c in s:
    if c in set2: continue
    if c in set1:
        set1.remove(c)
        set2.add(c)
        continue
    set1.add(c)

for c in s:
    if c in set1:
        print(c)
        sys.exit()
print(-1)
