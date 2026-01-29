'''
描述
按照指定规则对输入的字符串进行处理。

详细描述：

第一步：将输入的两个字符串str1和str2进行前后合并。如给定字符串 "dec" 和字符串 "fab" ， 合并后生成的字符串为 "decfab"

第二步：对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标的意思是字符在字符串中的位置。注意排序后在新串中仍需要保持原来的奇偶性。例如刚刚得到的字符串“decfab”，分别对下标为偶数的字符'd'、'c'、'a'和下标为奇数的字符'e'、'f'、'b'进行排序（生成 'a'、'c'、'd' 和 'b' 、'e' 、'f'），再依次分别放回原串中的偶数位和奇数位，新字符串变为“abcedf”

第三步：对排序后的字符串中的'0'~'9'、'A'~'F'和'a'~'f'字符，需要进行转换操作。
转换规则如下：
对以上需要进行转换的字符所代表的十六进制用二进制表示并倒序，然后再转换成对应的十六进制大写字符（注：字符 a~f 的十六进制对应十进制的10~15，大写同理）。
如字符 '4'，其二进制为 0100 ，则翻转后为 0010 ，也就是 2 。转换后的字符为 '2'。
如字符 ‘7’，其二进制为 0111 ，则翻转后为 1110 ，对应的十进制是14，转换为十六进制的大写字母为 'E'。
如字符 'C'，代表的十进制是 12 ，其二进制为 1100 ，则翻转后为 0011，也就是3。转换后的字符是 '3'。
根据这个转换规则，由第二步生成的字符串 “abcedf” 转换后会生成字符串 "5D37BF"。


数据范围：输入的字符串长度满足 1 \le n \le 100 \1≤n≤100 

输入描述：
样例输入两个字符串，用空格隔开。

输出描述：
输出转化后的结果。

示例1
输入：
dec fab
复制
输出：
5D37BF
复制
示例2
输入：
ab CD
复制
输出：
3B5D
复制
说明：
合并后为abCD，按奇数位和偶数位排序后是CDab（请注意要按ascii码进行排序，所以C在a前面，D在b前面），转换后为3B5D          
示例3
输入：
123 15
复制
输出：
88C4A
'''


def second(s: str) -> str:
    odd = []
    even = []
    for i, v in enumerate(s):
        if i % 2 == 0: even.append(v)
        else: odd.append(v)
    odd.sort()
    even.sort()
    res = []
    while True:
        if even: res.append(even.pop(0))
        else: break
        if odd: res.append(odd.pop(0))
        else: break
    return ''.join(res)


di = {
    0: '0',
    1: '1',
    2: '2',
    3: '3',
    4: '4',
    5: '5',
    6: '6',
    7: '7',
    8: '8',
    9: '9',
    10: 'A',
    11: 'B',
    12: 'C',
    13: 'D',
    14: 'E',
    15: 'F'
}


def third(s: str) -> str:
    sli = list(s)
    for i, v in enumerate(sli):
        if v.isnumeric():
            x = bin(int(v))[2:]
            while len(x) < 4:
                x = '0' + x
            x = x[::-1]
            sli[i] = di[int(x, 2)]
        elif v.isalpha():
            v = v.upper()
            if ord('A') <= ord(v) <= ord('F'):
                x = bin(ord(v) - ord('A') + 10)[2:]
                while len(x) < 4:
                    x = '0' + x
                x = x[::-1]
                sli[i] = di[int(x, 2)]
    return ''.join(sli)


s = input().replace(' ', '')
print(third(second(s)))
