'''

描述
给一个加密过的字符串解码，返回解码后的字符串。

加密方法是：k[c] ，表示中括号中的 c 字符串重复 k 次，例如 3[a] 解码结果是 aaa ，保证输入字符串符合规则。不会出现类似 3a , 3[3] 这样的输入。

数据范围：输出的字符串长度满足 
1
≤
�
≤
50
 
1≤n≤50 
示例1
输入：
"3[a]"
复制
返回值：
"aaa"
复制
示例2
输入：
"abc"
复制
返回值：
"abc"
复制
示例3
输入：
"3[3[b]]"
复制
返回值：
"bbbbbbbbb"

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @return string字符串
#
class Solution:

    def decodeString(self, s: str) -> str:
        # write code here

        while True:
            i = 0
            while i < len(s) and s[i] != '[':
                i += 1
            if i >= len(s): break
            st = 1
            for j in range(i + 1, len(s)):
                if s[j] == '[': st += 1
                elif s[j] == ']': st -= 1
                if st == 0: break

            subs = self.decodeString(s[i + 1:j])
            k = ''
            for idx in range(i - 1, -1, -1):
                if not s[idx].isdigit(): break
                k = s[idx] + k
            k = int(k)
            subs = k * subs
            if idx > 0: idx += 1

            s = s[:idx] + subs + s[j + 1:]

        return s
