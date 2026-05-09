/*

标题：迷宫与陷阱

小明在玩一款迷宫游戏，在游戏中他要控制自己的角色离开一间由NxN个格子组成的2D迷宫。
小明的起始位置在左上角，他需要到达右下角的格子才能离开迷宫。
每一步，他可以移动到上下左右相邻的格子中（前提是目标格子可以经过）。
迷宫中有些格子小明可以经过，我们用'.'表示；
有些格子是墙壁，小明不能经过，我们用'#'表示。
此外，有些格子上有陷阱，我们用'X'表示。除非小明处于无敌状态，否则不能经过。

有些格子上有无敌道具，我们用'%'表示。
当小明第一次到达该格子时，自动获得无敌状态，无敌状态会持续K步。
之后如果再次到达该格子不会获得无敌状态了。

处于无敌状态时，可以经过有陷阱的格子，但是不会拆除/毁坏陷阱，即陷阱仍会阻止没有无敌状态的角色经过。

给定迷宫，请你计算小明最少经过几步可以离开迷宫


输入
----
第一行包含两个整数N和K。 (1 <= N <= 1000 1 <= K <= 10)
以下N行包含一个NxN的矩阵。
矩阵保证左上角和右下角是'.'。

输出
----
一个整数表示答案。如果小明不能离开迷宫，输出-1。

【样例输入1】
5 3
...XX
##%#.
...#.
.###.
.....

【样例输出1】
10

【样例输入2】
5 1
...XX
##%#.
...#.
.###.
.....

【样例输出2】
12


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

-------------------------
笨笨有话说：
  小明为什么会第2次到达无敌道具的位置呢？ 难道他迷路了吗？




*/

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int MAX_K = 10;

// 方向数组：上、下、左、右
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char grid[MAX_N][MAX_N];           // 迷宫地图
bool used_potion[MAX_N][MAX_N];    // 标记无敌道具是否已被获取（全局，首次到达即消耗）
bool vis[MAX_N][MAX_N][MAX_K + 1]; // vis[x][y][inv] 标记状态是否已访问

struct State {
    int r, c; // 当前位置
    int inv;  // 剩余无敌步数（0 表示不处于无敌状态）
};

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // 初始化访问标记（全局数组默认零初始化，但仍显式清零以确保多次运行正确）
    memset(vis, 0, sizeof(vis));
    memset(used_potion, 0, sizeof(used_potion));

    queue<State> q;
    q.push({0, 0, 0}); // 从左上角出发，初始无无敌状态
    vis[0][0][0] = true;

    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            State cur = q.front();
            q.pop();

            int r = cur.r, c = cur.c, inv = cur.inv;

            // 到达右下角，返回当前步数
            if (r == N - 1 && c == N - 1) {
                cout << steps << endl;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];

                // 越界检查
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

                char cell = grid[nr][nc];

                // 墙壁不可经过
                if (cell == '#') continue;

                // 陷阱：需要有无敌状态才能经过
                if (cell == 'X' && inv == 0) continue;

                // 计算移动后的无敌步数（每移动一步消耗一点无敌）
                int ninv = (inv > 0) ? inv - 1 : 0;

                // 处理无敌道具
                if (cell == '%') {
                    if (!used_potion[nr][nc]) {
                        // 第一次到达该道具格子：获得无敌状态，持续 K 步
                        used_potion[nr][nc] = true;
                        ninv = K; // 获得 K 步无敌（覆盖之前剩余的无敌步数）
                    }
                    // 若已获取过，ninv 保持上面计算的 (inv-1) 不变，当作普通格子
                }

                if (!vis[nr][nc][ninv]) {
                    vis[nr][nc][ninv] = true;
                    q.push({nr, nc, ninv});
                }
            }
        }
        steps++;
    }

    // 无法到达右下角
    cout << -1 << endl;
    return 0;
}
