'''
描述
小红定义一个字符串是双生串，当且仅当其前半部分所有字符相同，后半部分所有字符相同。
现在，小红拿到了一个字符串 
s
s ，她每次操作可以修改一个字符。小红希望你求出将其修改为双生串的最小修改次数。
输入描述：
在一行上输入一个长度为 
1
≦
l
e
n
(
s
)
≦
2
×
1
0
5
1≦len(s)≦2×10 
5
  且为偶数，仅由小写字母构成的字符串 
s
s，代表待修改的字符串。
输出描述：
输出一个整数，表示将 
s
s 修改为双生串的最小修改次数。
示例1
输入：
popipa
复制
输出：
3
复制
说明：
在这个样例中，将 
s
s 修改为 
"p
p
p
a
a
a"
"p 
p
​
  
p
​
 
​
 pp 
a
  
a
 
 a 
a
  
a
 
 aa" 是其中一个最优解。
示例2
输入：
aaaa
复制
输出：
0
复制
说明：
在这个样例中，给定的字符串已经是双生串，不需要修改。
'''

s = input().strip()
n = len(s) // 2
left = s[:n]
right = s[n:]


def count_changes(s):
    counts = [0 for _ in range(26)]
    for c in s:
        counts[ord(c) - ord('a')] += 1
    return n - max(counts)


print(count_changes(left) + count_changes(right))
