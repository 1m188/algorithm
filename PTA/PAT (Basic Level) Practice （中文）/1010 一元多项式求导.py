'''
设计函数求一元多项式的导数。（注：x 
n
 （n为整数）的一阶导数为nx 
n−1
 。）

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''

nums = list(map(int, input().split()))

res = []

for i in range(0, len(nums), 2):
    x, p = nums[i], nums[i + 1]
    if p != 0:
        res.append(x * p)
        res.append(p - 1)
    else:
        break

if not res:
    res = [0, 0]

print(res[0], end='')
for i in range(1, len(res)):
    print(f' {res[i]}', end='')
