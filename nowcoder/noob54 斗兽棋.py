"""
描述
牛牛和牛妹正在玩一个博弈游戏。每人可以选择一个棋子：`elephant`、`tiger`、`cat` 或 `mouse`。
它们之间的胜负规则如下：
∙
∙ `elephant` 吃 `tiger`；
∙
∙ `tiger` 吃 `cat`；
∙
∙ `cat` 吃 `mouse`；
∙
∙ `mouse` 吃 `elephant`；
如果一方的棋子能够吃掉另一方的棋子，则该方获胜；否则为平局。
给定牛牛和牛妹所出的棋子，请判断比赛结果。
输入描述：
在一行输入两个以空格分隔的字符串
s
1
,
s
2
s
1
​
 ,s
2
​
 ，其中
s
1
,
s
2
∈
{
"elephant"
,
"tiger"
,
"cat"
,
"mouse"
}
s
1
​
 ,s
2
​
 ∈{"elephant","tiger","cat","mouse"}，分别代表牛牛和牛妹所出的棋子。
输出描述：
如果牛牛获胜，输出
win
win；如果牛妹获胜，输出
lose
lose；如果平局，输出
tie
tie。
示例1
输入：
tiger elephant
复制
输出：
lose
复制
说明：
牛牛出 `tiger`，牛妹出 `elephant`；大象吃老虎，牛牛落败，因此输出 `lose`。
备注：
"""

s1, s2 = input().split()
if (
    (s1 == "elephant" and s2 == "tiger")
    or (s1 == "tiger" and s2 == "cat")
    or (s1 == "cat" and s2 == "mouse")
    or (s1 == "mouse" and s2 == "elephant")
):
    print("win")
elif (
    (s2 == "elephant" and s1 == "tiger")
    or (s2 == "tiger" and s1 == "cat")
    or (s2 == "cat" and s1 == "mouse")
    or (s2 == "mouse" and s1 == "elephant")
):
    print("lose")
else:
    print("tie")
