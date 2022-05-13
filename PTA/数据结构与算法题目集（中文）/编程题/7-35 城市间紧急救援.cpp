/**
 * @file 7-35 城市间紧急救援.cpp
 * @date 2022-05-12
 */

/*
作为一个城市的应急救援队伍的负责人，你有一张特殊的全国地图。
在地图上显示有多个分散的城市和一些连接城市的快速道路。
每个城市的救援队数量和每一条连接两个城市的快速道路长度都标在地图上。
当其他城市有紧急求助电话给你的时候，你的任务是带领你的救援队尽快赶往事发地，
同时，一路上召集尽可能多的救援队。

输入格式:
输入第一行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0 ~ (N−1)；
M是快速道路的条数；S是出发地的城市编号；D是目的地的城市编号。

第二行给出N个正整数，其中第i个数是第i个城市的救援队的数目，数字间以空格分隔。
随后的M行中，每行给出一条快速道路的信息，分别是：城市1、城市2、快速道路的长度，中间用空格分开，
数字均为整数且不超过500。输入保证救援可行且最优解唯一。

输出格式:
第一行输出最短路径的条数和能够召集的最多的救援队数量。第二行输出从S到D的路径中经过的城市编号。
数字间以空格分隔，输出结尾不能有多余空格。

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
400 ms

内存限制
64 MB
*/

/* 很复杂的题目，第一次接触这种题目如果不对dijkstra最短路径算法有深入的认识的话，
很容易就在各种细节上犯错，关键要明晰两点：

1. dijkstra最短路径算法中所有的内容都在求最短路径的过程中不断地变化，尤其是
中间节点，更是变来变去，所以要用数组储存中间结果，一方面是在变化的过程中
可以作为参考，另一方面可以存储所有不同的节点的变化，不要试图用一个变量存储
所有的最终结果，这些最终结果和很多中间结果都是相互依赖的。

2. 明确定义的数组比如说vec，对于vec[i] 而言，是什么意思，一般i都是节点，那么就是
说，在vec这个数组中对于i节点其索引下的值是什么意思，并且在整个求最短路径的过程中
都要严格保证这种定义得到实现。

搞了半个晚上+一整个上午，心神俱疲 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 500 + 10000; // 代表无穷大，表示两点间无连接

int N = 0,                 // 节点数目
    M = 0,                 // 边数
    S = 0,                 // 出发点（源点）
    D = 0;                 // 目的地
vector<vector<int>> graph; // 邻接矩阵图
vector<int> saver_num;     // 每个城市的救援人员数目

/**
 * @brief 初始化输入
 */
void input() {
    cin >> N >> M >> S >> D;

    graph.resize(N, vector<int>(N, INF));
    saver_num.resize(N);

    // 获取每个城市救援队数目
    for (int i = 0; i < N; i++)
        cin >> saver_num[i];

    // 获取两个城市间距离
    for (int i = 0; i < M; i++) {
        int a = 0, b = 0, len = 0;
        cin >> a >> b >> len;
        graph[a][b] = graph[b][a] = len;
    }
}

/**
 * @brief dijkstra最短路径算法（变种）
 */
void dijkstra() {

    // 用来存储已经求出到其最短路径的节点
    vector<bool> vset(N);
    vset[S] = true;

    vector<int> dist(graph[S]); // 从源点出发到各个节点的最短路长

    /* 对于path[i]而言，他的意思是到i点最短路径最后一段为 path[i] -> i ，
    通过这个方法可以很好的在求最短路径的过程中不断地更新最短路径终点
    前一个点 */
    vector<int> path(N, S); // 从源点出发到各个节点的最短路径

    /* 初始为1，代表从源点到目标节点至少有一条路径 */
    vector<int> pathn(N, 1); // 从源点出发到各个节点的最短路径数目

    /* 对于max_saver_num[i]代表从源点到i点路上能拿到最多的救援人员，包括源点和i点 */
    vector<int> max_saver_num(N, saver_num[S]); // 从源点出发到各个节点路上能带的最多救援人员
    for (int i = 0; i < N; i++)
        if (graph[S][i] != INF)
            max_saver_num[i] += saver_num[i];

    // 当以目标点为终点的路径没有求出来之前
    while (!vset[D]) {

        // 求出未求出最短路径终点的节点中当前dist距离最小者
        int mi = -1;
        for (int i = 0; i < N; i++)
            if (!vset[i] && (mi == -1 || dist[i] < dist[mi]))
                mi = i;

        // 那么他就是当前的一条最短路径的终点了
        vset[mi] = true;

        // 更新
        for (int i = 0; i < N; i++) {
            if (!vset[i]) {                                                    // 对所有没求出最短路径节点进行更新
                if (dist[i] > dist[mi] + graph[mi][i]) {                       // 如果以当前点为中转点能够更短的话
                    dist[i] = dist[mi] + graph[mi][i];                         // 更新
                    path[i] = mi;                                              // 更短的点应该成为i的最短路径上的前一个点
                    pathn[i] = pathn[mi];                                      // 要换路，从mi到i又因为graph的存在只有一条路径，所以到i的路径条数为了更短就要变成到mi的路径条数
                    max_saver_num[i] = max_saver_num[mi] + saver_num[i];       // 换了路，也要换一路上能拿到的最多的救援人员，考虑到max_saver_num的含义，mi了之后还应该+i的部分，表示终点
                } else if (dist[i] == dist[mi] + graph[mi][i]) {               // 路径相等，说明路径数目更多了
                    pathn[i] += pathn[mi];                                     // 当前到i是又pathn[i]条，另外到i有到mi的条数加上从mi到i（因为graph的存在只有一条），所以两者相加
                    if (max_saver_num[mi] + saver_num[i] > max_saver_num[i]) { // 如果能够拿到更多的救援人员，则进行换路
                        path[i] = mi;
                        max_saver_num[i] = max_saver_num[mi] + saver_num[i];
                    }
                }
            }
        }
    }

    // 输出最终结果
    cout << pathn[D] << ' ' << max_saver_num[D] << '\n';
    vector<int> st;
    for (int i = D; i != S; i = path[i]) // 考虑到path的特殊性，这里用栈倒过来输出
        st.push_back(i);
    cout << S;
    for (int i = st.size() - 1; i >= 0; i--)
        cout << ' ' << st[i];
}

int main() {
    input();
    dijkstra();
    return 0;
}