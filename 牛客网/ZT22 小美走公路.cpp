/**
 * @file ZT22 小美走公路.cpp
 * @date 2024-12-06
 */

/*
描述
有一个环形的公路，上面共有
n
n站，现在给定了顺时针第
i
i站到第
i
+
1
i+1站之间的距离（特殊的，也给出了第
n
n站到第 1 站的距离）。小美想沿着公路第
x
x站走到第
y
y站，她想知道最短的距离是多少？
输入描述：
第一行输入一个正整数
n
n，代表站的数量。
第二行输入
n
n个正整数
a
i
a
i
​
 ，前
n
−
1
n−1个数代表顺时针沿着公路走，
i
i站到第
i
+
1
i+1站之间的距离；最后一个正整数代表顺时针沿着公路走，第
n
n站到第 1 站的距离。·
第三行输入两个正整数
x
x和
y
y，代表小美的出发地和目的地。
1
≤
n
≤
1
0
5
1≤n≤10
5

1
≤
a
i
≤
1
0
9
1≤a
i
​
 ≤10
9

1
≤
x
,
y
≤
n
1≤x,y≤n
输出描述：
一个正整数，代表小美走的最短距离。
示例1
输入：
3
1 2 2
2 3
复制
输出：
2
复制
示例2
输入：
3
1 2 2
1 3
复制
输出：
2
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    cin >> n;

    vector<int64_t> dis(n);
    for (int i = 0; i < n; i++)
        cin >> dis[i];

    int x = 0, y = 0;
    cin >> x >> y;
    x--, y--;

    int64_t dis1 = 0, dis2 = 0;
    for (int i = x; i != y; i = (i + 1) % n)
        dis1 += dis[i];
    for (int i = x; i != y; i = (i - 1 + n) % n)
        dis2 += dis[(i - 1 + n) % n];

    cout << min(dis1, dis2);

    return 0;
}
