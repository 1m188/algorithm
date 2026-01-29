'''
描述
编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；
同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。
同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

数据范围：字符串长度满足 
5
≤
n
≤
50
5≤n≤50
进阶：空间复杂度 
O
(
n
)
O(n)，时间复杂度 
O
(
n
)
O(n)
示例1
输入：
"172.16.254.1"
复制
返回值：
"IPv4"
复制
说明：
这是一个有效的 IPv4 地址, 所以返回 "IPv4" 
示例2
输入：
"2001:0db8:85a3:0:0:8A2E:0370:7334"
复制
返回值：
"IPv6"
复制
说明：
这是一个有效的 IPv6 地址, 所以返回 "IPv6" 
示例3
输入：
"256.256.256.256"
复制
返回值：
"Neither"
复制
说明：
这个地址既不是 IPv4 也不是 IPv6 地址 
备注：
ip地址的类型，可能为
IPv4,   IPv6,   Neither
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 验证IP地址
# @param IP string字符串 一个IP地址字符串
# @return string字符串
#
class Solution:

    def solve(self, IP: str) -> str:
        # write code here

        def isIPv4(IP: str) -> bool:
            li = IP.split('.')
            if len(li) != 4: return False
            for i in li:
                try:
                    x = int(i)
                except:
                    return False
                if not 0 <= x <= 255: return False
                if i[0] == '0': return False
            return True

        def isIPv6(IP: str) -> bool:
            li = IP.split(':')
            if len(li) != 8: return False
            for i in li:
                if not 1 <= len(i) <= 4: return False
                for c in i:
                    if not (ord('0') <= ord(c) <= ord('9') or \
                            ord('a') <= ord(c) <= ord('f') or \
                            ord('A') <= ord(c) <= ord('F')):
                        return False
            return True

        if isIPv4(IP): return 'IPv4'
        if isIPv6(IP): return 'IPv6'
        return 'Neither'
