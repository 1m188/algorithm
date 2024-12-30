'''
描述
牛客项目发布项目版本时会有版本号，比如1.02.11，2.14.4等等
现在给你2个版本号version1和version2，请你比较他们的大小
版本号是由修订号组成，修订号与修订号之间由一个"."连接。1个修订号可能有多位数字组成，修订号可能包含前导0，且是合法的。例如，1.02.11，0.1，0.2都是合法的版本号
每个版本号至少包含1个修订号。
修订号从左到右编号，下标从0开始，最左边的修订号下标为0，下一个修订号下标为1，以此类推。

比较规则：
一. 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较忽略任何前导零后的整数值。比如"0.1"和"0.01"的版本号是相等的
二. 如果版本号没有指定某个下标处的修订号，则该修订号视为0。例如，"1.1"的版本号小于"1.1.1"。因为"1.1"的版本号相当于"1.1.0"，第3位修订号的下标为0，小于1
三.  version1 > version2 返回1，如果 version1 < version2 返回-1，不然返回0.

数据范围：
1
<
=
v
e
r
s
i
o
n
1.
l
e
n
g
t
h
,
v
e
r
s
i
o
n
2.
l
e
n
g
t
h
<
=
1000
1<=version1.length,version2.length<=1000
version1 和 version2 的修订号不会超过int的表达范围，即不超过 32 位整数 的范围

进阶： 空间复杂度 
O
(
1
)
O(1) ， 时间复杂度 
O
(
n
)
O(n)
示例1
输入：
"1.1","2.1"
复制
返回值：
-1
复制
说明：
version1 中下标为 0 的修订号是 "1"，version2 中下标为 0 的修订号是 "2" 。1 < 2，所以 version1 < version2，返回-1
          
示例2
输入：
"1.1","1.01"
复制
返回值：
0
复制
说明：
version2忽略前导0，为"1.1"，和version相同，返回0          
示例3
输入：
"1.1","1.1.1"
复制
返回值：
-1
复制
说明：
"1.1"的版本号小于"1.1.1"。因为"1.1"的版本号相当于"1.1.0"，第3位修订号的下标为0，小于1，所以version1 < version2，返回-1          
示例4
输入：
"2.0.1","2"
复制
返回值：
1
复制
说明：
version1的下标2>version2的下标2，返回1          
示例5
输入：
"0.226","0.36"
复制
返回值：
1
复制
说明：
226>36，version1的下标2>version2的下标2，返回1   
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 比较版本号
# @param version1 string字符串
# @param version2 string字符串
# @return int整型
#
class Solution:

    def compare(self, version1: str, version2: str) -> int:
        # write code here

        v1 = list(map(lambda x: int(x), version1.split('.')))
        v2 = list(map(lambda x: int(x), version2.split('.')))

        length = max(len(v1), len(v2))
        while len(v1) < length:
            v1.append(0)
        while len(v2) < length:
            v2.append(0)

        for i in range(length):
            if v1[i] > v2[i]: return 1
            elif v1[i] < v2[i]: return -1
        return 0
