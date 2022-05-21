/**
 * @file L2-001 紧急救援.cpp
 * @date 2022-05-21
 */

/*
作为一个城市的应急救援队伍的负责人，你有一张特殊的全国地图。在地图上显示有多个分散的城市和一些连接城市的快速道路。每个城市的救援队数量和每一条连接两个城市的快速道路长度都标在地图上。当其他城市有紧急求助电话给你的时候，你的任务是带领你的救援队尽快赶往事发地，同时，一路上召集尽可能多的救援队。

输入格式:
输入第一行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0 ~ (N−1)；M是快速道路的条数；S是出发地的城市编号；D是目的地的城市编号。

第二行给出N个正整数，其中第i个数是第i个城市的救援队的数目，数字间以空格分隔。随后的M行中，每行给出一条快速道路的信息，分别是：城市1、城市2、快速道路的长度，中间用空格分开，数字均为整数且不超过500。输入保证救援可行且最优解唯一。

输出格式:
第一行输出最短路径的条数和能够召集的最多的救援队数量。第二行输出从S到D的路径中经过的城市编号。数字间以空格分隔，输出结尾不能有多余空格。

输入样例:
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
输出样例:
2 60
0 1 3
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

/* 老题目了，注意细节，dijkstra的变种。

虽然做过一遍，但再做一次还是wa了几次才ac，还是要多注意细节啊 */

#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0xfffffff; // 无穷大，代表两路不连通

int n = 0,                 // 城市数目
    m = 0,                 // 道路数目
    s = 0,                 // 出发点
    d = 0;                 // 目的地
vector<vector<int>> graph; // 邻接矩阵图
vector<int> saver;         // 每个城市所拥有的救援队数目

/**
 * @brief 输入
 */
void input() {
    scanf("%d %d %d %d", &n, &m, &s, &d);

    graph.resize(n, vector<int>(n, INF));
    saver.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &saver[i]);

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = graph[b][a] = c;
    }
}

/**
 * @brief dijkstra最短路算法变种
 */
void dijkstra() {

    vector<bool> vset(n); // 判断哪些顶点已经计算出终点的最短路了
    vset[s] = true;

    vector<int> dist = graph[s]; // 源点到其他点的距离

    vector<int> pathn(n, 1); // 最短路数目，初始到其他所有点都有一条
    pathn[s] = 0;

    // 到i点之前（到i点的最短距离未确定的时候）能拿到的最多救援队
    // 到i点最短路确定之后的含义就是到i点（包含i点）能拿到的最多救援队
    vector<int> msaver(n, saver[s]);
    msaver[s] = 0;

    // 以该点为终点的最短路径上，该点的前一个点
    vector<int> path(n, s);
    path[s] = -1;

    while (!vset[d]) { // 当目的地为终点的最短路径未确定的时候反复求取

        // 确定当前一条最短路径的终点
        int mi = -1;
        for (int i = 0; i < n; i++)
            if (!vset[i] && (mi == -1 || dist[i] < dist[mi]))
                mi = i;

        vset[mi] = true;
        msaver[mi] += saver[mi]; // 注意此时msaver的含义变了！变为包括mi的整条最短路径上能拿到的最多救援队

        for (int i = 0; i < n; i++) {

            if (!vset[i]) {

                // 更短的路
                if (dist[i] > dist[mi] + graph[mi][i]) {

                    dist[i] = dist[mi] + graph[mi][i]; // 更新距离
                    pathn[i] = pathn[mi];              // 换路
                    msaver[i] = msaver[mi];            // 换路
                    path[i] = mi;                      // 换路

                    // 距离相同
                } else if (dist[i] == dist[mi] + graph[mi][i]) {

                    pathn[i] += pathn[mi];        // 多了几条路径
                    if (msaver[mi] > msaver[i]) { // 如果能够拿到更多的救援队。注意这里msaver[mi]，因为之前mi已经确定了，这里的意思就是包含mi在内的最多的救援队了
                        msaver[i] = msaver[mi];
                        path[i] = mi;
                    }
                }
            }
        }
    }

    // 输出最短路条数和最多救援队数目
    printf("%d %d\n", pathn[d], msaver[d]);

    // 输出最短路径
    printf("%d", s);
    vector<int> st;
    for (int i = d; i != s; i = path[i])
        st.push_back(i);
    for (int i = st.size() - 1; i >= 0; i--)
        printf(" %d", st[i]);
}

int main() {
    input();
    dijkstra();
    return 0;
}