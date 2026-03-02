"""
描述
小苯是“小红书app”的一名博主，这天他想要给自己的“铁粉”送一些礼物。

他有
n
n 名粉丝，编号从
1
1 到
n
n，但他只能选择其中
k
k 名送礼物，他决定选择其中对他支持力度最大的前
k
k 名粉丝。
（如果两名支持力度相同，则优先选择收藏数更多的，如果都一样，则优先选择编号更小的（因为这意味着他关注小苯的时间更早））

具体的：每名粉丝如果每给小苯点一次赞，则他对小苯就增加了
1
1 点支持力度，如果他每收藏小苯的一篇文章，则他对小苯增加
2
2 点支持力度。

现在小苯想知道，他应该选择哪
k
k 名粉丝送出礼物，请你帮帮他吧。
输入描述：
输入包含
n
+
1
n+1行。
第一行两个正整数
n
,
k

(
1
≤
k
≤
n
≤
1
0
5
)
n,k (1≤k≤n≤10
5
 )，分别表示对小苯有过支持的粉丝个数，以及小苯选择送礼的粉丝个数。
接下来
n
n 行，每行两个整数
x
i
,
y
i

(
0
≤
x
i
,
y
i
≤
1
0
5
)
x
i
​
 ,y
i
​
  (0≤x
i
​
 ,y
i
​
 ≤10
5
 )，表示第
i
i 位粉丝给小苯点过
x
x 次赞，收藏过
y
y 个小苯的文章。
输出描述：
输出包含一行
k
k 个正整数，表示小苯选择出送礼物的粉丝们的编号。（按照升序输出）
示例1
输入：
4 2
1 2
2 1
3 0
1 3
复制
输出：
1 4
"""

from functools import total_ordering


@total_ordering
class Fan:
    def __init__(self, number: int):
        self.number = number
        self.zan = 0
        self.shoucang = 0

    def __hash__(self) -> int:
        return hash((self.number,))

    def __eq__(self, other: "Fan") -> bool:
        return self.number == other.number

    def __lt__(self, other: "Fan") -> bool:
        x1 = self.zan + self.shoucang * 2
        x2 = other.zan + other.shoucang * 2
        if x1 != x2:
            return x1 < x2

        if self.shoucang != other.shoucang:
            return self.shoucang < other.shoucang

        return self.number > other.number


def adjust(heap: list, start: int, end: int) -> None:
    while True:
        index = start
        left = start * 2 + 1
        right = start * 2 + 2
        if left <= end and heap[left] < heap[index]:
            index = left
        if right <= end and heap[right] < heap[index]:
            index = right
        if index == start:
            break
        heap[start], heap[index] = heap[index], heap[start]
        start = index


def build_heap(vec: list) -> None:
    n = len(vec)
    for i in range((n - 1 - 1) // 2, -1, -1):
        adjust(vec, i, n - 1)


n, k = map(int, input().split())
fans = []
for i in range(1, n + 1):
    x, y = map(int, input().split())
    fans.append(Fan(i))
    fans[-1].zan = x
    fans[-1].shoucang = y

heap = fans[:k]
build_heap(heap)
for i in range(k, n):
    if fans[i] > heap[0]:
        heap[0] = fans[i]
        adjust(heap, 0, k - 1)

print(" ".join(map(str, [x.number for x in sorted(heap, key=lambda x: x.number)])))
