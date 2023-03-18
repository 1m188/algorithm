'''
稀疏向量
'''

n, a, b = map(int, input().split())
u, v = [], []
for _ in range(a):
    index, value = map(int, input().split())
    u.append((index, value))
for _ in range(b):
    index, value = map(int, input().split())
    v.append((index, value))

res = 0
ui, vi = 0, 0
while ui < a and vi < b:
    if u[ui][0] == v[vi][0]:
        res += u[ui][1] * v[vi][1]
        ui += 1
        vi += 1
    elif u[ui][0] > v[vi][0]:
        vi += 1
    else:
        ui += 1

print(res)
