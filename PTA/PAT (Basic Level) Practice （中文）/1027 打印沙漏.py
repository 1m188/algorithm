'''
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *
输出样例:
*****
 ***
  *
 ***
*****
2
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''


def out(n: int, ch: str):

    spn = 0
    x = n

    while x > 1:
        for _ in range(spn):
            print(' ', end='')
        for _ in range(x):
            print(ch, end='')
        print()
        x -= 2
        spn += 1

    for _ in range(spn):
        print(' ', end='')
    print(ch)
    x += 2
    spn -= 1

    while x <= n:
        for _ in range(spn):
            print(' ', end='')
        for _ in range(x):
            print(ch, end='')
        print()
        x += 2
        spn -= 1


n, ch = input().split()
n = int(n)

k = 1
n -= k
k += 2
while n >= 2 * k:
    n -= 2 * k
    k += 2
out(k - 2, ch)
print(n)