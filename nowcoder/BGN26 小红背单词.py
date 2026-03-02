"""
描述
小红每天都要背单词，然后她会把每天记住了多少单词记录下来，并在小红书上打卡。

当小红背单词时，如果她已经记住了
i
i个单词，且背了一个没有记住的新单词
i
+
1
i+1次，则她就会记住这个新的单词。
例如，当她按顺序背["you","thank","thank"]时，她第一次背单词"you"时她就能记住"you"。而由于她已经记住了一个单词，所以需要背两次"thank"才能记住"thank"。

现在你知道了小红背单词的顺序，请你求出小红今天记住了多少个单词。
输入描述：
第一行一个整数
n
(
1
≤
n
≤
10000
)
n(1≤n≤10000)。
接下来
n
n行，每行一个字符串，保证每个字符串长度不超过 10。
输出描述：
输出一个整数，表示她记住了多少个单词。

示例1
输入：
5
you
thank
queue
queue
thank
复制
输出：
2
复制
说明：
小红先记住了单词"you",又因为背了两次"queue",于是记住了单词"queue"。由于已经记住了两个单词，所以背两次"thank"还不能让小红记住。
"""

n = int(input())

di: dict[str, int] = {}
s: set[str] = set()

ans = 0
x = 1
for _ in range(n):
    word = input()
    if word not in di:
        di[word] = 1
    else:
        di[word] += 1
    if di[word] >= x and word not in s:
        ans += 1
        x += 1
        s.add(word)

print(ans)
