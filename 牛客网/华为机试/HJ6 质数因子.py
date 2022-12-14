'''
描述
功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）


数据范围： 1 \le n \le 2 \times 10^{9} + 14 \1≤n≤2×10 
9
 +14 
输入描述：
输入一个整数

输出描述：
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。

示例1
输入：
180
复制
输出：
2 2 3 3 5
'''


def judge(x: int) -> bool:
    if x <= 1: return False
    if x == 2: return True
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0: return False
    return True


n = int(input())

primes = [2]
res = []

while n != 1:
    if n % primes[-1] == 0:
        res.append(primes[-1])
        n //= primes[-1]
    else:
        f = False
        # 虽然说是找下一个质数，但作为因数，其是有上限的，和判定质数类似
        for i in range(primes[-1] + 1, int(n**0.5) + 1):
            if (judge(i)):
                primes.append(i)
                f = True
                break
        if not f:  # 没找到下一个质数，那么就只有它自己本身一个因数了
            res.append(n)
            break

print(' '.join(map(str, res)))
