/**
 * @file 7-32 哥尼斯堡的“七桥问题”.cpp
 * @date 2022-05-12
 */

/*
哥尼斯堡是位于普累格河上的一座城市，它包含两个岛屿及连接它们的七座桥，如下图所示。



可否走过这样的七座桥，而且每桥只走过一次？
瑞士数学家欧拉(Leonhard Euler，1707—1783)最终解决了这个问题，并由此创立了拓扑学。

这个问题如今可以描述为判断欧拉回路是否存在的问题。
欧拉回路是指不令笔离开纸面，可画过图中每条边仅一次，且可以回到起点的一条回路。
现给定一个无向图，问是否存在欧拉回路？

输入格式:
输入第一行给出两个正整数，分别是节点数N (1≤N≤1000)和边数M；
随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（节点从1到N编号）。

输出格式:
若欧拉回路存在则输出1，否则输出0。

输入样例1:
6 10
1 2
2 3
3 1
4 5
5 6
6 4
1 4
1 6
3 4
3 6

输出样例1:
1

输入样例2:
5 8
1 2
1 3
2 3
2 4
2 5
5 3
5 4
3 4

输出样例2:
0

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 判定欧拉回路是否存在

1. 连通
2. 对于无向图，每个节点的度都要是偶数；对于有向图，每个节点的入度==出度 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N = 0,                  // 节点数
    M = 0;                  // 边数
vector<vector<bool>> graph; // 邻接矩阵图

/**
 * @brief 处理输入，并且判断每个节点的度是否是偶数
 * @return true 是
 * @return false 否
 */
bool input() {
    cin >> N >> M;

    vector<int> degree(N + 1);
    graph.resize(N + 1, vector<bool>(N + 1));
    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true; // 添加边
        degree[a]++, degree[b]++;         // 添加度
    }

    // 判断每个节点的度是否是偶数
    for (int i = 1; i <= N; i++)
        if (degree[i] % 2)
            return false;
    return true;
}

/**
 * @brief 广度优先搜索判断是否连通
 * @return true 是
 * @return false 否
 */
bool bfs() {
    vector<bool> flags(N + 1);

    queue<int> que({1});
    flags[1] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 1; i <= N; i++) {
            if (graph[v][i] && !flags[i]) {
                flags[i] = true;
                que.push(i);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        if (!flags[i])
            return false;
    return true;
}

int main() {
    cout << (input() && bfs());
    return 0;
}