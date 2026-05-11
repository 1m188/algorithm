"""
描述
在本题中，我们使用一个全局变量双端队列
q
q 来模拟贪吃蛇的身体。队列从头到尾存放蛇身各部分的坐标，队头为蛇尾，队尾为蛇头。

系统会调用以下两个函数，你需要实现它们的逻辑：

1.

1.
​
 moveSnack 函数：moveSnack 函数接受一个方向参数
d
i
r
dir，
d
i
r
∈
{
1
,
2
,
3
,
4
}
dir∈{1,2,3,4}，分别表示上下左右移动。函数功能如下：
∙

∙将蛇头向对应方向移动一个单位长度；
∙

∙身体的其他部分依次跟随前移一格；
∙

∙如果移动后蛇头与身体其他部分重叠，则函数返回
t
r
u
e
true，表示会撞到自己，此时不执行任何移动操作；否则返回
f
a
l
s
e
false。

2.

2.
​
 eatSnack 函数：eatSnack 函数接受一个方向参数
d
i
r
dir，
d
i
r
∈
{
1
,
2
,
3
,
4
}
dir∈{1,2,3,4}，分别表示上下左右移动。函数功能如下：
∙

∙将蛇头向对应方向移动一个单位长度；
∙

∙身体的其他部分依次跟随前移一格；
∙

∙蛇尾在原方向上生长一个单位长度；
∙

∙如果移动后蛇头与身体其他部分重叠，则函数返回
t
r
u
e
true，表示会撞到自己，此时不执行任何移动操作；否则返回
f
a
l
s
e
false。
输入描述：
输入数据仅用于主函数获取数据后调用你实现的函数，你其实可以不用管。

第一行输入两个正整数
n
,
q
(
1
≦
n
,
q
≦
1
0
3
)
n,q(1≦n,q≦10
3
 )，分别表示初始蛇身长度和操作次数。

接下来
n
n 行，每行输入两个整数
x
i
,
y
i
(
−
1
0
4
≦
x
i
,
y
i
≦
1
0
4
)
x
i
​
 ,y
i
​
 (−10
4
 ≦x
i
​
 ,y
i
​
 ≦10
4
 )，表示蛇身从尾部到头部第
i
i 节的坐标。

随后
q
q 行，每行输入两个整数
o
p
,
d
i
r
(
1
≦
o
p
≦
2
;
1
≦
d
i
r
≦
4
)
op,dir(1≦op≦2;1≦dir≦4)：
∙

∙当
o
p
=
1
op=1 时，调用 moveSnack 函数；
∙

∙当
o
p
=
2
op=2 时，调用 eatSnack 函数。
输出描述：
输出数据仅用于主函数获取返回值后于评测机交互，你其实可以不用管。

对每次操作进行如下处理：
∙

∙如果会撞到自己，输出
−
1
−1 并停止程序；
∙

∙否则，输出从蛇头到蛇尾各节的坐标，每对坐标占一行。
示例1
输入：
6 5
0 -1
0 0
0 1
1 1
2 1
2 2
1 1
1 3
1 2
1 2
1 1
复制
输出：
2 3
2 2
2 1
1 1
0 1
0 0
1 3
2 3
2 2
2 1
1 1
0 1
1 2
1 3
2 3
2 2
2 1
1 1
1 1
1 2
1 3
2 3
2 2
2 1
-1
复制
说明：
我们用浅色代表蛇尾，深色代表蛇头，则贪吃蛇的移动过程如下：
∙

∙初始时，蛇的位置如下图所示：

∙

∙操作1，向上移动一步后：

∙

∙操作2，向左移动一步后：

∙

∙操作3，向下移动一步后：

∙

∙操作4，向下移动一步后：

∙

∙操作5，向上移动，导致蛇头与蛇身相撞，游戏结束。
示例2
输入：
1 5
0 0
2 1
2 4
1 2
1 3
1 4
复制
输出：
0 1
0 0
1 1
0 1
0 0
1 0
1 1
0 1
0 0
1 0
1 1
-1

"""

# 虽然不难，但是挺繁琐的，很多细节，稍不留神容易犯错

import sys
from collections import deque

snake = deque()


def moveSnake(dir: int) -> bool:
    # 实现移动逻辑

    if dir == 1:
        dx, dy = 0, 1
    elif dir == 2:
        dx, dy = 0, -1
    elif dir == 3:
        dx, dy = -1, 0
    elif dir == 4:
        dx, dy = 1, 0

    n = len(snake)
    x, y = snake[-1][0] + dx, snake[-1][1] + dy
    for i in range(n - 1, 0, -1):
        if snake[i][0] == x and snake[i][1] == y:
            return True

    snake.popleft()
    snake.append((x, y))

    return False


def eatSnake(dir: int) -> bool:
    # 实现吃果子生长逻辑

    if len(snake) > 1:
        dx, dy = -(snake[1][0] - snake[0][0]), -(snake[1][1] - snake[0][1])
    else:
        if dir == 1:
            dx, dy = 0, -1
        elif dir == 2:
            dx, dy = 0, 1
        elif dir == 3:
            dx, dy = 1, 0
        elif dir == 4:
            dx, dy = -1, 0

    if moveSnake(dir):
        return True

    snake.appendleft((snake[0][0] + dx, snake[0][1] + dy))

    return False


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it))
    q = int(next(it))
    # snake = deque()
    for _ in range(n):
        x = int(next(it))
        y = int(next(it))
        snake.append((x, y))
    for _ in range(q):
        op = int(next(it))
        dir = int(next(it))
        collision = moveSnake(dir) if op == 1 else eatSnake(dir)
        if collision:
            print(-1)
            return
        else:
            for x, y in reversed(snake):
                print(f"{x} {y}")


if __name__ == "__main__":
    main()
