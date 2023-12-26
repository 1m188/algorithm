'''

描述
对于长度为n的一个字符串A（仅包含数字，大小写英文字母），请设计一个高效算法，计算其中最长回文子串的长度。


数据范围： 
1
≤
�
≤
1000
1≤n≤1000
要求：空间复杂度 
�
(
1
)
O(1)，时间复杂度 
�
(
�
2
)
O(n 
2
 )
进阶:  空间复杂度 
�
(
�
)
O(n)，时间复杂度 
�
(
�
)
O(n)
示例1
输入：
"ababc"
复制
返回值：
3
复制
说明：
最长的回文子串为"aba"与"bab"，长度都为3
示例2
输入：
"abbba"
复制
返回值：
5
复制
示例3
输入：
"b"
复制
返回值：
1

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param A string字符串
# @return int整型
#
class Solution:

    def getLongestPalindrome(self, A: str) -> int:
        # write code here

        n = len(A)
        N = 2 * n + 1

        li = []
        for c in A:
            li.append('#')
            li.append(c)
        li.append('#')

        p = [0 for _ in range(N)]
        r = 0
        c = 0

        for i in range(N):
            if i == 0:
                r = 0
                c = 0
                p[i] = 0
                continue

            p[i] = min(p[2 * c - i], r - i) if i < r else 0

            right = i + p[i] + 1
            left = i - p[i] - 1
            while left >= 0 and right < N and li[left] == li[right]:
                right += 1
                left -= 1
            p[i] = right - i - 1

            if i + p[i] > r:
                r = i + p[i]
                c = i

        m = max(p)
        idx = p.index(m)
        res = li[idx - m:idx + m + 1]
        res = [i for i in res if i != '#']
        res = ''.join(res)
        return len(res)
