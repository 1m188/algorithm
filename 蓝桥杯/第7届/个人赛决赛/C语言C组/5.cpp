/*

路径之谜

小明冒充X星球的骑士，进入了一个奇怪的城堡。
城堡里边什么都没有，只有方形石头铺成的地面。

假设城堡地面是 n x n 个方格。【如图1.png】所示。

按习俗，骑士要从西北角走到东南角。
可以横向或纵向移动，但不能斜着走，也不能跳跃。
每走到一个新方格，就要向正北方和正西方各射一箭。
（城堡的西墙和北墙内各有 n 个靶子）


同一个方格只允许经过一次。但不必做完所有的方格。

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

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N;                        // 方格边长
int north[20], west[20];      // 北墙（列）和西墙（行）的箭靶数
int row_cnt[20], col_cnt[20]; // 当前已射在各行/列上的箭数
bool visited[20][20];         // 方格访问标记
vector<int> path;             // 当前路径（方格编号）
bool found = false;           // 是否已找到唯一解

// 四个方向：上、右、下、左
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c) {
    if (found)
        return;

    // 到达东南角时检查箭靶数是否全部匹配
    if (r == N - 1 && c == N - 1) {
        for (int i = 0; i < N; ++i)
            if (row_cnt[i] != west[i] || col_cnt[i] != north[i])
                return;
        found = true;
        return;
    }

    // 试探四个方向
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N)
            continue;
        if (visited[nr][nc])
            continue;
        // 剪枝：若增加该格会超出箭靶限制，则跳过
        if (row_cnt[nr] + 1 > west[nr])
            continue;
        if (col_cnt[nc] + 1 > north[nc])
            continue;

        // 前进
        visited[nr][nc] = true;
        row_cnt[nr]++;
        col_cnt[nc]++;
        path.push_back(nr * N + nc);

        dfs(nr, nc);
        if (found)
            return;

        // 回溯
        path.pop_back();
        row_cnt[nr]--;
        col_cnt[nc]--;
        visited[nr][nc] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> north[i];
    for (int i = 0; i < N; ++i)
        cin >> west[i];

    // 从西北角(0,0)出发
    visited[0][0] = true;
    row_cnt[0] = 1;
    col_cnt[0] = 1;
    path.push_back(0);

    dfs(0, 0);

    // 输出路径
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0)
            cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}
