/*

标题：分考场

n个人参加某项特殊考试。
为了公平，要求任何两个认识的人不能分在同一个考场。
求最少需要分几个考场才能满足条件。

输入格式：
第一行，一个整数n(1<n<100)，表示参加考试的人数。
第二行，一个整数m，表示接下来有m行数据
以下m行每行的格式为：两个整数a，b，用空格分开 (1<=a,b<=n)  表示第a个人与第b个人认识（编号从1开始）。

输出格式：
一行一个整数，表示最少分几个考场。

例如：
输入：
5
8
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5

程序应该输出：
4

再比如：
输入：
5
10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

则程序应该输出：
5


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
bool knows[105][105]; // 认识关系邻接矩阵
int color[105];       // 每个人分配的考场编号（0=未分配）
int best;             // 当前最优解
int order[105];       // 按度数降序的顶点处理顺序
int degree[105];      // 各顶点度数

// 贪心着色求上界，用于初始化剪枝
int greedy_coloring() {
    int tmp[105] = {0};
    int max_c = 0;
    for (int i = 1; i <= n; i++) {
        int v = order[i];
        bool used[105] = {false};
        for (int u = 1; u <= n; u++) {
            if (knows[v][u] && tmp[u]) {
                used[tmp[u]] = true;
            }
        }
        int c = 1;
        while (used[c])
            c++;
        tmp[v] = c;
        if (c > max_c) max_c = c;
    }
    return max_c;
}

// idx: 当前处理的是 order 中的第几个顶点
// room_cnt: 当前已使用的考场数
void dfs(int idx, int room_cnt) {
    if (room_cnt >= best) return; // 剪枝：不可能更优
    if (idx > n) {
        best = room_cnt;
        return;
    }

    int v = order[idx];

    // 统计与 v 冲突的考场
    bool conflict[105] = {false};
    for (int u = 1; u <= n; u++) {
        if (knows[v][u] && color[u]) {
            conflict[color[u]] = true;
        }
    }

    // 尝试将 v 放入已有的考场
    for (int r = 1; r <= room_cnt; r++) {
        if (!conflict[r]) {
            color[v] = r;
            dfs(idx + 1, room_cnt);
            color[v] = 0;
        }
    }

    // 尝试将 v 放入新的考场
    color[v] = room_cnt + 1;
    dfs(idx + 1, room_cnt + 1);
    color[v] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        knows[a][b] = knows[b][a] = true;
        degree[a]++;
        degree[b]++;
    }

    // 按度数降序排列顶点，度数高的优先分配
    for (int i = 1; i <= n; i++)
        order[i] = i;
    sort(order + 1, order + n + 1,
         [](int a, int b) { return degree[a] > degree[b]; });

    // 贪心算法给出上界作为初始最优值
    best = greedy_coloring();

    dfs(1, 0);

    cout << best << endl;

    return 0;
}
