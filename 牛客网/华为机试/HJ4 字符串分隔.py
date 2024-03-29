'''
描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串

示例1
输入：
abc
复制
输出：
abc00000
'''

import sys

line = sys.stdin.readline().strip('\n\r')

if not line: sys.exit()

while len(line) >= 8:
    print(line[:8])
    line = line[8:]

if line:
    size = len(line)
    while size < 8:
        line += '0'
        size += 1
    print(line)
