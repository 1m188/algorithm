'''
输入两个非负 10 进制整数 A 和 B (≤2 
30
 −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
鸣谢用户谢浩然补充数据！

代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
'''


def jzzh(x: int, d: int) -> str:
    if d == 2: return bin(x)[2:]
    elif d == 8: return oct(x)[2:]
    elif x < d: return str(x)
    res = []
    while x:
        res.insert(0, str(x % d))
        x //= d
    return ''.join(res)


a, b, d = map(int, input().split())
c = int(a) + int(b)
print(jzzh(c, d))
