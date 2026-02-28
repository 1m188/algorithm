"""
描述
"你叉叉，唱日出，穷哈哈，唱日落.....",小哈开心地哼着小调，因此小哈是一个爱笑的人，每次笑都很有魔性，调皮地小哼记录了小哈的一次说的话，其中里面可能包含了小哈的笑声，并以为字符串来记录小哈的话。已知，小哈的笑声是字母
a
a和
h
h交替的序列，例如:
a
h
a
h
a
h
ahahah，
a
h
a
aha,
a
a,
h
h是符合笑声的合法序列。但是，
a
b
a
c
a
b
a
abacaba,
a
a
aa不符合笑声的合法序列。
通过小哼的记录，请你求出小哈笑声的最大长度。
输入描述：
输入的第一行给出小哈说话的长度
N
N。
随后一行中输入一行长度为
N
N字符串
S
S——表示小哈的话。
1
≤
N
≤
1
0
5
1≤N≤10
5

S
S仅由小写字母组成。
输出描述：
输出小哈笑声的最大长度。
示例1
输入：
7
abacaba
复制
输出：
1
复制
示例2
输入：
20
ahahahahahahahahahah
复制
输出：
20
"""

n = int(input().strip())
s = input().strip()

chs = ["a", "h"]
chi = 0
ans = 0
start = 0
while start < n:
    while start < n and s[start] != "a" and s[start] != "h":
        start += 1
    if start >= n:
        break
    chi = chs.index(s[start])

    end = start
    while end < n and s[end] == chs[chi]:
        ans = max(ans, end - start + 1)
        end += 1
        chi = 1 - chi

    start = end

print(ans)
