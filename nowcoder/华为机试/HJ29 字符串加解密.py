'''
描述
对输入的字符串进行加解密，并输出。

加密方法为：

当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；

当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；

其他字符不做变化。

解密方法为加密的逆过程。
数据范围：输入的两个字符串长度满足 1 \le n \le 1000 \1≤n≤1000  ，保证输入的字符串都是只由大小写字母或者数字组成
输入描述：
第一行输入一串要加密的密码
第二行输入一串加过密的密码

输出描述：
第一行输出加密后的字符
第二行输出解密后的字符

示例1
输入：
abcdefg
BCDEFGH
复制
输出：
BCDEFGH
abcdefg
'''


def jiami(s: str) -> str:
    sli = list(s)
    for i, v in enumerate(sli):
        if v.isalpha():
            x = ord(v) + 1
            if v.isupper():
                if x > ord('Z'): x = ord('A')
                x = chr(x).lower()
            else:
                if x > ord('z'): x = ord('a')
                x = chr(x).upper()
            sli[i] = x
        elif v.isnumeric():
            sli[i] = str((int(v) + 1) % 10)
    return ''.join(sli)


def jiemi(s: str) -> str:
    sli = list(s)
    for i, v in enumerate(sli):
        if v.isalpha():
            x = ord(v) - 1
            if v.isupper():
                if x < ord('A'): x = ord('Z')
                x = chr(x).lower()
            else:
                if x < ord('a'): x = ord('z')
                x = chr(x).upper()
            sli[i] = x
        elif v.isnumeric():
            x = int(v) - 1
            if x < 0: x = 9
            sli[i] = str(x)
    return ''.join(sli)


s1 = input()
s2 = input()

print(jiami(s1))
print(jiemi(s2))
