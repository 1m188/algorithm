'''
线性分类器
'''

n, m = map(int, input().split())
A, B = [], []
for _ in range(n):
    x, y, ty = input().split()
    x, y = int(x), int(y)
    if ty == 'A': A.append((x, y))
    else: B.append((x, y))


def judge(theta_0: int, theta_1: int, theta_2: int) -> bool:
    global A, B
    sign_A = 0
    for x, y in A:
        z = theta_0 + theta_1 * x + theta_2 * y
        if sign_A == 0: sign_A = 1 if z > 0 else -1
        else:
            sign_z = 1 if z > 0 else -1
            if sign_z != sign_A: return False
    for x, y in B:
        z = theta_0 + theta_1 * x + theta_2 * y
        sign_z = 1 if z > 0 else -1
        if sign_z == sign_A: return False
    return True


for _ in range(m):
    theta_0, theta_1, theta_2 = map(int, input().split())
    print('Yes' if judge(theta_0, theta_1, theta_2) else 'No')
