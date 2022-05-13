/**
 * @file 7-36 社交网络图中结点的“重要性”计算.cpp
 * @date 2022-05-13
 */

/*
在社交网络中，个人或单位（结点）之间通过某些关系（边）联系起来。
他们受到这些关系的影响，这种影响可以理解为网络中相互连接的结点之间蔓延的一种相互作用，
可以增强也可以减弱。而结点根据其所处的位置不同，其在网络中体现的重要性也不尽相同。

“紧密度中心性”是用来衡量一个结点到达其它结点的“快慢”的指标，
即一个有较高中心性的结点比有较低中心性的结点能够更快地（平均意义下）到达网络中的其它结点，
因而在该网络的传播过程中有更重要的价值。在有N个结点的网络中，结点v 
i
​
 的“紧密度中心性”Cc(v 
i
​
 )数学上定义为v 
i
​
 到其余所有结点v 
j
​
  (j

=i) 的最短距离d(v 
i
​
 ,v 
j
​
 )的平均值的倒数：

              N - 1
C_c(v_i) = ------------------------
             Σ^N_i!=j d(v_i,v_j)

对于非连通图，所有结点的紧密度中心性都是0。

给定一个无权的无向图以及其中的一组结点，计算这组结点中每个结点的紧密度中心性。

输入格式:
输入第一行给出两个正整数N和M，其中N（≤10^4）是图中结点个数，顺便假设结点从1到N编号；
M（≤10^5）是边的条数。
随后的M行中，每行给出一条边的信息，即该边连接的两个结点编号，中间用空格分隔。
最后一行给出需要计算紧密度中心性的这组结点的个数K（≤100）以及K个结点编号，用空格分隔。

输出格式:
按照Cc(i)=x.xx的格式输出K个给定结点的紧密度中心性，每个输出占一行，结果保留到小数点后2位。

输入样例:
9 14
1 2
1 3
1 4
2 3
3 4
4 5
4 6
5 6
5 7
5 8
6 7
6 8
7 8
7 9
3 3 4 9

输出样例:
Cc(3)=0.47
Cc(4)=0.62
Cc(9)=0.35

代码长度限制
16 KB

时间限制
20000 ms

内存限制
64 MB
*/

/* 相比于上一题7-35来说简单不少，主要是dijkstra最短路只需要算最短路径长即可 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0xffffff; // 无穷大，代表两点不连通

int N = 0;                 // 节点数
vector<vector<int>> graph; // 图
vector<int> node;          // 待求紧密度中心性的节点

/**
 * @brief 初始化输入
 */
void input() {
    int M = 0;
    cin >> N >> M;
    // 本来只是无权图，做成int是为了方便后面的路径比较
    graph.resize(N + 1, vector<int>(N + 1, INF));

    while (M--) {
        int a = 0, b = 0;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1; // 连通则路径长度设为1
    }

    int K = 0;
    cin >> K;
    node.resize(K);
    for (int i = 0; i < K; i++)
        cin >> node[i];
}

/**
 * @brief 广度优先遍历判定是否连通
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
        for (int i = 1; i <= N; i++)
            if (!flags[i] && graph[v][i] != INF) {
                flags[i] = true;
                que.push(i);
            }
    }

    for (int i = 1; i <= N; i++)
        if (!flags[i])
            return false;
    return true;
}

/**
 * @brief dijkstra算法求最短路径
 * @param v 源点
 * @return vector<int> 从源点到其他所有点的最短路径，因为上面初始化的时候点到自己的距离被初始化成了无穷大，这里返回来的时候源点到自己的距离也会是无穷大
 */
vector<int> dijkstra(int v) {

    vector<bool> vset(N + 1); // 已求出最短路径的目标点
    vset[v] = true;
    vector<int> dist(graph[v]); // 最短路径长

    while (true) {

        int mi = -1;
        for (int i = 1; i <= N; i++) {
            if (!vset[i] && (mi == -1 || dist[i] < dist[mi])) {
                mi = i;
            }
        }
        if (mi == -1) // 找不到当前非处理过的有最短路径的点，则说明所有点都处理完了，直接跳出
            break;

        vset[mi] = true;

        for (int i = 1; i <= N; i++) {
            if (!vset[i] && dist[i] > dist[mi] + graph[mi][i]) { // 更新距离
                dist[i] = dist[mi] + graph[mi][i];
            }
        }
    }

    return dist;
}

/**
 * @brief 根据vi点和其到其他点的最短路径长计算紧密度中心性
 * @param vi 待计算的源点
 * @param dist 最短路径长
 * @return double 紧密度中心性
 */
double Cc(int vi, const vector<int> &dist) {
    int d = 0;
    for (int i = 1; i <= N; i++) {
        if (i != vi)
            d += dist[i];
    }

    return double(N - 1) / d;
}

int main() {
    input();
    if (!bfs()) { // 先判断是否连通，不连通所有点的紧密度中心性都是0.00
        for (const auto &e : node)
            printf("Cc(%d)=0.00\n", e);
    } else {
        for (const auto &e : node) {
            vector<int> x = dijkstra(e);
            double ans = Cc(e, x);
            printf("Cc(%d)=%.2f\n", e, ans);
        }
    }
    return 0;
}