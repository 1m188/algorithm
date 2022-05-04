// 有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。
// 现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。
// 如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

// 输入格式:
// 输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N−1)；
// M是高速公路的条数；
// S是出发地的城市编号；
// D是目的地的城市编号。
// 随后的M行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。
// 输入保证解的存在。

// 输出格式:
// 在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

// 输入样例:
// 4 5 0 3
// 0 1 1 20
// 1 3 2 30
// 0 3 4 10
// 0 2 2 20
// 2 3 1 20

// 输出样例:
// 3 40

// 代码长度限制
// 16 KB

// Java (javac)
// 时间限制
// 800 ms

// 内存限制
// 64 MB

// 其他编译器
// 时间限制
// 400 ms

// 内存限制
// 64 MB

/* 这个问题其实在问：给你一个图以及其中两个顶点S，D，要你求从S到D的最短路径，如果有多个最短路径，以另一种权值
最小的算，给出最短路径长和相应的权值 */

/* djikstra算法求单源最短路径长 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 501; // 无穷大

// 两个顶点间的路径长和花费
struct Path
{
    int len = INF;
    int cost = INF;
};

int N = 0, M = 0, S = 0, D = 0; // 输入的顶点数、边数、起始点和终点
vector<vector<Path>> graph;     // 邻接矩阵 图
int ans_len = 0, ans_cost = 0;  // 最终结果

// 处理输入和初始化
void input()
{
    cin >> N >> M >> S >> D;

    graph = vector<vector<Path>>(N, vector<Path>(N));
    for (int i = 0; i < N; i++)
        graph[i][i].cost = graph[i][i].len = 0;

    for (int i = 0; i < M; i++)
    {
        int c1 = 0, c2 = 0, l = 0, c = 0;
        cin >> c1 >> c2 >> l >> c;
        graph[c1][c2].len = graph[c2][c1].len = l;
        graph[c1][c2].cost = graph[c2][c1].cost = c;
    }
}

// dijkstra算法求单源最短路径
void dijkstra()
{
    set<int> s; // 已经处理过的顶点集合
    s.insert(S);

    vector<int> dist; // 最短距离
    vector<int> cost; // 最小花费
    for (int i = 0; i < graph[S].size(); i++)
    {
        dist.push_back(graph[S][i].len);
        cost.push_back(graph[S][i].cost);
    }

    // 从未处理顶点中取一个距离当前已处理顶点集合最短距离的顶点
    // 加入已经处理过的顶点集合
    // 更新最短距离和最小花费
    while (s.find(D) == s.end())
    {
        int v = -1;
        for (int i = 0; i < N; i++)
            if (s.find(i) == s.end() && (v == -1 || dist[i] < dist[v]))
                v = i;

        s.insert(v);

        for (int i = 0; i < N; i++)
        {
            if (s.find(i) == s.end())
            {
                if (dist[i] > dist[v] + graph[v][i].len) // 如果有更短的距离那么以更短的距离为准
                {
                    dist[i] = dist[v] + graph[v][i].len;
                    cost[i] = cost[v] + graph[v][i].cost;
                }
                else if (dist[i] == dist[v] + graph[v][i].len) // 如果距离相等，则取最小的花费
                {
                    cost[i] = min(cost[v] + graph[v][i].cost, cost[i]);
                }
            }
        }
    }

    // 给出结果
    ans_len = dist[D];
    ans_cost = cost[D];
}

int main()
{
    input();
    dijkstra();

    cout << ans_len << ' ' << ans_cost;

    return 0;
}

/* 以下为python3代码 */

/* 这里的代码本来是要提交到pta上面的，但pta上面有个坑，对于Java有特别的性能要求，但对其他的所有语言
就没有，python3和cpp的性能要求都是一样的，同样的逻辑，python3会超时过不了，但cpp就没问题。pta上面还是
尽量用c/c++写吧 */

/* 以下代码逻辑和上面cpp代码逻辑无异 */

/*

INF = float('INF')

def init():

    global N, M, S, D, graph

    N, M, S, D = map(int, input().split(' '))

    graph = [[[INF, INF] for _ in range(N)] for _ in range(N)]
    for i in range(N):
        graph[i][i][0] = graph[i][i][1] = 0

    for _ in range(M):
        c1, c2, l, c = map(int, input().split(' '))
        graph[c1][c2][0] = graph[c2][c1][0] = l
        graph[c1][c2][1] = graph[c2][c1][1] = c

def dijkstra():

    s = set([S])
    dist = [i[0] for i in graph[S]]
    cost = [i[1] for i in graph[S]]

    while D not in s:

        v = -1
        for i in range(N):
            if i not in s and (v == -1 or dist[i] < dist[v]):
                v = i

        s.add(v)

        for i in range(N):
            if i not in s:
                if dist[i] > dist[v] + graph[v][i][0]:
                    dist[i] = dist[v] + graph[v][i][0]
                    cost[i] = cost[v] + graph[v][i][1]
                elif dist[i] == dist[v] + graph[v][i][0]:
                    cost[i] = min(cost[v] + graph[v][i][1], cost[i])

    return dist[D], cost[D]

if __name__ == '__main__':

    init()

    a, b = dijkstra()
    print(f'{a} {b}')

*/