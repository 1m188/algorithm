/**
 * @date 2022-05-23

    这个文件大概是当初刚刚开始学的时候写的，现在看来还是有诸多问题，
    可能是因为直接抄的书上的伪码，所以有很多警告报错，做了一点修正
    和注释补充，文档内容倒是差不多，但代码实现有诸多不足，勉强参考
    参考即可。以后有机会重新实现一遍这些算法和数据结构。
 */

/*

图——天勤2021数据结构

*/

#include "stdbool.h"
#include "stdio.h"
#include "memory.h"
#include "malloc.h"
#include "limits.h"

#define MAX_SIZE 100
#define INF INT_MAX

/******************************************  图的存储结构  *********************************************************/

// 邻接矩阵

// 邻接矩阵的节点信息结构体
typedef struct
{
    int no;    // 顶点编号
    char info; // 顶点其他信息
} VertexType;

// 邻接矩阵
typedef struct
{
    bool edges[MAX_SIZE][MAX_SIZE]; // 邻接矩阵定义，如果是有权图，将bool换成int或float等与权数相关的类型
    int n, e;                       // 图的顶点数和边数
    VertexType vex[MAX_SIZE];       // 所有顶点信息
} MGraph;

// 邻接表

// 邻接表中的边信息结构体
typedef struct ArcNode
{
    int adjvex;              // 该边所指向的节点位置
    struct ArcNode *nextarc; // 与该边同等级的其他边
    int info;                // 该边的相关信息（如权值）
} ArcNode;

// 邻接表中顶点信息结构体
typedef struct
{
    char data;         // 顶点信息
    int count;         // 统计当前顶点的入度（用于AOV拓扑排序）
    ArcNode *firstarc; // 该顶点所指向的某一条边
} VNode;

// 邻接表
typedef struct
{
    VNode adjlist[MAX_SIZE]; // 邻接表定义
    int n, e;                // 图的顶点数和边数
} AGraph;

/******************************************************************************************************************/

/******************************************  图的遍历算法操作  *********************************************************/

// 根据节点编号访问节点的操作
void Visit(int adjvec)
{
    printf("%d", adjvec);
}

// 深度优先搜索遍历
void DFS(AGraph *g, int v, bool *visit)
{
    // g为邻接表，v为起始节点编号，visit是一个标志节点是否被访问过的数组，初始元素全为false
    // 本算法对连通图中，以一个起点为开始的边进行依次访问，同时在其中经过的每个点又递归的进行上述访问操作

    // 首先访问顶点，并且标记顶点为已经访问
    visit[v] = true;
    Visit(v);

    // 获取当前顶点所指向的第一条边
    ArcNode *p = g->adjlist[v].firstarc;
    while (p)
    {
        // 如果当前边所指向顶点未被访问，则递归访问
        if (!visit[p->adjvex])
            DFS(g, p->adjvex, visit);
        p = p->nextarc; // p指向当前边所指向的下一条边
    }
}

// 广度优先搜索遍历
void BFS(AGraph *g, int v, bool *visit)
{
    // 该算法使用一个队列，类似树的层次遍历，将所有子节点加入队列，并且逐一访问，在一个循环之中重复

    // 访问起始节点
    Visit(v);
    visit[v] = true;

    // 定义队列
    int que[MAX_SIZE], front = 0, rear = 0;
    memset(que, 0, sizeof(int) * MAX_SIZE);

    // 起始节点进队
    rear = (rear + 1) % MAX_SIZE;
    que[rear] = v;

    while (front != rear) // 队列非空时
    {
        // 取队列头部节点，访问该节点对应的第一条边
        front = (front + 1) % MAX_SIZE;
        ArcNode *p = g->adjlist[que[front]].firstarc;

        // 对依次所有未访问过的边进行访问，路径上的节点也一起访问，并且加入队列
        while (p)
        {
            if (!visit[p->adjvex])
            {
                // 访问节点
                Visit(p->adjvex);
                visit[p->adjvex] = true;

                // 入队
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = p->adjvex;
            }
            p = p->nextarc; // p指向该边所指下一条边
        }
    }
}

// 上述算法均针对连通图，对于非连通图，只需要对每个顶点进行访问即可

// 非连通图深度优先搜索遍历
void dfs(AGraph *g)
{
    bool visit[MAX_SIZE];
    memset(visit, 0, sizeof(bool) * MAX_SIZE);
    for (int i = 0; i < g->n; i++)
        if (!visit[i])
            DFS(g, i, visit);
}

// 非连通图广度优先搜索遍历
void bfs(AGraph *g)
{
    bool visit[MAX_SIZE];
    memset(visit, 0, sizeof(bool) * MAX_SIZE);
    for (int i = 0; i < g->n; i++)
        if (!visit[i])
            BFS(g, i, visit);
}

// 设计一个算法，求不带权无向连通图G中距离顶点v最远的一个顶点（所谓最远就是指到达v的路径长度最长）
int BFS2(AGraph *g, int v)
{
    // 用广搜来找到最外层的节点，即最远处的节点，最后遍历的节点必为最远处节点

    // 定义标志数组
    bool visit[MAX_SIZE];
    memset(visit, 0, sizeof(bool) * MAX_SIZE);

    visit[v] = true; // 访问起始节点（但并不需要访问操作，只需要置位其访问过即可）

    // 定义队列，并且起始节点入队
    int que[MAX_SIZE], front = 0, rear = 0;
    rear = (rear + 1) % MAX_SIZE;
    que[rear] = v;

    int x = 0;            // 用来存储最外层节点编号
    while (front != rear) // 队列非空时持续访问
    {
        front = (front + 1) % MAX_SIZE;
        x = que[front];
        ArcNode *p = g->adjlist[x].firstarc;

        // 和层次遍历差不多
        while (p)
        {
            if (!visit[p->adjvex])
            {
                visit[p->adjvex] = true;
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    return x;
}

// 设计一个算法，判断无向图G是否为一棵树，并返回结果
// 一个无向图是一棵树的条件是有n-1条边的连通图，n为节点个数
// 考虑使用dfs判定联通，使用节点和边的信息直接判定边和节点的关系

// dfs判联通，并计算顶点数和边数
void DFS2(AGraph *g, int v, bool *visit, int *vn, int *en)
{
    // vn为顶点计数器，en为边计数器

    visit[v] = true;
    (*vn)++; // 顶点+1

    ArcNode *p = g->adjlist[v].firstarc;
    while (p)
    {
        (*en)++; // 边数+1
        if (!visit[p->adjvex])
            DFS2(g, p->adjvex, visit, vn, en);
        p = p->nextarc;
    }
}

// 判定无向图是否是树
bool GisTree(AGraph *g)
{
    // 定义标志数组和相应的顶点、边计数器，并进行dfs递归遍历
    bool visit[MAX_SIZE];
    memset(visit, 0, sizeof(bool) * MAX_SIZE);
    int vn = 0, en = 0;
    DFS2(g, 0, visit, &vn, &en);

    // 判定顶点数是否和目标图的顶点数相同（判定连通）
    // 判定边数是否为顶点数-1
    // 这里边数/2是因为在dfs遍历的过程中每条边访问了两次
    if (vn == g->n && g->n - 1 == en / 2)
        return true;
    else
        return false;
}

// 图采用邻接表存储，设计一个算法，判别顶点i和顶点j（i!=j）之间是否有路径
bool DFSTrave(AGraph *g, int i, int j)
{
    // 从i开始做深搜，完成后判定j节点是否被访问过

    bool visit[MAX_SIZE];
    memset(visit, 0, sizeof(bool) * MAX_SIZE);
    DFS(g, i, visit);
    return visit[j];
}

/******************************************************************************************************************/

/******************************************  最小（代价）生成树  *********************************************************/

// 普里姆（Prime）算法
void Prime(MGraph *g, int v0, int *sum)
{
    // g为邻接矩阵，v0为开始节点，sum为最小生成树所有权值之和

    // Prime算法  以v0节点为开始
    // 1. 将v0到其他顶点的所有边当作侯选边
    // 2. 重复以下步骤n-1次，使得其他n-1个节点被并入到生成树中
    // (1). 从侯选边中挑出权值最小的边输出，并将与该边另一端的节点并入树中
    // (2). 考查所有剩余节点，如果有节点到刚才并入的节点的权值比最小权值数组里的要小，则更新

    // 这里初始化最低权值数组和标志节点是否入树数组
    int *lowcost = (int *)malloc(sizeof(int) * g->n);
    bool *vest = (bool *)malloc(sizeof(bool) * g->n);
    for (int i = 0; i < g->n; i++)
    {
        lowcost[i] = g->edges[v0][i];
        vest[i] = false;
    }
    vest[v0] = true; // v0节点入树
    *sum = 0;

    // 进行n-1次循环，将所有节点并入树中
    for (int i = 0; i < g->n - 1; i++)
    {
        int min = INF; // INF是一个预先定义的比所有权值都大的常量
        int n = 0;     // 将要并入树中的节点编号

        // 找到和当前树最小权值的那个节点及其相应权值
        for (int j = 0; j < g->n; j++)
        {
            if (!vest[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                n = j;
            }
        }

        vest[n] = true; // 更新新的节点，此时距离其他节点最小权值要么为原来的权值，要么为新节点的权值
        *sum += min;

        // j怎么能和g-n作比较...?g是一个指针，n是一个数
        // 这里到底是什么意思...?大概是伪码...?
        for (int j = 0; j < g - n; j++) // 以刚并入的节点为媒介更新侯选边及其相应权值
            if (!vest[j] && lowcost[j] > g->edges[n][j])
                lowcost[j] = g->edges[n][j];
    }

    free(lowcost);
    free(vest);
}

// 克鲁斯卡尔（Kruskal）算法

// 克鲁斯卡尔算法中边信息结构体
typedef struct
{
    int a, b; // 一条边所连两个边
    int w;    // 边的权值
} Road;

// 在并查集中查找根节点的函数
// a为节点编号，v为并查集数组
int getRoot(int a, int *v)
{
    while (a != v[a])
        a = v[a];
    return a;
}

// 对边按照权值进行升序排序算法
void sort(Road road[]);

// 克鲁斯卡尔算法
// g为邻接矩阵，sum为最终生成树的权值之和，road为图所有边的信息结构体数组，v为并查集数组
void Kruskal(MGraph *g, int *sum, Road road[], int *v)
{
    *sum = 0;
    for (int i = 0; i < g->n; i++)
        v[i] = i; // 让每个节点最开始都指向自己
    sort(road);   // 对road数组中的e条边按权值做升序排序

    for (int i = 0; i < g->e; i++)
    {
        int a = getRoot(road[i].a, v);
        int b = getRoot(road[i].b, v);
        if (a != b) // 这里判定新的边的两边节点是否已经并入树中
        {
            v[a] = b; // 合并两棵树，其中一棵的根节点指向另一棵
            *sum += road[i].w;
        }
    }
}

/******************************************************************************************************************/

/******************************************  最短路径  *********************************************************/

// 迪杰斯特拉（Dijkstra）算法
// 用于寻找无向图中单点到其余各点的最短路径

// 打印预先保存的目标节点的最短路径
// path是之前用作保存到达每个节点的最短路径上的节点前一个节点的数组，a是目标节点
void printfPath(int path[], int a)
{
    // 此算法使用栈来对数组做逆向输出

    // 定义栈
    int stack[MAX_SIZE], top = -1;
    memset(stack, 0, sizeof(int) * MAX_SIZE);

    // 以从叶子节点到根节点的顺序将节点入栈
    while (path[a] != -1)
    {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;

    // 出栈打印元素，从根节点到叶子节点
    while (top != -1)
        printf("%d ", stack[top--]);
    printf("\n");
}

// 迪杰斯特拉（Dijkstra）算法
// g为邻接矩阵，v为所要计算的节点，dist为v到其余各节点的最短路径，path为记录到其余各节点最短路径上倒数第二个节点
void Dijkstra(MGraph *g, int v, int dist[], int path[])
{
    // set数组用来指示哪些节点已被考虑过
    bool *set = (bool *)malloc(sizeof(bool) * g->n);

    // 对最短路径数组、已考虑节点数组、最短路径倒数第二节点数组进行初始化
    for (int i = 0; i < g->n; i++)
    {
        dist[i] = g->edges[v][i];
        set[i] = false;
        // path[i] = g->edges[v][i] < INF ? v : -1; // 有问题
        path[i] = g->edges[v][i] ? v : -1;
    }
    set[v] = true;
    path[v] = -1; // 上述v到v自己的距离为0，但显然v到v最短路径不存在两个节点，故赋为-1

    // 开始循环，对其余n-1个节点做遍历考虑
    for (int i = 0; i < g->n - 1; i++)
    {
        int min = INF;
        int n = 0;
        for (int j = 0; j < g->n; j++) // 找到当前距离v节点最近的那个节点及其距离
            if (!set[j] && dist[j] < min)
            {
                n = j;
                min = dist[j];
            }
        set[n] = true; // 把这个节点的考虑标志位置1

        // 用刚才获得的新的节点来更新v到剩下节点的最近的距离，并且如果有更新的话相应更新其最短路径倒数第二个节点
        for (int j = 0; j < g->n; j++)
            if (!set[j] && dist[j] > dist[n] + g->edges[n][j])
            {
                dist[j] = dist[n] + g->edges[n][j];
                path[j] = n;
            }
    }

    free(set);
}

// 弗洛伊德（Floyd）算法
// 用于求每个节点到其他所有节点的最短路径

// 递归打印从u到v的最短路径上的节点
void printPath(int u, int v, int path[][MAX_SIZE], int A[][MAX_SIZE])
{
    if (A[u][v] == INF) // 如果两点距离无穷大，说明没有路径
        printf("No path\n");
    else
    {
        if (path[u][v] == -1) // 如果为-1，说明有直接路径
            printf("%d-%d ", u, v);
        else // 否则递归先算前半段，后算后半段，这样输出为从头到尾的顺序输出
        {
            int mid = path[u][v];
            printPath(u, mid, path, A);
            printPath(mid, v, path, A);
        }
    }
}

// 弗洛伊德（Floyd）算法
// g为邻接矩阵，path为两点的最短路径经过节点，A为任意两点间的最短距离长度
void Floyd(MGraph *g, int path[][MAX_SIZE], int A[][MAX_SIZE])
{
    // 对最短距离数组和路径节点数组做初始化
    for (int i = 0; i < g->n; i++)
        for (int j = 0; j < g->n; j++)
        {
            A[i][j] = g->edges[i][j];
            path[i][j] = -1;
        }

    // 对每个点都做一个操作：判定任意两点间的距离是否大于以此点做中转站的距离，若是，则此点必为最短路径上点，更新距离以及最短路径经过节点
    for (int k = 0; k < g->n; k++)
        for (int i = 0; i < g->n; i++)
            for (int j = 0; j < g->n; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
}

/******************************************************************************************************************/

/******************************************  拓扑排序  *********************************************************/

// AOV拓扑排序
bool TopSort(AGraph *g)
{
    // 从有向图中选择一个没有前驱（入度为0）的顶点输出
    // 删除上一步中的节点，并且删除从此节点出发的全部边
    // 重复上述两步，直到剩余的图中不存在没有前驱的顶点为止

    // 定义栈
    int *stack = (int *)malloc(sizeof(int) * g->n);
    memset(stack, 0, sizeof(int) * g->n);
    int top = -1;

    int n = 0; // 顶点数目计数

    // 将图中入度为0的顶点入栈
    for (int i = 0; i < g->n; i++)
        if (g->adjlist[i].count == 0)
            stack[++top] = i;

    // 当栈非空的时候，不断出栈并将出栈顶点计数，并将其所有出边删除（即将其所有指向顶点的入度-1）
    while (top == -1)
    {
        int v = stack[top--]; // 顶点出栈
        printf("%d ", v);     // 输出当前顶点
        n++;                  // 统计当前顶点
        ArcNode *p = g->adjlist[v].firstarc;
        while (p) // 此循环实现了将所有由此顶点所引出的边所指向的顶点的入度-1，并将这个过程中入度变为0的顶点入栈
        {
            if (--g->adjlist[p->adjvex].count == 0)
                stack[++top] = p->adjvex;
            p = p->nextarc;
        }
    }

    free(stack);

    return n == g->n;
}

/******************************************************************************************************************/

/******************************************  关键路径  *********************************************************/
/*

针对有向无环图，和拓扑排序一样

AOE网，边表示活动，有权值，节点表示事件，为新活动开始或者旧活动结束的标志

1. 对图做拓扑排序，获得每个节点
2. 求每个事件的最早发生时间和最晚发生时间，最早发生时间为按照顺序拓扑排序到达当前事件节点的最早发生时间加上其到目标事件节点的最大时间，
   最晚发生时间为反过来，按照逆拓扑排序，当前事件节点的最晚发生时间减去指向其的事件节点到目标事件节点的最小时间，
   其中开始节点的最早发生时间为0，结束节点的最早发生时间和最晚发生时间一致。
3. 求出所有发生时间后，最早发生时间和最晚发生时间相同的事件为关键事件，由其所确定的路径为关键路径

*/
/******************************************************************************************************************/

int main(int argc, char *argv[])
{
    return 0;
}