/*

路径之谜

小明冒充X星球的骑士，进入了一个奇怪的城堡。
城堡里边什么都没有，只有方形石头铺成的地面。

假设城堡地面是 n x n 个方格。【如图1.png】所示。

按习俗，骑士要从西北角走到东南角。
可以横向或纵向移动，但不能斜着走，也不能跳跃。
每走到一个新方格，就要向正北方和正西方各射一箭。
（城堡的西墙和北墙内各有 n 个靶子）


同一个方格只允许经过一次。但不必走完所有的方格。

如果只给出靶子上箭的数目，你能推断出骑士的行走路线吗？

有时是可以的，比如图1.png中的例子。

本题的要求就是已知箭靶数字，求骑士的行走路径（测试数据保证路径唯一）

输入：
第一行一个整数N(0<N<20)，表示地面有 N x N 个方格
第二行N个整数，空格分开，表示北边的箭靶上的数字（自西向东）
第三行N个整数，空格分开，表示西边的箭靶上的数字（自北向南）

输出：
一行若干个整数，表示骑士路径。

为了方便表示，我们约定每个小格子用一个数字代表，从西北角开始编号: 0,1,2,3....
比如，图1.png中的方块编号为：

0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15


示例：
用户输入：
4
2 4 3 4
4 3 3 3

程序应该输出：
0 4 5 1 2 3 7 11 10 9 13 14 15


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

#include <iostream>
#include <vector>
using namespace std;

int n;                        // 网格大小
vector<int> north_target;     // 北靶各列目标箭数
vector<int> west_target;      // 西靶各行目标箭数
vector<int> row_vis;          // 当前各行已访问次数
vector<int> col_vis;          // 当前各列已访问次数
vector<vector<bool>> visited; // 格子访问标记
vector<int> path;             // 当前路径（格子编号）
vector<int> result;           // 最终结果路径

// 四个移动方向：上、下、左、右
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

// 剪枝：检查当前行列计数是否已超出目标
bool prune() {
    for (int r = 0; r < n; r++)
        if (row_vis[r] > west_target[r]) return true;
    for (int c = 0; c < n; c++)
        if (col_vis[c] > north_target[c]) return true;
    return false;
}

// DFS 回溯搜索：从 (r,c) 出发继续寻找路径
void dfs(int r, int c) {
    // 到达终点 (n-1, n-1)，检查行列计数是否与靶数一致
    if (r == n - 1 && c == n - 1) {
        for (int i = 0; i < n; i++) {
            if (row_vis[i] != west_target[i]) return;
            if (col_vis[i] != north_target[i]) return;
        }
        result = path;
        return;
    }

    // 已找到解则不再搜索
    if (!result.empty()) return;

    // 尝试四个方向
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (visited[nr][nc]) continue;

        // 前进：标记并更新计数
        visited[nr][nc] = true;
        row_vis[nr]++;
        col_vis[nc]++;
        path.push_back(nr * n + nc);

        // 剪枝后递归
        if (!prune()) dfs(nr, nc);

        // 回溯
        visited[nr][nc] = false;
        row_vis[nr]--;
        col_vis[nc]--;
        path.pop_back();
    }
}

int main() {
    // 读入数据
    cin >> n;
    north_target.resize(n);
    west_target.resize(n);
    for (int i = 0; i < n; i++)
        cin >> north_target[i];
    for (int i = 0; i < n; i++)
        cin >> west_target[i];

    // 初始化
    row_vis.assign(n, 0);
    col_vis.assign(n, 0);
    visited.assign(n, vector<bool>(n, false));

    // 起点 (0,0)：进入时射箭
    visited[0][0] = true;
    row_vis[0] = 1;
    col_vis[0] = 1;
    path.push_back(0);

    // DFS 搜索唯一路径
    dfs(0, 0);

    // 输出结果
    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
