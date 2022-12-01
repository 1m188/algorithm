'''
描述
输入 n 个整型数，统计其中的负数个数并求所有非负数的平均值，结果保留一位小数，如果没有非负数，则平均值为0
本题有多组输入数据，输入到文件末尾。

数据范围：1 \le n \le 50000 \1≤n≤50000  ，其中每个数都满足 |val| \le 10^{6} \∣val∣≤10 
6
  
输入描述：
输入任意个整数，每行输入一个。

输出描述：
输出负数个数以及所有非负数的平均值

示例1
输入：
-13
-4
-7
复制
输出：
3
0.0
复制
示例2
输入：
-12
1
2
复制
输出：
1
1.5
'''

import sys

n1, n2 = 0, 0
avg = 0.0

for line in sys.stdin:
    line = line.strip()
    if not line: break

    num = int(line)
    if num < 0: n1 += 1
    else:
        n2 += 1
        avg += num

print('%d\n%.1f' % (n1, avg / n2 if n2 else 0.0))
