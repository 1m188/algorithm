'''
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10 
5
 )、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''


def build_link(di: dict[str, list[str, str]],
               head_addr: str) -> list[tuple[str, str]]:
    res = []
    addr = head_addr
    while addr != '-1':
        data, addr_next = di[addr]
        res.append((addr, data))
        addr = addr_next
    return res


def reverse_k(li: list[tuple[str, str]], k: int):
    left, right = 0, k - 1
    while right < len(li):
        a, b = left, right
        while a < b:
            li[a], li[b] = li[b], li[a]
            a += 1
            b -= 1
        left = right + 1
        right = left + k - 1


def out(li: list[tuple[str, str]]):
    for i in range(len(li) - 1):
        addr, data = li[i]
        print(f'{addr} {data} {li[i+1][0]}')
    addr, data = li[-1]
    print(f'{addr} {data} {-1}')


head_addr, n, k = input().split()
n = int(n)
k = int(k)

di: dict[str, list[str, str]] = {}
for _ in range(n):
    addr, data, addr_next = input().split()
    di[addr] = [data, addr_next]

li = build_link(di, head_addr)
reverse_k(li, k)
out(li)