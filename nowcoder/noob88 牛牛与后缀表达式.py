"""
描述
给定牛牛一个后缀表达式
s
s（
1
≤
∣
s
∣
≤
1
0
6
1≤∣s∣≤10
6
 ），计算它的结果，例如，
1
+
1
1+1 对应的后缀表达式为 \text{1#1#+}，其中 \text{#} 为参与运算的参数的结束标识符。
输入数据保证表达式
s
s 一定合法，
s
s 中只含有 ‘+’、’-‘、’*‘三种运算，分别表示加法、减法和乘法，且任意计算过程和计算结果的绝对值一定不会超过
1
0
18
10
18
 。

【名词解释】
后缀表达式：一种数学表达式表示法，其中所有运算符都位于其操作数之后，并通过从左到右扫描表达式并使用栈进行操作数和结果的管理来确定明确的运算顺序，无需括号。
示例1
输入：
"1#1#+"
复制
返回值：
2
复制
说明：
1#1#+这个后缀表达式表示的式子是1+1，结果为2
示例2
输入：
"12#3#+15#*"
复制
返回值：
225
复制
说明：
12#3#+15#*这个后缀表达式表示的式子是(12+3)*15，结果为225
示例3
输入：
"1#1#4#5#-*+1#4#*+"
复制
返回值：
4
复制
说明：

"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 给定一个后缀表达式，返回它的结果
# @param str string字符串
# @return long长整型
#
class Solution:
    def legalExp(self, s: str) -> int:
        # write code here

        stack: list[int] = []
        tmp = ""

        def calc(stack: list[int], exp: str):
            if exp == "+":
                a = stack.pop()
                b = stack.pop()
                stack.append(a + b)
            elif exp == "-":
                a = stack.pop()
                b = stack.pop()
                stack.append(b - a)
            elif exp == "*":
                a = stack.pop()
                b = stack.pop()
                stack.append(a * b)

        for c in s:
            if c.isdigit():
                tmp += c
            elif c == "#":
                stack.append(int(tmp))
                tmp = ""
            else:
                if tmp:
                    stack.append(int(tmp))
                    tmp = ""
                calc(stack, c)
                c = ""
        calc(stack, c)
        return stack[0]
