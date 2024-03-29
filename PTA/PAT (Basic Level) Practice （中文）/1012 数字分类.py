'''
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A 
1
​
  = 能被 5 整除的数字中所有偶数的和；
A 
2
​
  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n 
1
​
 −n 
2
​
 +n 
3
​
 −n 
4
​
 ⋯；
A 
3
​
  = 被 5 除后余 2 的数字的个数；
A 
4
​
  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A 
5
​
  = 被 5 除后余 4 的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A 
1
​
 ~A 
5
​
  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若分类之后某一类不存在数字，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''

nums = list(map(int, input().split()))
n = nums.pop(0)
a = ['N' for _ in range(5)]

for i in nums:
    if i % 10 == 0: a[0] = i if a[0] == 'N' else a[0] + i

idx = 0
for i in nums:
    if i % 5 == 1:
        a[1] = ((-1)**idx) * i if a[1] == 'N' else a[1] + ((-1)**idx) * i
        idx += 1

for i in nums:
    if i % 5 == 2: a[2] = 1 if a[2] == 'N' else a[2] + 1

cnt = 0
for i in nums:
    if i % 5 == 3:
        a[3] = i if a[3] == 'N' else a[3] + i
        cnt += 1
if cnt: a[3] /= cnt

for i in nums:
    if i % 5 == 4: a[4] = i if a[4] == 'N' else max(a[4], i)

print(f'{a[0]} {a[1]} {a[2]} ', end='')
if cnt: print('%.1f ' % a[3], end='')
else: print(f'{a[3]} ', end='')
print(a[4])
