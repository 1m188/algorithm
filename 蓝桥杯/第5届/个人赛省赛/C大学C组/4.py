"""
蓝桥杯.第5届.个人赛省赛.C大学C组.4


1193是个素数，对它循环移位后发现：
1931,9311,3119也都是素数，这样特征的数叫：循环素数。

你能找出具有这样特征的5位数的循环素数吗？

当然，这样的数字可能有很多，请写出其中最大的一个。

注意：答案是个5位数，不要填写任何多余的内容。



"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n == 2:
        return True
    if n & 0x1 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


for i in range(99999, 10000 - 1, -1):
    f = True
    for j in range(4 + 1):
        x = str(i)
        x = int(x[j:] + x[:j])
        if not is_prime(x):
            f = False
            break
    if f:
        print(i)
        break
