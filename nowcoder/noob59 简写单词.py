"""
描述
规定一种对于复合词的简写方式：只保留每个组成单词的首字母，并将首字母大写后再连接在一起。
例如：
∙

∙“College English Test”可简写为“CET”；
∙

∙“Computer Science”可简写为“CS”；
∙

∙“I am Bob”可简写为“IAB”。
现在输入一个由若干单词组成的复合词，请输出它的简写形式。
输入描述：
在一行中输入一个复合词，由若干单词组成。
∙

∙单词数
s
u
m
sum 满足
1
≦
s
u
m
≦
100
1≦sum≦100；
∙

∙每个单词长度
l
e
n
len 满足
1
≦
l
e
n
≦
50
1≦len≦50；
∙

∙单词之间由单个空格分隔；
∙

∙每个单词仅由大小写英文字母组成。
输出描述：
输出一个字符串，为复合词的简写形式。
简写方式为：取每个单词的首字母并将其转换为大写，然后按原单词顺序依次连接。
请不要输出多余的空格或换行。
示例1
输入：
International Collegiate Programming Contest
复制
输出：
ICPC
复制
示例2
输入：
Super mySQL
复制
输出：
SM
"""

cwords = input().split()
print("".join([word[0].upper() for word in cwords]))
