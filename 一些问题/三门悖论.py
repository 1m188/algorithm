'''
模拟一下三门悖论

有三扇门，其中两扇门背后没有东西，一扇门背后有汽车，
当你选中一扇门之后，主持人排除了另外两扇门中的一扇没有中奖的门，
问，你应该换门吗？


在仿真结果中，换门中奖的频率约为不换门中奖的频率的2倍，和理论分析一致，换门的中奖概率更高
'''

import random

a1 = 0  # 换门中奖的次数
a2 = 0  # 不换门中奖的次数
N = 10**5  # 每种情况模拟的次数

for n in range(N):
    print(f'\r{n+1}/{N}', end='', flush=True)

    a = random.randint(1, 3)  # 中奖的门编号
    c = random.randint(1, 3)  # 随机选一扇门

    # 揭示非选择的剩下两扇门中一扇没有中奖的门
    b = 0
    for i in range(1, 3 + 1):  # 主持人一定不知道哪扇门中奖了，为了降低节目效果，他一定会选择剩下两扇门中的没中奖的那一扇门
        if i == c: continue
        if i == a: continue
        b = i
        break

    # 获得剩下可以换的那个门 d!=c
    d = 0
    for i in range(1, 3 + 1):
        if i == c: continue
        if i == b: continue
        d = i
        break

    if d == a: a1 += 1
    else: a2 += 1

print()
print(f'换门中奖的频率: {a1/N}')
print(f'不换门中奖的频率: {a2/N}')
