"""
描述
小红和小紫手中有一个正整数
x
x。她们轮流进行如下操作：
1.

1.
​
  选择
x
x 的一个素因子
k
(
k
>
1
)
k(k>1)；
2.

2.
​
  将
x
x 替换为
x
k
k
x
​
 。
小红先手；若某位玩家无法进行操作，则她立即失败。两人都足够聪明，请你判断每局游戏的最终赢家。游戏共进行
t
t 局，每局的初始整数可能不同。

【名词解释】
∙

∙素因子：若正整数
k
k 是质数，且
k
k 能整除正整数
x
x，则称
k
k 为
x
x 的素因子。
输入描述：
第一行输入一个整数
t
(
1
≦
t
≦
10
)
t(1≦t≦10)，表示游戏的局数。
此后
t
t 行，每行输入一个整数
x
(
1
≦
x
≦
1
0
9
)
x(1≦x≦10
9
 )，表示该局游戏的初始整数。
输出描述：
对于每局游戏，在一行上输出一个字符串：
∙

∙若小红最终获胜，输出
"kou"
"kou"；
∙

∙若小紫最终获胜，输出
"yukari"
"yukari"。
大小写需与上述格式完全一致。
示例1
输入：
2
5
12
复制
输出：
kou
kou
复制
说明：
在此样例中，共有
2
2 局游戏：
∙

∙第
1
1 局：
x
=
5
x=5，唯一的素因子为
5
5。小红选择
k
=
5
k=5，得到
x
=
1
x=1；此时小紫无法继续操作，小红获胜；
∙

∙第
2
2 局：
x
=
12
=
2
2
×
3
x=12=2
2
 ×3，一次可能的最优操作序列为
{
12
→
6
→
3
→
1
}
{12→6→3→1}，共进行
3
3 次操作（奇数次），因此先手的小红获胜。
示例2
输入：
3
1
4
30
复制
输出：
yukari
yukari
kou

"""


def get_primes(x: int) -> list[int]:
    res = []
    f = True
    while f:
        f = False
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0:
                f = True
                res.append(i)
                x //= i
                break
    res.append(x)
    return res


t = int(input())
for _ in range(t):
    x = int(input())
    if x == 1:
        print("yukari")
    else:
        primes = get_primes(x)
        n = len(primes)
        print("yukari" if n & 0x1 == 0 else "kou")
