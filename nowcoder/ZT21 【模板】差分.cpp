/**
 * @file ZT21 【模板】差分.cpp
 * @date 2024-12-05
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
 } ，我们有
m
m 次修改操作，每一次操作给出三个参数
l
,
r
,
k
l,r,k ，代表将数组中的
a
l
,
a
l
+
1
,
…
,
a
r
a
l
​
 ,a
l+1
​
 ,…,a
r
​
  都加上
k
k 。
请你直接输出全部操作完成后的数组。
输入描述：
第一行输入两个整数
n
,
m
(
1
≦
n
,
m
≦
1
0
5
)
n,m(1≦n,m≦10
5
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
m
m 行，每行输入三个整数
l
,
r
,
k
(
1
≦
l
≦
r
≦
n
;

−
1
0
9
≦
k
≦
1
0
9
)
l,r,k(1≦l≦r≦n; −10
9
 ≦k≦10
9
 ) 代表一次操作。
输出描述：
在一行上输出
n
n 个整数，代表全部操作完成后的数组。
示例1
输入：
3 2
1 2 3
1 2 4
3 3 -2
复制
输出：
5 6 1
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0, m = 0;
    cin >> n >> m;

    vector<int64_t> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int64_t> diff(n);

    while (m--) {
        int l = 0, r = 0;
        int64_t k = 0;
        cin >> l >> r >> k;
        l--, r--;
        diff[l] += k;
        if (r + 1 < n) diff[r + 1] -= k;
    }

    int64_t x = 0;
    for (int i = 0; i < n; i++) {
        x += diff[i];
        arr[i] += x;
    }

    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << arr[i];

    return 0;
}
