'''
描述
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

所有的IP地址划分为 A,B,C,D,E五类

A类地址从1.0.0.0到126.255.255.255;

B类地址从128.0.0.0到191.255.255.255;

C类地址从192.0.0.0到223.255.255.255;

D类地址从224.0.0.0到239.255.255.255；

E类地址从240.0.0.0到255.255.255.255


私网IP范围是：

从10.0.0.0到10.255.255.255

从172.16.0.0到172.31.255.255

从192.168.0.0到192.168.255.255


子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
（注意二进制下全是1或者全是0均为非法子网掩码）

注意：
1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
2. 私有IP地址和A,B,C,D,E类地址是不冲突的

输入描述：
多行字符串。每行一个IP地址和掩码，用~隔开。

请参考帖子https://www.nowcoder.com/discuss/276处理循环输入的问题。
输出描述：
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。

示例1
输入：
10.70.44.68~255.254.255.0
1.0.0.1~255.0.0.0
192.168.0.2~255.255.255.0
19..0.~255.255.255.0
复制
输出：
1 0 1 0 0 2 1
复制
说明：
10.70.44.68~255.254.255.0的子网掩码非法，19..0.~255.255.255.0的IP地址非法，所以错误IP地址或错误掩码的计数为2；
1.0.0.1~255.0.0.0是无误的A类地址；
192.168.0.2~255.255.255.0是无误的C类地址且是私有IP；
所以最终的结果为1 0 1 0 0 2 1        
示例2
输入：
0.201.56.50~255.255.111.255
127.201.56.50~255.255.111.255
复制
输出：
0 0 0 0 0 0 0
复制
说明：
类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略       
'''

import sys


def isIPLegal(ip: str) -> bool:
    '''
    判断ip是否合法
    '''
    ipli = ip.split('.')
    if len(ipli) != 4: return False
    if '' in ipli: return False
    for i in ipli:
        i = int(i)
        if not (i >= 0 and i <= 255): return False
    return True


def isMaskLegal(mask: str) -> bool:
    '''
    判断掩码是否合法
    '''
    if not isIPLegal(mask): return False
    maskli = mask.split('.')
    mask_bin = ''
    for i in maskli:
        x = bin(int(i))[2:]
        while len(x) < 8:  # 这里很重要！！！注意每小节的二进制要补足8位，其最大值到255
            x = '0' + x
        mask_bin += x
    if mask_bin[0] != '1' or mask_bin[-1] != '0': return False  # 全1或全0非法
    return '01' not in mask_bin  # 只需查找 01 是否在序列之中即可


ipClasses = [[1 * 255**3, 126 * 255**3 + 255 * 255**2 + 255 * 255 + 255],\
             [128 * 255**3, 191 * 255**3 + 255 * 255**2 + 255 * 255 + 255],\
             [192 * 255**3, 223 * 255**3 + 255 * 255**2 + 255 * 255 + 255],\
             [224 * 255**3, 239 * 255**3 + 255 * 255**2 + 255 * 255 + 255],\
             [240 * 255**3, 255 * 255**3 + 255 * 255**2 + 255 * 255 + 255]]

pIPClasses = [[10 * 255**3, 10 * 255**3 + 255 * 255**2 + 255 * 255 + 255],\
              [172 * 255**3 + 16 * 255**2, 172 * 255**3 + 31 * 255**2 + 255 * 255 + 255],\
              [192 * 255**3 + 168 * 255**2, 192 * 255**3 + 168 * 255**2 + 255 * 255 + 255]]


def classifyIP(ip: str) -> int:
    '''
    ip分类
    '''
    ipn = 0
    for i, v in enumerate(ip.split('.')):
        ipn += int(v) * 255**(4 - i - 1)
    for i, [a, b] in enumerate(ipClasses):
        if ipn >= a and ipn <= b: break
    return i


def isIPPrivate(ip: str) -> bool:
    '''
    ip是否私有
    '''
    ipn = 0
    for i, v in enumerate(ip.split('.')):
        ipn += int(v) * 255**(4 - i - 1)
    for a, b in pIPClasses:
        if ipn >= a and ipn <= b: return True
    return False


res = [0 for _ in range(7)]

for line in sys.stdin:
    line = line.strip()
    if not line: break  # 注意跳出循环的条件

    ip, mask = line.split('~')

    # 两种忽略条件
    if ip.split('.')[0] in ['0', '127']: continue
    if not isMaskLegal(mask) or not isIPLegal(ip):
        res[5] += 1
        continue

    classidx = classifyIP(ip)
    res[classidx] += 1
    if isIPPrivate(ip):
        res[-1] += 1

print(' '.join(map(str, res)))
