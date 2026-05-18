"""

形如：1/a 的分数称为单位分数。

可以把1分解为若干个互不相同的单位分数之和。
例如：
1 = 1/2 + 1/3 + 1/9 + 1/18
1 = 1/2 + 1/3 + 1/10 + 1/15
1 = 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/15 + 1/35 + 1/45 + 1/231
等等，类似这样的分解无穷无尽。

我们增加一个约束条件：最大的分母必须不超过30

请你求出分解为n项时的所有不同分解法。

数据格式要求：

输入一个整数n，表示要分解为n项（n<12）
输出分解后的单位分数项，中间用一个空格分开。
每种分解法占用一行，行间的顺序按照分母从小到大排序。

例如，
输入：
4
程序应该输出：
1/2 1/3 1/8 1/24
1/2 1/3 1/9 1/18
1/2 1/3 1/10 1/15
1/2 1/4 1/5 1/20
1/2 1/4 1/6 1/12

再例如，
输入：
5
程序应该输出：
1/2 1/3 1/12 1/21 1/28
1/2 1/4 1/6 1/21 1/28
1/2 1/4 1/7 1/14 1/28
1/2 1/4 1/8 1/12 1/24
1/2 1/4 1/9 1/12 1/18
1/2 1/4 1/10 1/12 1/15
1/2 1/5 1/6 1/12 1/20
1/3 1/4 1/5 1/6 1/20


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


"""

from math import gcd

MAX_DENOM = 30
path = []
n = 0


def can_reach(start, remain, target_num, target_den):
    # 检查从start开始的remain个最小分母的单位分数之和是否>=目标
    total = 0.0
    for i in range(remain):
        total += 1.0 / (start + i)
    return total >= target_num / target_den


def dfs(start, remain, num, den):
    if remain == 0:
        if num == 0:
            print(" ".join(f"1/{d}" for d in path))
        return

    if num <= 0:
        return

    if remain == 1:
        if num == 1 and den >= start and den <= MAX_DENOM:
            path.append(den)
            print(" ".join(f"1/{d}" for d in path))
            path.pop()
        return

    d_min = max(start, (den + num - 1) // num)
    if d_min > MAX_DENOM:
        return

    for d in range(d_min, MAX_DENOM + 1):
        if not can_reach(d, remain, num, den):
            break

        new_num = num * d - den
        new_den = den * d
        g = gcd(new_num, new_den)
        new_num //= g
        new_den //= g

        path.append(d)
        dfs(d + 1, remain - 1, new_num, new_den)
        path.pop()


def main():
    global n
    n = int(input())
    dfs(2, n, 1, 1)


if __name__ == "__main__":
    main()
