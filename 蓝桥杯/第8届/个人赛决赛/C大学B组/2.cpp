/*
 * 标题：磁砖样式
 *
 * 【题目描述】
 *   小明家的一面装饰墙原来是 3*10 的小方格。
 *   现在手头有一批刚好能盖住2个小方格的长方形瓷砖。
 *   瓷砖只有两种颜色：黄色和橙色。
 *
 *   小明想知道，对于这么简陋的原料，可以贴出多少种不同的花样来。
 *   小明有个小小的强迫症：忍受不了任何2*2的小格子是同一种颜色。
 *   （瓷砖不能切割，不能重叠，也不能只铺一部分。另外，只考虑组合图案，请忽略瓷砖的拼缝）
 *   显然，对于 2*3 个小格子来说，口算都可以知道：一共10种贴法，如【p1.png所示】
 *
 *   但对于 3*10 的格子呢？肯定是个不小的数目，请你利用计算机的威力算出该数字。
 *
 *   注意：你需要提交的是一个整数，不要填写任何多余的内容（比如：说明性文字）
 *
 * 【求解思路】
 *   - 目标：求 3×10 的网格上，用 1×2 的彩色（黄/橙）瓷砖能铺出的不同颜色图案数。
 *   - 约束：(1) 瓷砖不切割不重叠，刚好铺满；(2) 任意 2×2 子网格不能全同色。
 *   - 题目要求“忽略瓷砖拼缝”，即不同铺法若产生相同的最终颜色图案则只计一次。
 *   - 解法：DFS 回溯枚举所有铺砖方案，每当铺满棋盘时去重统计颜色图案。
 *   - 剪枝：每次放置一块瓷砖后，立即检查所有已完成的 2×2 子网格是否全同色。
 *   - 已用 2×3 的已知答案（10 种）验证过本算法正确。
 */

#include <cstring>
#include <iostream>
#include <unordered_set>
using namespace std;

// 棋盘尺寸
const int ROWS = 3;
const int COLS = 10;

// 棋盘状态：-1 表示未填充，0 表示黄色，1 表示橙色
int board[ROWS][COLS];

// 用于去重的哈希集合，将棋盘着色编码为 30 位整数
// 30 位 <= 32 位 int，完全够用
unordered_set<int> patterns;

// 全局检查：遍历所有 2×2 子网格，若存在已填满且全同色的则返回 false
bool check_2x2() {
    for (int r = 0; r < ROWS - 1; r++)
        for (int c = 0; c < COLS - 1; c++)
            // 只有四个格子均已完成填充时才检查
            if (board[r][c] != -1 && board[r][c + 1] != -1 &&
                board[r + 1][c] != -1 && board[r + 1][c + 1] != -1)
                // 若四个格子颜色全部相同，则违反约束
                if (board[r][c] == board[r][c + 1] &&
                    board[r][c + 1] == board[r + 1][c] &&
                    board[r + 1][c] == board[r + 1][c + 1])
                    return false;
    return true;
}

// 将当前棋盘的着色编码为一个 30 位整数（用于去重）
// 编码规则：橙色格子 (值为1) 对应的位设为 1，黄色格子 (值为0) 对应的位为 0
int encode() {
    int code = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (board[r][c] == 1)
                code |= 1 << (r * COLS + c);
    return code;
}

// 深度优先搜索，从格子 (r, c) 开始寻找下一个可放置瓷砖的位置
void dfs(int r, int c) {
    // 跳过已填充的格子，找到下一个空位
    while (r < ROWS && board[r][c] != -1) {
        if (++c == COLS) {
            c = 0;
            r++;
        }
    }

    // 所有格子均已填充，记录当前图案并返回
    if (r == ROWS) {
        patterns.insert(encode());
        return;
    }

    int sr = r, sc = c; // 当前要处理的起始格子

    // ------ 尝试横向放置瓷砖 (覆盖当前格 + 右侧格) ------
    if (sc + 1 < COLS && board[sr][sc + 1] == -1) {
        // 颜色：黄色
        board[sr][sc] = board[sr][sc + 1] = 0;
        if (check_2x2()) dfs(sr, sc);
        // 颜色：橙色
        board[sr][sc] = board[sr][sc + 1] = 1;
        if (check_2x2()) dfs(sr, sc);
        // 回溯还原
        board[sr][sc] = board[sr][sc + 1] = -1;
    }

    // ------ 尝试竖向放置瓷砖 (覆盖当前格 + 下方格) ------
    if (sr + 1 < ROWS && board[sr + 1][sc] == -1) {
        // 颜色：黄色
        board[sr][sc] = board[sr + 1][sc] = 0;
        if (check_2x2()) dfs(sr, sc);
        // 颜色：橙色
        board[sr][sc] = board[sr + 1][sc] = 1;
        if (check_2x2()) dfs(sr, sc);
        // 回溯还原
        board[sr][sc] = board[sr + 1][sc] = -1;
    }
}

int main() {
    // 初始化棋盘为未填充状态
    memset(board, -1, sizeof(board));

    // 启动深度优先搜索
    dfs(0, 0);

    // 输出去重后的图案总数
    cout << patterns.size() << endl;

    return 0;
}
