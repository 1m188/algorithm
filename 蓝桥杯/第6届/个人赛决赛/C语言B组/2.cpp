/*

标题：完美正方形

如果一些边长互不相同的正方形，可以恰好拼出一个更大的正方形，则称其为完美正方形。

历史上，人们花了很久才找到了若干完美正方形。比如：如下边长的22个正方形
2 3 4 6 7 8 12 13 14 15 16 17 18 21 22 23 24 26 27 28 50 60
如【图1.png】那样组合，就是一种解法。此时，
紧贴上边沿的是：60 50
紧贴下边沿的是：26 28 17 21 18

22阶完美正方形一共有8种。下面的组合是另一种：
2 5 9 11 16 17 19 21 22 24 26 30 31 33 35 36 41 46 47 50 52 61
如果告诉你该方案紧贴着上边沿的是从左到右依次为：47 46 61，
你能计算出紧贴着下边沿的是哪几个正方形吗？

请提交紧贴着下边沿的正方形的边长，从左到右，用空格分开。

不要填写任何多余的内容或说明文字。

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 154; // 大正方形边长 = 47+46+61 = 154

int squares[22] = {2, 5, 9, 11, 16, 17, 19, 21, 22, 24, 26, 30, 31, 33, 35, 36, 41, 46, 47, 50, 52, 61};
bool used[22];

// grid[i][j] 表示位置(i,j)被哪个正方形占据，-1表示空
int grid[N][N];

// 记录每个正方形的放置位置: (x, y, size)，x是行，y是列
struct Placement {
    int x, y, size;
};
Placement placements[22];
int placementCount = 0;

// 找到最左上角的空位
bool findEmpty(int &x, int &y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == -1) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

// 检查在位置(x,y)放置边长为size的正方形是否可行
bool canPlace(int x, int y, int size) {
    if (x + size > N || y + size > N) return false;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (grid[i][j] != -1) return false;
        }
    }
    return true;
}

// 在位置(x,y)放置边长为size的正方形，标记为id
void place(int x, int y, int size, int id) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            grid[i][j] = id;
        }
    }
    placements[placementCount++] = {x, y, size};
}

// 移除位置(x,y)边长为size的正方形
void remove(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            grid[i][j] = -1;
        }
    }
    placementCount--;
}

// 深度优先搜索填充正方形
bool dfs() {
    int x, y;
    if (!findEmpty(x, y)) {
        // 所有位置都填满了，找到一个解
        return true;
    }

    for (int i = 0; i < 22; i++) {
        if (used[i]) continue;
        int size = squares[i];

        if (canPlace(x, y, size)) {
            used[i] = true;
            place(x, y, size, i);

            if (dfs()) return true;

            remove(x, y, size);
            used[i] = false;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 初始化网格
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = -1;
        }
    }

    // 放置顶部已知的正方形：47, 46, 61
    // 从左到右：47在(0,0)，46在(0,47)，61在(0,93)
    // 47+46+61 = 154 = N

    int idx47 = -1, idx46 = -1, idx61 = -1;
    for (int i = 0; i < 22; i++) {
        if (squares[i] == 47) idx47 = i;
        if (squares[i] == 46) idx46 = i;
        if (squares[i] == 61) idx61 = i;
    }

    used[idx47] = true;
    place(0, 0, 47, idx47);

    used[idx46] = true;
    place(0, 47, 46, idx46);

    used[idx61] = true;
    place(0, 93, 61, idx61);

    if (dfs()) {
        // 收集底部紧贴的正方形（底部即 x + size == N）
        vector<pair<int, int>> bottomSquares; // (列, 边长)

        bool checked[22] = {false};
        for (int j = 0; j < N; j++) {
            int id = grid[N - 1][j];
            if (id != -1 && !checked[id]) {
                checked[id] = true;
                for (int k = 0; k < placementCount; k++) {
                    if (placements[k].size == squares[id]) {
                        if (placements[k].x + placements[k].size == N) {
                            bottomSquares.push_back({placements[k].y, squares[id]});
                        }
                        break;
                    }
                }
            }
        }

        sort(bottomSquares.begin(), bottomSquares.end());

        for (int i = 0; i < bottomSquares.size(); i++) {
            if (i > 0) cout << " ";
            cout << bottomSquares[i].second;
        }
        cout << endl;
    }

    return 0;
}
