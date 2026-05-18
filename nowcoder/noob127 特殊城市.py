"""
描述
Farmer John 有若干头奶牛。为了训练奶牛们的智力，他在谷仓的墙上放了一张美国地图。地图上标明了每个城市及其所在州的代码（前两位大写字母）。

奶牛们注意到，如果城市
A
A 的名称前两位字母等于城市
B
B 所在州代码，且城市
B
B 的名称前两位字母等于城市
A
A 所在州代码，并且
A
,
B
A,B 来自不同的州，则称
{
A
,
B
}
{A,B} 是一对特殊城市。

现有
N
N 座城市，请你计算共有多少对特殊城市。
输入描述：
第一行输入一个整数
N
N（
1
≦
N
≦
2
×
1
0
5
1≦N≦2×10
5
 ），表示城市数量。

接下来
N
N 行，每行输入两个字符串：城市名称
S
S（由
2
∼
10
2∼10 个大写字母组成）和所在州代码
C
C（由
2
2 个大写字母组成），用空格隔开。保证同一州内城市名称互不相同。
输出描述：
输出一个整数，表示特殊城市对的数量。
示例1
输入：
6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
复制
输出：
1
复制
说明：
MIAMI 位于州 FL，且 FLINT 的名称前两位字母为 FL；FLINT 位于州 MI，且 MIAMI 的名称前两位字母为 MI。其他城市不满足此条件，因此共有 1 对特殊城市。
示例2
输入：
2
ABCD EF
EFGH AB
复制
输出：
1
复制
说明：
ABCD 位于州 EF，且 EFGH 的名称前两位字母为 EF；EFGH 位于州 AB，且 ABCD 的名称前两位字母为 AB。因此共有 1 对特殊城市。
"""

n = int(input())

ans = 0
di: dict[str, dict[str, int]] = {}  # 嵌套哈希表

for _ in range(n):
    s, c = input().split()
    p = s[:2]
    if p not in di:
        di[p] = {c: 1}
    else:
        if c not in di[p]:
            di[p][c] = 1
        else:
            di[p][c] += 1

for prefix in di:
    for state in di[prefix]:
        cnt1 = di[prefix][state]
        if state in di and prefix in di[state]:
            cnt2 = di[state][prefix]
            if prefix != state:
                ans += cnt1 * cnt2


print(ans // 2)
