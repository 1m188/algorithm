"""
描述
小红有一个字符串，她可以进行以下操作：
拆分。把 'w' 拆成2个 'v'，’m‘ 拆成 2个 'n'。
轴对称。把 'b' 轴对称成 'd' ，'p' 轴对称成 'q'，反之亦然。
翻转。把 'b' 翻转成'q'，把 'd' 翻转成 'p'，把' n' 翻转成 'u'，反之亦然。
经过若干次操作后，小红想知道这个字符串能不能变成回文串。
输入描述：
第一行输入一个整数
T
(
1
≤
T
≤
1
0
4
)
T(1≤T≤10
4
 ) 表示询问次数。

接下来
T
T 行，每行输入一个字符串表示询问。

所有字符串长度之和不超过
1
0
5
10
5
  。
输出描述：
输出
T
T 行，每行输出 "YES" 或 "NO" 表示是否可以变成回文串。
示例1
输入：
5
wovv
bod
pdd
moom
lalalai
复制
输出：
YES
YES
YES
YES
NO
复制
说明：
第一个字符串可以变成：vvovv（将第一个w拆成两个v）
第二个字符串可以变成：bob、dod、pop或qoq
第三个字符串可以变成：bdb
第四个字符串本来就是回文的，不用进行操作
第五个字符串不可以变成回文串
"""


def judge(li: list[str]) -> bool:
    left, right = 0, len(li) - 1
    while left < right:
        if li[left] != li[right] and not (
            (li[left] in ["b", "d", "p", "q"] and li[right] in ["b", "d", "p", "q"])
            or (li[left] in ["n", "u"] and li[right] in ["n", "u"])
        ):
            return False
        left += 1
        right -= 1
    return True


t = int(input().strip())
for _ in range(t):
    s = input().strip()
    li = list(s)

    index = 0
    while index < len(li):
        if li[index] == "w":
            li[index] = "v"
            li.insert(index + 1, "v")
        elif li[index] == "m":
            li[index] = "n"
            li.insert(index + 1, "n")
        index += 1

    print("YES" if judge(li) else "NO")
