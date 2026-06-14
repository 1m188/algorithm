/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 都是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。
*/

/*
 * 解题思路：
 * 6×6 方格有 7×7 个格点。剪开线必须经过中心点 (3,3)（保证两部分对称）。
 * 从中心 (3,3) 出发 DFS 走到边界，每走一步同时标记对称点 (6-x, 6-y)。
 * 若当前点 (x,y) 的对称点已标记，说明剪开线闭合，形成两个相同部分。
 *
 * 但要求两部分形状完全相同，即剪开线必须是中心对称的。
 * DFS 路径本身即为中心对称：每走一步，对称地标记对立点。
 * 走到边界时形成一条完整的分割线。
 *
 * 四种旋转被视为同一种，故答案需除以 4。
 * 已知答案：509。
 */
#include <cstring>
#include <iostream>
using namespace std;

const int N = 6;
bool vis[N + 1][N + 1];
int ans = 0;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    if (x == 0 || x == N || y == 0 || y == N) {
        ans++;
        return;
    }
    vis[x][y] = true;
    vis[N - x][N - y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && !vis[nx][ny])
            dfs(nx, ny);
    }
    vis[x][y] = false;
    vis[N - x][N - y] = false;
}

int main() {
    memset(vis, 0, sizeof(vis));
    dfs(N / 2, N / 2);
    // 旋转对称（4种旋转视为同一种），且从中心出发的4个方向起始相同
    cout << ans / 4 << endl;
    return 0;
}
