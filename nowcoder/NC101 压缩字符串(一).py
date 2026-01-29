'''
描述
利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2bc5a3。
1.如果只有一个字符，1不用写
2.字符串中只包含大小写英文字母（a至z）。

数据范围:
0<=字符串长度<=50000

要求：时间复杂度O(N）
示例1
输入：
"aabcccccaaa"
复制
返回值：
"a2bc5a3"
复制
示例2
输入：
"shopeew"
复制
返回值：
"shope2w"
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param param string字符串
# @return string字符串
#
class Solution:

    def compressString(self, param: str) -> str:
        # write code here
        li = []
        cnt = 0
        ch = None
        for c in param:
            if ch == None:
                ch = c
                cnt = 1
            elif c == ch:
                cnt += 1
            else:
                li.append(ch)
                if cnt > 1: li.append(str(cnt))
                ch = c
                cnt = 1
        if ch != None:
            li.append(ch)
            if cnt > 1: li.append(str(cnt))
        return ''.join(li)
