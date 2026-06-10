/*

标题：发现环


小明的实验室有N台电脑，编号1~N。原本这N台电脑之间有N-1条数据链接相连，恰好构成一个树形网络。在树形网络上，任意两台电脑之间有唯一的路径相连。

不过在最近一次维护网络时，管理员误操作使得某两台电脑之间增加了一条数据链接，于是网络中出现了环路。环路上的电脑由于两两之间不再是只有一条路径，使得这些电脑上的数据传输出现了BUG。

为了恢复正常传输。小明需要找到所有在环路上的电脑，你能帮助他吗？

输入
-----
第一行包含一个整数N。
以下N行每行两个整数a和b，表示a和b之间有一条数据链接相连。

对于30%的数据，1 <= N <= 1000
对于100%的数据, 1 <= N <= 100000， 1 <= a, b <= N

输入保证合法。

输出
----
按从小到大的顺序输出在环路上的电脑的编号，中间由一个空格分隔。


样例输入：
5
1 2
3 1
2 4
2 5
5 3

样例输出：
1 2 3 5


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 邻接表存储图
    vector<vector<int>> g(n + 1);
    // 记录每个节点的度数
    vector<int> degree(n + 1, 0);

    // 读入 N 条边
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    // 标记节点是否已被移出网络（被剪枝）
    vector<bool> removed(n + 1, false);

    // 队列用于存储待剪枝的叶节点（度数为 1 的节点）
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    // 拓扑剪枝：反复移除度数为 1 的节点，直到只剩下环上的节点
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        removed[u] = true;

        // 遍历 u 的所有邻接节点
        for (int v : g[u]) {
            if (!removed[v]) {
                degree[v]--;
                // 若邻接节点度数降为 1，则成为新的叶节点
                if (degree[v] == 1) {
                    q.push(v);
                }
            }
        }
    }

    // 按编号从小到大输出未被移除的节点，即环上的所有电脑
    bool first = true;
    for (int i = 1; i <= n; ++i) {
        if (!removed[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
