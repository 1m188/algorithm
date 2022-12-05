'''
让我们定义d 
n
​
 为：d 
n
​
 =p 
n+1
​
 −p 
n
​
 ，其中p 
i
​
 是第i个素数。显然有d 
1
​
 =1，且对于n>1有d 
n
​
 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10 
5
 )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
'''

import sys


def isPrime(x: int) -> bool:
    '''
    判断是否质数
    '''
    if x <= 1: return False
    if x == 2: return True
    if x % 2 == 0: return False
    for i in range(3, int(x**0.5) + 1):
        if x % i == 0: return False
    return True


n = int(input())

if n < 5:
    print(0)
    sys.exit()

nums = [True for _ in range(n + 1)]

idx = 2
while idx <= n:
    if nums[idx]:
        if not isPrime(idx): nums[idx] = False
        jdx = idx * 2
        while jdx <= n:
            nums[jdx] = False
            jdx += idx
    idx += 1

res = 0
for i in range(2, n + 1 - 2):
    if nums[i] and nums[i + 2]: res += 1
print(res)
