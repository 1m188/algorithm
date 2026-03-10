"""

10301是个5位的素数。它有个特点，把数字倒过来还是它本身，具有这样特征的素数，我们称之为：回文素数。

10501
10601
11311

这些都是5位的回文素数。

请你计算一下，像这样的5位数的回文素数，一共有多少个？

请填写这个表示个数的整数，注意不要写任何其它多余的内容，比如说明或解释文字，也不要列出所有的回文素数。



"""


def judge(n: int) -> bool:
    if n <= 1:
        return False
    if n == 2:
        return True
    if n & 0x1 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def rev(n: int) -> int:
    return int(str(n)[::-1])


ans = 0
for i in range(10000, 99999 + 1):
    if i == rev(i) and judge(i):
        ans += 1
print(ans)  # 93
