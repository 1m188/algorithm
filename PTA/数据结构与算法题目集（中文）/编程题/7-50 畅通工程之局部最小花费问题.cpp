/**
 * @file 7-50 畅通工程之局部最小花费问题.cpp
 * @date 2022-05-16
 */

/*
某地区经过对城镇交通状况的调查，得到现有城镇间快速道路的统计数据，并提出“畅通工程”的目标：
使整个地区任何两个城镇间都可以实现快速交通（但不一定有直接的快速道路相连，
只要互相间接通过快速路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建快速路的费用，
以及该道路是否已经修通的状态。现请你编写程序，计算出全地区畅通需要的最低成本。

输入格式:
输入的第一行给出村庄数目N (1≤N≤100)；随后的N(N−1)/2行对应村庄间道路的成本及修建状态：
每行给出4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，
以及修建状态 — 1表示已建，0表示未建。

输出格式:
输出全省畅通需要的最低成本。

输入样例:
4
1 2 1 1
1 3 4 0
1 4 1 1
2 3 3 0
2 4 2 1
3 4 5 0

输出样例:
3

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 最小生成树，prim算法（因为点比较少），将所有已经连接的边的权值都置为0，
这样求最小生成树的时候最终的权值就都是未连接的部分了，并且在比较的时候如果有
已经连接的部分参加，则肯定是已经连接的部分胜出，因为他的值是0.

注意和dijkstra最短路径算法的区别 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 0xfffffff; // 代表无连接的部分，无穷大

int N;                     // 多少个点
vector<vector<int>> graph; // 邻接矩阵图

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d) // 如果已经修好了就将其权值置为0
            c = 0;
        graph[a][b] = graph[b][a] = c;
    }
}

/**
 * @brief prim算法求最短路径
 */
void prim() {

    int cost = 0;

    vector<bool> vset(N + 1); // 已经加入最小生成树的顶点
    vset[1] = true;

    vector<int> dist = graph[1]; // 从当前最小生成树到其他所有顶点的最短距离

    while (true) {

        // 找当前最短距离
        int mi = -1;
        for (int i = 1; i <= N; i++)
            if (!vset[i] && (mi == -1 || dist[i] < dist[mi]))
                mi = i;

        // 找不到就说明都找过了跳出
        if (mi == -1)
            break;

        vset[mi] = true;  // 加入最小生成树
        cost += dist[mi]; // 注意更新cost

        for (int i = 1; i <= N; i++)
            // 这里需要注意和dijkstra最短路算法区分开来
            // dijkstra最短路算法是更新其他所有未确定顶点到
            // 源点的最短距离，而这里最小生成树是更新其他所有未加入
            // 最小生成树的顶点到最小生成树的最短距离
            if (!vset[i] && graph[mi][i] < dist[i])
                dist[i] = graph[mi][i];
    }

    cout << cost;
}

int main() {
    input();
    prim();
    return 0;
}