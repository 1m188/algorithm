/*

标题：全球变暖


【题目描述】
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

【样例输入】
7
.......
.##....
.##....
....##.
..####.
...###.
.......

【样例输出】
1


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '#' || visited[i][j]) continue;

            // BFS 遍历一整座岛
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            bool has_interior = false;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                // 检查是否为内部点（四方向全是陆地）
                bool interior = true;
                for (int d = 0; d < 4; d++) {
                    if (grid[x + dx[d]][y + dy[d]] == '.') {
                        interior = false;
                        break;
                    }
                }
                if (interior) has_interior = true;

                // 扩展相邻陆地
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (grid[nx][ny] == '#' && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            if (!has_interior) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
