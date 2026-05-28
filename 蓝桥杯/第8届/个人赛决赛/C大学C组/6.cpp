/*

标题：合根植物

w星球的一个种植园，被分成 m * n 个小格子（东西方向m行，南北方向n列）。每个格子里种了一株合根植物。
这种植物有个特点，它的根可能会沿着南北或东西方向伸展，从而与另一个格子的植物合成为一体。

如果我们告诉你哪些小格子间出现了连根现象，你能说出这个园中一共有多少株合根植物吗？

输入格式：
第一行，两个整数m，n，用空格分开，表示格子的行数、列数（1<m,n<1000）。
接下来一行，一个整数k，表示下面还有k行数据(0<k<100000)
接下来k行，第行两个整数a，b，表示编号为a的小格子和编号为b的小格子合根了。

格子的编号一行一行，从上到下，从左到右编号。
比如：5 * 4 的小格子，编号：
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
17 18 19 20

样例输入：
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17


样例输出：
5

其合根情况参考图[p1.png]

1   2  -  3   4
|             |
5   6     7 - 8
|
9 - 10 - 11 - 12
|   |         |
13 14    15  16
|  |     |
17-18   19 - 20

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <iostream>
#include <vector>

using namespace std;

// 并查集
class DSU {
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    int total = m * n;
    DSU dsu(total);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    // 统计不同根的数量
    int ans = 0;
    for (int i = 1; i <= total; i++) {
        if (dsu.find(i) == i) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
