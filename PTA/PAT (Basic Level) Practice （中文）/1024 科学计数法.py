'''
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
'''

nl = input().split('E')
num_sign = nl[0][0]
if num_sign == '+': num_sign = ''
num = nl[0][1:]
index_sign = nl[1][0]
index = int(nl[1][1:])

numl = list(num)
numl.remove('.')
pi = 1
if index_sign == '+':
    for _ in range(index):
        pi += 1
        if pi > len(numl): numl.append('0')
    if pi < len(numl): numl.insert(pi, '.')
    print(num_sign + ''.join(numl))
else:
    for _ in range(index):
        pi -= 1
        if pi <= 0:
            numl.insert(0, '0')
            pi += 1
    numl.insert(pi, '.')
    print(num_sign + ''.join(numl))
