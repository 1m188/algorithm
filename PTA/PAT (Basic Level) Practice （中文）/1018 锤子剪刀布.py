'''
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10 
5
 ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
'''

n = int(input())
sheng = [0, 0]
ping = [0, 0]
fu = [0, 0]
win_gestures = [{'B': 0, 'C': 0, 'J': 0}, {'B': 0, 'C': 0, 'J': 0}]

for _ in range(n):
    a, b = input().split()
    if a == b:
        ping[0] += 1
        ping[1] += 1
    elif (a == 'C' and b == 'J') or\
         (a == 'J' and b == 'B') or\
         (a == 'B' and b == 'C'):
        sheng[0] += 1
        fu[1] += 1
        win_gestures[0][a] += 1
    else:
        sheng[1] += 1
        fu[0] += 1
        win_gestures[1][b] += 1

print(f'{sheng[0]} {ping[0]} {fu[0]}')
print(f'{sheng[1]} {ping[1]} {fu[1]}')

li = [0, 0]
for i in range(2):
    li[i] = list(win_gestures[i].items())
    li[i].sort(key=lambda x: x[1], reverse=True)
print(f'{li[0][0][0]} {li[1][0][0]}')
