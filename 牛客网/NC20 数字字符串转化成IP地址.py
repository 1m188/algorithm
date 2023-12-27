'''

描述
现在有一个只包含数字的字符串，将该字符串转化成IP地址的形式，返回所有可能的情况。
例如：
给出的字符串为"25525522135",
返回["255.255.22.135", "255.255.221.35"]. (顺序没有关系)

数据范围：字符串长度 
0
≤
�
≤
12
0≤n≤12
要求：空间复杂度 
�
(
�
!
)
O(n!),时间复杂度 
�
(
�
!
)
O(n!)

注意：ip地址是由四段数字组成的数字序列，格式如 "x.x.x.x"，其中 x 的范围应当是 [0,255]。

示例1
输入：
"25525522135"
复制
返回值：
["255.255.22.135","255.255.221.35"]
复制
示例2
输入：
"1111"
复制
返回值：
["1.1.1.1"]
复制
示例3
输入：
"000256"
复制
返回值：
[]

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @return string字符串一维数组
#
class Solution:

    def restoreIpAddresses(self, s: str) -> List[str]:
        # write code here

        def judge(s: str) -> bool:
            n = len(s)
            if not 0 < n <= 3: return False
            x = int(s)
            if x == 0 and n > 1: return False
            if x != 0 and s[0] == '0': return False
            if not 0 <= x <= 255: return False
            return True

        res = set()

        def dfs(s: str = s, li: list[str] = []):
            if len(li) == 4:
                if s: return
                for i in li:
                    if not judge(i): return
                res.add('.'.join(li))
                return

            n = len(s)
            if n == 0: return

            for i in range(1, 3 + 1):
                sa, sb = s[:i], s[i:]
                li.append(sa)
                dfs(sb, li)
                li.pop()

        dfs()
        return list(res)
