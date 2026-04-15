"""
描述
众所周知，牛牛是一个 “1+1” 都能回答错误的小可爱，因此经常遭受旺仔哥哥的头槌惩罚。
今天，旺仔哥哥出了一场选择题测验，牛牛决定按照坊间传说来猜答案：
∙

∙三长一短选最短；
∙

∙三短一长选最长；
∙

∙参差不齐就选 C。

【名词解释】
【三长一短】三长一短 是指在四个选项长度中恰有一个选项的长度严格小于另外三个选项，且不存在四个选项长度中恰有一个选项的长度严格大于另外三个选项；
【三短一长】三短一长 是指在四个选项长度中恰有一个选项的长度严格大于另外三个选项，且不存在四个选项长度中恰有一个选项的长度严格小于另外三个选项；
【参差不齐】参差不齐 是指既不满足“三长一短”也不满足“三短一长”的情况。
输入描述：
第一行输入一个整数
T
T
(
1
≦
T
≦
500
)
(1≦T≦500)，表示题目数。
接下来共有
T
T 道题，每道题由 4 行字符串组成，分别对应选项 A、B、C、D；每个字符串长度不超过 600，由可见字符（字母、数字、符号等）组成。
输出描述：
对于每道题，输出按照上述坊间传说应选的选项字母（A、B、C 或 D），每个字母独占一行。
示例1
输入：
3
A.3.141592653589
B.2.718281828459
C.0.618033988749
D.0.577215664901532860
A.wo_shi_cuo_de
B.wo_bu_dui
C.wo_shi_dui_de
D.C_shi_dui_de
A.3.141592653589
B.2.718281828459
C.0.618033988749
D.0.577215664901
复制
输出：
D
B
C
复制
说明：
∙

∙第 1 道题中，选项长度分别为 14、14、14、18，恰有一个最长，符合“三短一长”，选最长 D；
∙

∙第 2 道题中，选项长度分别为 13、9、13、12，恰有一个最短，符合“三长一短”，选最短 B；
∙

∙第 3 道题中，四个选项长度均相同，属于“参差不齐”，选 C。
"""

import functools


@functools.total_ordering
class Option:
    def __init__(self, content: str, opt: str):
        self.content = content
        self.opt = opt

    def __eq__(self, other: "Option") -> bool:
        return len(self.content) == len(other.content)

    def __lt__(self, other: "Option") -> bool:
        return len(self.content) < len(other.content)


T = int(input())
for _ in range(T):
    A, B, C, D = input(), input(), input(), input()
    li = sorted([Option(eval(x), x) for x in ["A", "B", "C", "D"]])
    if (
        li[0] < li[1]
        and li[0] < li[2]
        and li[0] < li[3]
        and not (li[3] > li[2] and li[3] > li[1] and li[3] > li[0])
    ):
        print(li[0].opt)
    elif (
        li[3] > li[2]
        and li[3] > li[1]
        and li[3] > li[0]
        and not (li[0] < li[1] and li[0] < li[2] and li[0] < li[3])
    ):
        print(li[3].opt)
    else:
        print("C")
