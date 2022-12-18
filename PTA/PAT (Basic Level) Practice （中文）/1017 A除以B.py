'''
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
代码长度限制
16 KB
时间限制
100 ms
内存限制
64 MB
'''

a, b = input().split()
b = int(b)
a = list(map(int, a))
res = ''

x = 0
cnt = 0
while a:
    while x < b:
        cnt += 1
        if cnt > 1: res += '0'  # 中间上了一位还不够的时候补零
        x = x * 10 + a.pop(0)
        if not a: break
    if x >= b:  # 到最后几位的时候全都是余数，不再上商
        res += str(x // b)
        x %= b
    else:
        res += '0'
    cnt = 0

if set(res) != set(['0']): res = res.lstrip('0')  # 如果商全0，即a<b
print(f'{res} {x}')
