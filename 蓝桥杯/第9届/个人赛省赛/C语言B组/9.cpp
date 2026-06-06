/*

标题：全球变暖

你有一张某海域NxN像素的照片，"."表示海洋、"#"表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......

其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

【输入格式】
第一行包含一个整数N。  (1 <= N <= 1000)
以下N行N列代表一张海域照片。

照片保证第1行、第1列、第N行、第N列的像素都是海洋。

【输出格式】
一个整数表示答案。

【输入样例】
7
.......
.##....
.##....
....##.
..####.
...###.
.......

【输出样例】
1



资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。


*/

/*
 * 分析：
 *   BFS 遍历每个岛屿（'#' 连通分量）。
 *   一个岛屿不会被完全淹没，当且仅当存在至少一个格子，
 *   其上下左右四个方向全为陆地（'#'）——这样的格子称为"高地"。
 *   统计所有完全淹没的岛屿数量（即没有高地的岛屿）。
 *   时间复杂度 O(N^2)。
 */

#include "iostream"
#include "queue"

const int MAXN = 1000;

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;

// 四个方向
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

// 判断 (x, y) 是否在网格内
bool in_bound(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// BFS 遍历一个岛屿，返回是否会被完全淹没
bool bfs_island(int sx, int sy) {
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    bool has_highland = false; // 是否有高地（四方向全是 #）

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 检查当前格子是否为高地
        bool all_land = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_bound(nx, ny) || grid[nx][ny] == '.') {
                all_land = false;
                break;
            }
        }
        if (all_land)
            has_highland = true;

        // 扩展四个方向
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (in_bound(nx, ny) && grid[nx][ny] == '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // 没有高地 → 完全淹没
    return !has_highland;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> grid[i];
    }

    int submerge_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                if (bfs_island(i, j)) {
                    submerge_count++;
                }
            }
        }
    }

    std::cout << submerge_count << std::endl;

    return 0;
}
