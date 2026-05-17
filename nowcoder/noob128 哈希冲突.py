"""
描述
在密码学中，哈希碰撞是指找到两个不同的输入，使它们经过同一个哈希函数处理后得到相同的输出。

在代码模板中给定了哈希函数
H
H，其计算过程如下：
∙
∙ 接收输入字符串
e
n
c
enc，先与给定密钥
k
e
y
key 右拼接，得到字符串
k
e
y
+
e
n
c
key+enc；
∙
∙ 对拼接后的字符串计算 SHA256 哈希值；
∙
∙ 取 SHA256 哈希值的前
∣
e
n
c
∣
∣enc∣ 个字符作为输出结果，其中
∣
e
n
c
∣
∣enc∣ 是
e
n
c
enc 的长度。

给定密钥
k
e
y
key （
1
≦
∣
k
e
y
∣
≦
10
1≦∣key∣≦10）和目标长度
L
L（
1
≦
L
≦
5
1≦L≦5）（作为全局变量而不是参数提供，你可以直接使用这两个变量名来获取对应的值），请找到两个不同的由小写字母组成的字符串
s
1
s
1
​
  和
s
2
s
2
​
 ，它们的长度均为
L
L 且满足

H
(
s
1
)
=
H
(
s
2
)
H(s
1
​
 )=H(s
2
​
 )

请将这两个字符串
s
1
s
1
​
  和
s
2
s
2
​
  组成值对作为函数的返回值。如果有多种可能的字符串值对，你可以输出任意一个符合题意的值对。
输入描述：
输入数据仅用于主函数获取数据后调用你实现的函数，你其实可以不用管。

第一行输入一个整数
L
L（
1
≦
L
≦
5
1≦L≦5），表示待构造字符串的长度。

第二行输入一个由小写字母组成的字符串
k
e
y
key，长度满足
1
≦
∣
k
e
y
∣
≦
10
1≦∣key∣≦10。
输出描述：

输出数据仅用于主函数获取返回值后于评测机交互，你其实可以不用管。

输出两个由小写字母组成的字符串
s
1
s
1
​
  和
s
2
s
2
​
 ，长度均为
L
L 且
s
1
≠
s
2
s
1
​


​
 =s
2
​
 ，它们满足
H
(
s
1
)
=
H
(
s
2
)
H(s
1
​
 )=H(s
2
​
 )，中间用一个空格分隔。
示例1
输入：
2
a
复制
输出：
mq ap
复制
备注：

"""

import hashlib
from typing import Tuple
import random


def sha256(text: str) -> str:
    return hashlib.sha256(text.encode()).hexdigest()


enc_len: int = 0
enc_key: str = ""


def H(s: str) -> str:
    combined = enc_key + s
    return sha256(combined)[:enc_len]


# 暴力随机搜索，撞库
def solve() -> Tuple[str, str]:
    # 在此处补全代码

    # 随机生成一个固定长度字符串
    def generate_string(length: int) -> str:
        return "".join(random.choices("abcdefghijklmnopqrstuvwxyz", k=length))

    di: dict[str, str] = {}

    while True:
        s = generate_string(enc_len)
        hash_s = H(s)
        if hash_s not in di:
            di[hash_s] = s
        elif di[hash_s] != s:
            return di[hash_s], s


def main():
    global enc_len, enc_key
    enc_len = int(input())
    enc_key = input()

    result = solve()
    print(f"{result[0]} {result[1]}")


if __name__ == "__main__":
    main()
