/**
 * @file ZT18 【模板】静态区间和（前缀和）.cpp
 * @date 2024-12-04
 */

/*
描述
对于给定的长度为
n
n 的数组
{
a
1
,
a
2
,
…
,
a
n
}
{a
1
​
 ,a
2
​
 ,…,a
n
​
 } ，你需要构建一个能够维护区间和信息的数据结构，使得其能支持：
∙

∙ 区间和查询：输出
[
l
,
r
]
[l,r] 这个区间中的元素之和，即
∑
i
=
l
r
a
i
∑
i=l
r
​
 a
i
​
  。
输入描述：
第一行输入两个整数
n
,
q
(
1
≦
n
,
q
≦
1
0
6
)
n,q(1≦n,q≦10
6
 ) 代表数组中的元素数量、操作次数。
第二行输入
n
n 个整数
a
1
,
a
2
,
…
,
a
n
(
−
1
0
9
≦
a
i
≦
1
0
9
)
a
1
​
 ,a
2
​
 ,…,a
n
​
 (−10
9
 ≦a
i
​
 ≦10
9
 ) 代表初始数组。
此后
q
q 行，每行输入两个整数
l
,
r
(
1
≦
l
≦
r
≦
n
)
l,r(1≦l≦r≦n) 代表区间和查询。
输出描述：
对于每一次询问，输出一行一个整数代表区间和。
示例1
输入：
3 2
1 2 4
1 2
2 3
复制
输出：
3
6
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, q = 0;
    cin >> n >> q;

    vector<int64_t> prefixSum(n);
    cin >> prefixSum[0];
    for (int i = 1; i < n; i++) {
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i - 1];
    }

    while (q--) {
        int l = 0, r = 0;
        cin >> l >> r;
        l--, r--;
        if (l == 0)
            cout << prefixSum[r] << '\n';
        else
            cout << prefixSum[r] - prefixSum[l - 1] << '\n';
    }

    return 0;
}
